#include <fstream>
#include "MiniCppUnit.hxx"
#include "LibFileSystem.hxx"
#include "ConverterGroup.hxx"

class ConverterGroupTests : public TestFixture<ConverterGroupTests>
{
public:
	TEST_FIXTURE( ConverterGroupTests )
	{
		TEST_CASE( testConvert_withHtmlConverter );
		TEST_CASE( testConvert_withoutConverter );
		TEST_CASE( testConvert_withPrintablePdfConverter );
		TEST_CASE( testConvert_withWatermarkPdfConverter );
		TEST_CASE( testConvert_withHtmlAndPdfConverters );
		TEST_CASE( testConvert_withUnknownConverter );
	}
	
	/**
	 * The setUp method is automatically called before each test
	 */
	void setUp()
	{
		LibFileSystem::createNetDirectory( "config" );
		LibFileSystem::createNetDirectory( "generated" );
		LibFileSystem::createNetDirectory( "originals" );
	}
	/**
	 * The tearDown method is automatically called after each test
	 */
	void tearDown()
	{
		LibFileSystem::cleanupDirectory( "config" );
		LibFileSystem::cleanupDirectory( "generated" );
		LibFileSystem::cleanupDirectory( "originals" );
	}
	/**
	 * This method creates files used in tests
	 */
	void createOriginalFile( const std::string & name )
	{
		std::string fullname( "originals/" );
		fullname += name;
		std::ofstream os( fullname.c_str() );
		os << "An original file" << std::endl;
		os.close();
	}
	
	
	void testConvert_withHtmlConverter()
	{
		ConverterGroup converterGroup;
		converterGroup.add( "html" );
		
		createOriginalFile( "Original.odt" );
		converterGroup.convert("originals/Original.odt", "generated/Prefix");
		
		ASSERT_EQUALS(
			"generated/Prefix [multiple HTML files].war\n", 
			LibFileSystem::listDirectoryInOrder( "generated" )
		);
	}

	void testConvert_withoutConverter()
	{
		ConverterGroup converterGroup;
		try
		{			
			createOriginalFile( "Original.odt" );
			converterGroup.add();
			converterGroup.convert("originals/Original.odt", "generated/Prefix");
			FAIL( "An exception should be caught!" );
		}
		catch ( std::exception & e )
		{
			ASSERT_EQUALS(
				"Add a converter to convert a file!",
				e.what()
			)
		}
	
		
	}
	
	void testConvert_withPrintablePdfConverter()
	{	
		ConverterGroup converterGroup;
		converterGroup.add( "pdf_print" );
		
		createOriginalFile( "Original.odt" );
		converterGroup.convert("originals/Original.odt", "generated/Prefix");
	
		ASSERT_EQUALS(
			"generated/Prefix [printable].pdf\n", 
			LibFileSystem::listDirectoryInOrder( "generated" )
		);
	
	}
	
	void testConvert_withWatermarkPdfConverter()
	{
		ConverterGroup converterGroup;
		converterGroup.add( "pdf_mark" );
		
		createOriginalFile( "Original.odt" );
		converterGroup.convert("originals/Original.odt", "generated/Prefix");
	
		ASSERT_EQUALS(
			"generated/Prefix [watermark].pdf\n", 
			LibFileSystem::listDirectoryInOrder( "generated" )
		);

	}
	
	void testConvert_withHtmlAndPdfConverters()
	{
		ConverterGroup converterGroup;
		converterGroup.add( "html" );
		converterGroup.add( "pdf_print" );
		converterGroup.add( "pdf_mark" );

		createOriginalFile( "Original.odt" );
		converterGroup.convert("originals/Original.odt", "generated/Prefix");
	
		ASSERT_EQUALS(
			"generated/Prefix [multiple HTML files].war\n"
			"generated/Prefix [printable].pdf\n"
			"generated/Prefix [watermark].pdf\n", 
			LibFileSystem::listDirectoryInOrder( "generated" )
		);

	}
	
	void testConvert_withUnknownConverter()
	{
		ConverterGroup converterGroup;
		
		try
		{
			converterGroup.add( "doc" );
			converterGroup.convert( "originals/Original.odt", "generated/Prefix" );
			FAIL( "An exception should be caught!" );
		}
		catch ( std::exception & e )
		{
			ASSERT_EQUALS(
				"Unsupported format",
				e.what()
			)
		}
	
		
	}
/**/

};

REGISTER_FIXTURE( ConverterGroupTests )

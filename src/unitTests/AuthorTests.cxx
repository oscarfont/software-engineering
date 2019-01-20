#include "MiniCppUnit.hxx"
#include "Author.hxx"

class AuthorTests : public TestFixture<AuthorTests>
{
public:
	
	TEST_FIXTURE( AuthorTests )
	{
		TEST_CASE( testName_byDefault );
		TEST_CASE( testName_addingName );
		TEST_CASE( testContracted_byDefault );
		TEST_CASE( testContracted_authorContracted );
	}
	
	void testName_byDefault()
	{
		Author author;
		ASSERT_EQUALS( "", author.name() );
	}
	
	void testName_addingName()
	{
		Author author;
		author.name("Maria");
		ASSERT_EQUALS( "Maria", author.name() );
	}
	
	void testContracted_byDefault()
	{
		Author author;
		ASSERT_EQUALS( false, author.isContracted() );
	}
	
	void testContracted_authorContracted()
	{
		Author author;
		author.contract();
		ASSERT_EQUALS( true, author.isContracted() );
	}

};

REGISTER_FIXTURE( AuthorTests )

#include <iostream>
#include <string>
#include <fstream>
#include "MiniCppUnit.hxx"
#include "Channel.hxx"

class ChannelTests : public TestFixture<ChannelTests>
{
public:

	TEST_FIXTURE( ChannelTests )
	{
		TEST_CASE( testChannel_name );
		TEST_CASE( testChannel_description );
		TEST_CASE( testChannel_listChannel );
	}
	
	void testChannel_name(){
		Channel Channel1;
		Channel1.setName("Sports");
		ASSERT_EQUALS("Sports", Channel1.name());
	}

	void testChannel_description(){
		Channel Channel1;
		Channel1.setName("Sports");
		Channel1.setDescription("The channel every sports fan needs");
		ASSERT_EQUALS("The channel every sports fan needs", Channel1.description());
	}

	void testChannel_listChannel(){
		Channel Channel1;
		Channel1.setName("Sports");
		Channel1.setDescription("The channel every sports fan needs");
		ASSERT_EQUALS(
			"Sports\n"
			"\tThe channel every sports fan needs",
			Channel1.listChannel()
		)
	}

};

REGISTER_FIXTURE( ChannelTests )

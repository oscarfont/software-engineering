#include <iostream>
#include <fstream>
#include "MiniCppUnit.hxx"
#include "Topic.hxx"

class TopicTests : public TestFixture<TopicTests>
{
public:

	TEST_FIXTURE( TopicTests )
	{
		TEST_CASE( testTopic_name );
		TEST_CASE( testTopic_notify );
	}
	
	void testTopic_name()
	{
		Topic newTopic;
		newTopic.setName( " Computer Science " );
		
		ASSERT_EQUALS(
			" Computer Science ", 
			newTopic.getName()
		);
	}
	
	void testTopic_notify()
	{
		Topic newTopic;
		Client newClient;
		newClient.setName( "A client" );
		newClient.setEmail( "a@mail.org" );
		newTopic.subscribeClient( newClient );
		newTopic.notify( newClient.getName(), newClient.getEmail(), "A work", "An author" );
		
		ASSERT_EQUALS(
			"To: A client <a@mail.org>\n"
			"Subject: new work A work by An author\n"
			"\n",
			MailStub::theInstance().sentMails()
		);
	}

};

REGISTER_FIXTURE( TopicTests )

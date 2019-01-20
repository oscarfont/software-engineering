#include "MiniCppUnit.hxx"
#include "Client.hxx"

class ClientTests : public TestFixture<ClientTests>
{
public:
	TEST_FIXTURE( ClientTests )
	{
		TEST_CASE( testClient_name );
		TEST_CASE( testClient_email );
		TEST_CASE( testClient_update );
	}


	void testClient_name()
	{
		Client newClient;
		newClient.setName( "Pepe" );
		ASSERT_EQUALS( "Pepe", newClient.getName());
	}
	
	void testClient_email()
	{
		Client newClient;
		newClient.setName( "Pepe" );
		newClient.setEmail( "pepe69@mail.org" );
		ASSERT_EQUALS( "pepe69@mail.org", newClient.getEmail());
	}
	
	void testClient_update()
	{
		Client newClient;
		newClient.setName( "A client" );
		newClient.setEmail( "a@mail.org" );
		ASSERT_EQUALS(
			"new work A work by An author",
			newClient.update(newClient.getName(), newClient.getEmail(), "A work", "An author")
		);
	}
	
};

REGISTER_FIXTURE( ClientTests )

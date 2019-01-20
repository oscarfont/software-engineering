#include "MiniCppUnit.hxx"
#include "Subject.hxx"

class SubjectTests : public TestFixture<SubjectTests>
{
public:
	TEST_FIXTURE( SubjectTests )
	{
		//TEST_CASE( testAttach_oneObserver );
		//TEST_CASE( testAttach_twoObservers );
		//TEST_CASE( testDetach_oneObserver );
	}
/*	
	void testAttach_oneObserver()
	{
		Subject newSubject;
		Observer newObserver;
		newObserver.setId( "Observer1" );
		newSubject.Attach(newObserver);
		ASSERT_EQUALS( "Observer1\n", newSubject.listObservers() );
	}
	
	void testAttach_twoObservers()
	{
		Subject newSubject;
		Observer newObserver1;
		Observer newObserver2;
		newObserver1.setId( "Observer1" );
		newObserver2.setId( "Observer2" );
		newSubject.Attach(newObserver1);
		newSubject.Attach(newObserver2);
		ASSERT_EQUALS(  
			"Observer1\n"
			"Observer2\n", 
			 newSubject.listObservers()
		);
	}
	
	void testDetach_oneObserver()
	{
		Subject newSubject;
		Observer newObserver1;
		Observer newObserver2;
		newObserver1.setId( "Observer1" );
		newObserver2.setId( "Observer2" );
		newSubject.Attach(newObserver1);
		newSubject.Attach(newObserver2);
		newSubject.Detach(newObserver1);
		ASSERT_EQUALS( "Observer2\n", newSubject.listObservers() );
	}
*/
};

REGISTER_FIXTURE( SubjectTests )

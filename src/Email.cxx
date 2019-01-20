#include "Email.hxx"

Email::Email(){}

Email::~Email(){}

void Email::sendNotification(const string & body, const string & cl, const string & cnt){
	string to =  cl + " <" + cnt + ">";
	MailStub::theInstance().sendMail(to, body);
}
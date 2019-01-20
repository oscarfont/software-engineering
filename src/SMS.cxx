#include "SMS.hxx"

SMS::SMS(){}

SMS::~SMS(){}

void SMS::sendNotification(const string & body, const string & cl, const string & cnt){
	SmsStub::theInstance().sendSms(cnt, body);
}
#include "Whatsapp.hxx"

Whatsapp::Whatsapp(){}

Whatsapp::~Whatsapp(){}

void Whatsapp::sendNotification(const string & body, const string & cl, const string & cnt){
	WhatsappStub::theInstance().sendWhatsapp(cnt, body);
}
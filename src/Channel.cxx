#include "Channel.hxx"

Channel::Channel(){}

Channel::~Channel(){}

void Channel::setName(const string & name){
	_name = name; 
}

string Channel::name() const{
	return _name;
}

void Channel::setDescription(const string & des){
	_des = des;
}

string Channel::description() const{
	return _des;
}

string Channel::listChannel(){
	return (name() + "\n\t" + description());
}

void Channel::setHtml(const string & html){
	_html = html;
}

string Channel::html() const{
	return _html;
}

void Channel::generateHtml(){
	string out1 = "<?xml version='1.0' encoding='UTF-8' ?>\n";
	string out2 = "<rss version='2.0'>\n<channel>\n";
	string out3 = "<title>MeltingPotOnline: " + name() + "</title>\n";
	string out4 = "<link>http://www.meltingpotonline.com/" + name() + "</link>\n";
	string out5 = "<description>" + description() + "</description>\n";
	_html = out1 + out2 + out3 + out4 + out5;
}

void Channel::Update(const string &aut, const string &work){
	string out1 = "<item>\n";
	string out2 = "<title>Novelty: '" + work + "' by '" + aut +"'</title>\n";
	string out3 = "<link>http://www.meltingpotonline.com/infoWork?author='" + aut + "'&title='"+ work + "'</link>\n";
	string out4 = "</item>\n";
	_html = _html + out1 + out2 + out3 + out4;
}
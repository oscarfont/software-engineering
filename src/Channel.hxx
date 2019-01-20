#ifndef CHANNEL_H
#define CHANNEL_H

#include <iostream>
#include <string>
#include <vector>
#include "Observer.hxx"

using namespace std;

class Channel : public Observer{
private:

	string _name;
	string _des;
	string _html;

public:

	Channel();
	virtual ~Channel();
	void setName(const string & name);
	string name() const;
	void setDescription(const string & des);
	string description() const;
	string listChannel();
	void setHtml(const string & html);
	string html() const;
	void generateHtml();
	void Update(const string &aut, const string &work);
};

#endif

#include "Exception.hxx"

const char * WorkException::what() const throw ()
{
	return "The work does not exist";
}

const char * AuthorException::what() const throw ()
{
	return "The author does not exist";
}

const char * FileException::what() const throw ()
{
	return "The original file does not exist";
}

const char * NoConverterException::what() const throw ()
{
	return "Add a converter to convert a file!";
}

const char * UnknownConverter::what() const throw ()
{
	return "Unsupported format";
}

const char * InexistentTopic::what() const throw ()
{
	return "The topic does not exist";
}	

const char * InexistentClient::what() const throw ()
{
	return "The client does not exist";
}	

const char * InexistentObserver::what() const throw ()
{
	return "The observer does not exist";
}

const char * InexistentChannel::what() const throw ()
{
	return "The thematic channel does not exist";
}	

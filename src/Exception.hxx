#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <exception>

class WorkException : public std::exception
{
public:
	const char * what() const throw ();
};

class AuthorException : public std::exception
{
public:
	const char * what() const throw ();
};

class FileException : public std::exception
{
public:
	const char * what() const throw ();
};

class NoConverterException : public std::exception
{
public:
	const char * what() const throw ();
};

class UnknownConverter : public std::exception
{
public:
	const char * what() const throw ();
};

class InexistentTopic : public std::exception
{
public:
	const char * what() const throw ();	
};

class InexistentClient : public std::exception
{
public:
	const char * what() const throw ();	
};

class InexistentObserver : public std::exception
{
public:
	const char * what() const throw ();	
};

class InexistentChannel : public std::exception
{
public:
	const char * what() const throw ();
};

#endif

#include <iostream>
#include <exception>

using namespace std;

class myException : public exception 
{
	virtual const char* what() const throw()
	{
		return "Hier den Exceptiontext einfügen";
	}
} myex;
#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <string>
#include <iostream>

using namespace std;

class CustomException
{
private:
	string m_Fehlermeldung;

public:
	CustomException();
	CustomException(string fehlermedlung);
	~CustomException();

	inline string getFehlermeldung() { return m_Fehlermeldung; }
	inline void setFehlermeldung(string fehlermeldung) { m_Fehlermeldung = fehlermeldung; }
};


#endif // !CUSTOMEXCEPTION_H


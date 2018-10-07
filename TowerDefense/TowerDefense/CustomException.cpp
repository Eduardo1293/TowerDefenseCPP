#include "CustomException.h"

CustomException::CustomException(): m_Fehlermeldung("Nicht gefunden!")
{
}

CustomException::CustomException(string fehlermedlung)
{
	if (!fehlermedlung.empty())
	{
		this->setFehlermeldung(fehlermedlung);
	}
}

CustomException::~CustomException()
{
}

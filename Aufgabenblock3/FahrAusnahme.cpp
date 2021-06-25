#include "FahrAusnahme.h"



FahrAusnahme::FahrAusnahme(Fahrzeug* ptrfahrzeug, Weg* ptrweg)
{
	this->p_ptrFahrzeugZeiger = ptrfahrzeug;
	this->p_ptrWegZeiger = ptrweg;
}


FahrAusnahme::~FahrAusnahme()
{
}

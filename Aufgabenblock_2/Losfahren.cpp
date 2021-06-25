#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"


Losfahren::Losfahren(Fahrzeug * fzgPtr, Weg *wegPtr) : FahrAusnahme(fzgPtr, wegPtr)
{
}


Losfahren::~Losfahren()
{
}

void Losfahren::vBearbeiten()
{
	cout << endl << " Ausnahme Losfahren: " 
		<< endl << *p_ptrFahrzeugZeiger
		<< endl << *p_ptrWegZeiger << endl;
	p_ptrWegZeiger->vAbgabe(p_ptrFahrzeugZeiger);
	p_ptrWegZeiger->vAnnahme(p_ptrFahrzeugZeiger);
}
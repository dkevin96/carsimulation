#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "SimuClient.h"

Streckenende::Streckenende(Fahrzeug * fzgPtr, Weg *wegPtr) : FahrAusnahme(fzgPtr, wegPtr)
{
}


Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	cout << endl << " Ausnahme Streckenende: " 
		<< endl << *p_ptrFahrzeugZeiger 
		<< endl << *p_ptrWegZeiger << endl;
	p_ptrWegZeiger->vAbgabe(p_ptrFahrzeugZeiger);
}

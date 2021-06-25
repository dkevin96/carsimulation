#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "SimuClient.h"
#include "Kreuzung.h"
extern double dGlobaleZeit;
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
	Kreuzung* pKreuzung = p_ptrWegZeiger->kGetKreuzung();
	Weg* pNeuerWeg = pKreuzung->ptZufaelligerWeg(p_ptrWegZeiger);
	pKreuzung->vTanken(p_ptrFahrzeugZeiger);
	pNeuerWeg->vAnnahme(p_ptrFahrzeugZeiger);

	cout << "ZEIT     : " << dGlobaleZeit << endl
		<< "KREUZUNG : " << pKreuzung->sGetName() << " " << pKreuzung->dgetTankstelle() << endl
		<< "WECHSEL  : " << p_ptrWegZeiger->sGetName() << " -> " << pNeuerWeg->sGetName() << endl
		<< "FAHRZEUG : " << *p_ptrFahrzeugZeiger << endl;
}

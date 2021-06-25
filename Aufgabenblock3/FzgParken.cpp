#include "FzgParken.h"
#include "Losfahren.h"
#include <math.h>
extern double dGlobaleZeit;



FzgParken::FzgParken(Weg* ptrWeg, double startZeit)
	: FzgVerhalten(ptrWeg)
{
	this->p_dStartzeitpunkt = startZeit;
}

FzgParken::~FzgParken()
{
}

double FzgParken::dStrecke(Fahrzeug *pFahrzeug, double dZeit) 
{
	if ((dGlobaleZeit - p_dStartzeitpunkt) <= -0.0001) //vergleich 2.999 und 3.0
		return 0.0;
	else
	{
		//Wenn Startzeit erreicht, Exception werfen um Fahrzeug zu starten
		throw new Losfahren(pFahrzeug, p_pWeg);//exit(2)
	}
}
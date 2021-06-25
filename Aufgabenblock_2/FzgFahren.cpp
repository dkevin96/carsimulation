#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"



FzgFahren::FzgFahren(Weg *pweg) :
	FzgVerhalten(pweg)
{

}
FzgFahren::~FzgFahren()
{
}

double FzgFahren::dStrecke(Fahrzeug* pFahrzeug, double dZeit)
{
	double dFahrbareStrecke = wGetWeg()->dGetLaenge() - pFahrzeug->dGetAbschnittStrecke();
	if (dFahrbareStrecke <= 0)
	{
		//Exception wird geworfen, wenn Fahrzeug am Wegende angekommen ist.
		throw new Streckenende(pFahrzeug, wGetWeg());
	}

	//ansonsten Berechnung der gefahrenen Strecke im Zeitraum dZeit
	double dStrecke;
	dStrecke = pFahrzeug->dGeschwindigkeit()*dZeit;
	//Wenn dStrecke komplett fahrbar ist,
	if (dFahrbareStrecke - dStrecke >= 0.01)
	{
		return dStrecke;//wird dStrecke zurückgegeben
	}
	else																				 
	{
		return (wGetWeg()->dGetLaenge() - pFahrzeug->dGetAbschnittStrecke());//wird noch zu fahrende Strecke bis Wegende zurückgegeben. 
	}

}
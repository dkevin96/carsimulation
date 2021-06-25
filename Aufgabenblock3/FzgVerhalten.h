#pragma once
class Weg;
class Fahrzeug;
//Basisklasse von FzgFahren und FzgParken
class FzgVerhalten
{
public:
	FzgVerhalten(Weg* pWeg);
	virtual ~FzgVerhalten();
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit) = 0;
	Weg* wGetWeg();
protected:
	Weg*p_pWeg;

};

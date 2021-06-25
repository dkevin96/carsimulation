#pragma once
#include "FzgVerhalten.h"

class Fahrzeug;
class Weg;

class FzgFahren: public FzgVerhalten
{
public:
	FzgFahren(Weg*);
	virtual ~FzgFahren();
	double dStrecke(Fahrzeug* pFahrzeug, double dZeit);
};


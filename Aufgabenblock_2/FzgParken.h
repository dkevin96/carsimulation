#pragma once
#include "FzgVerhalten.h"
class FzgParken :
	public FzgVerhalten
{
public:
	FzgParken(Weg *weg, double dStartzeitpunkt);
	virtual ~FzgParken();
	double dStrecke(Fahrzeug *pFahrzeug, double dZeitraum);
private:
	double p_dStartzeitpunkt;
};


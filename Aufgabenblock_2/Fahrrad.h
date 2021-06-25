#pragma once
#include "Fahrzeug.h"
#include <iomanip>
class Fahrrad :public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string sName);
	Fahrrad(string Name, double p_dMaxGeschwindigkeit);
	virtual ~Fahrrad();
	double dGeschwindigkeit();
	double dTanken(double dMenge=0);
	ostream& ostreamAusgabe(ostream& out);
	virtual void vZeichnen(Weg*);
};


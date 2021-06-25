#pragma once
#include "Fahrzeug.h"
class PKW : public Fahrzeug
{
public:
	PKW();
	PKW(string sName);
	PKW(string sName, double dMaxGeschwindigkeit);
	PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen = 55.0);
	virtual ~PKW();
	double dVerbrauch();
	double dTanken(double dMenge = 0);
	void vAbfertigung();
	void vAusgabe();
	double dGeschwindigkeit();
	ostream& ostreamAusgabe(ostream& out);
	virtual void vZeichnen(Weg* weg);
private:
	double p_dVerbrauch; //Verbrauch/100km
	double p_dTankvolumen;
	double p_dTankinhalt;//in Liter
	double dMenge;
	void vInitialisierung();
};

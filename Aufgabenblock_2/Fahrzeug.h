#pragma once
#include <string>
#include <iostream>
#include "AktivesVO.h"
using namespace std;

class Weg;
class FzgVerhalten;

class Fahrzeug : public AktivesVO
{
public:
	Fahrzeug();
	Fahrzeug(string Name);
	Fahrzeug(string Name, double speed);
	virtual ~Fahrzeug();
	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double Menge = 0);
	virtual double dGeschwindigkeit();
	virtual ostream& ostreamAusgabe(ostream&);
	bool operator<(Fahrzeug&);
	void operator=(Fahrzeug&);
	// Diese Funktion erzeugt eine passende Instanz von FzgFahren für den jeweiligen Weg.
	void vNeueStrecke(Weg* ptrWeg);
	// Diese Funktion erzeugt eine passende Instanz von FzgParken für den jeweiligen Weg.
	void vNeueStrecke(Weg *weg, double dStartzeitpunkt);
	double dGetAbschnittStrecke();
	virtual void vZeichnen(Weg* weg) = 0;
protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dAbschnittStrecke; //zurueckgelegte Strecke auf dem aktuellen Weg
	FzgVerhalten* p_pVerhalten;// Zeiger um das Verhalten des Fahrzeug zu veraendern ohne ein neues Fahrzeug erstellen zu mussen
private:
	void vInitialisierung();
};

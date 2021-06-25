#include "PKW.h"
#include <iomanip>
extern double dGlobaleZeit;
//Standard-Konstruktor
PKW::PKW()
{
	vInitialisierung();
	//cout << "neuer PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << " " << p_dTankvolumen << endl;
}

//Konstruktor mit Initialisierung von p_sName
PKW::PKW(string sName) : Fahrzeug(sName)
{
	vInitialisierung();
	//cout << "neuer PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << " " << p_dTankvolumen << endl;
}

//Konstruktor mit Initialisierung von p_sName und p_dGeschwindigkeit
PKW::PKW(string sName, double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
	vInitialisierung();
	//cout << "neuer PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << " " << p_dTankvolumen << endl;
}

//Konstruktor mit Initialisierung von p_sName, p_dGeschwindigkeit, dVerbrauch und optional von dTankvolumen
PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
	vInitialisierung();
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = dTankvolumen;
	p_dTankinhalt = 3;
	//cout << "neuer PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << " " << p_dTankvolumen << endl;
}

PKW::~PKW()
{
}

// Erhöht p_dTankinhalt um dMenge, bzw tankt voll bei dMengen, die nicht in den Tank passen
double PKW::dVerbrauch()
{
	return (p_dVerbrauch * p_dGesamtStrecke) / 100;
}

double PKW::dTanken(double Menge)
{
	if (Menge == 0 || (Menge + p_dTankinhalt) > p_dTankvolumen)  // kein Parameter wird ubergeben || Es soll mehr als das Volumen getankt
	{
		double a = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return a;
	}
	else
	{
		p_dTankinhalt = p_dTankinhalt + Menge;
		return Menge;
	}
}

void PKW::vInitialisierung()
{
	p_dTankvolumen = 55.0;
	p_dTankinhalt = 3;
	p_dVerbrauch = 0;
}

void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)	//wenn PKW bei Aufruf der Funktion noch fährt (da Treibstoff im Tank), soll
	{
		double dTankinhaltcheck;
		dTankinhaltcheck = p_dTankinhalt - (dGlobaleZeit - p_dZeit)*dGeschwindigkeit()*p_dVerbrauch / 100;
		if (dTankinhaltcheck > 0)				//geprüft werden ob Spritmenge gereicht hat, um letzten Abschnitt zu fahren. Wenn ja, soll
		{
			p_dTankinhalt = dTankinhaltcheck;			//Tankinhalt aktualisiert werden
			Fahrzeug::vAbfertigung();				//Fahrzeug abgefertigt werden
		}
		else									//Wenn nicht, soll
		{
			Fahrzeug::vAbfertigung();				//letzte Abfertigung durchgeführt werden
			p_dTankinhalt = 0.0;					//Tankinhalt geleert werden
		}
	}
	else						//wenn PKW bei Aufruf der Funktion bereits steht:		
	{
		if ((dGlobaleZeit - p_dZeit) >= 1.0)			//Zeitliche Abfertigung für evtl. Berechnung nach erneutem Tanken 
		{
			p_dGesamtZeit += (dGlobaleZeit - p_dZeit);
			p_dZeit = dGlobaleZeit;
		}
	}
}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setiosflags(ios::left) << setprecision(3)
		<< setw(15) << dVerbrauch()
		<< setw(15) << p_dTankinhalt;
}

double PKW::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

ostream& PKW::ostreamAusgabe(ostream& out)
{
	Fahrzeug::ostreamAusgabe(out);
	out << setiosflags(ios::left) << setprecision(2)
		<< setw(18) << dVerbrauch()
		<< setw(15) << p_dTankinhalt;
	return out;
}
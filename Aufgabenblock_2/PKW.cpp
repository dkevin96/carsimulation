#include "PKW.h"
#include <iomanip>
#include "FzgVerhalten.h"
#include "Weg.h"
#include "SimuClient.h"
extern double dGlobaleZeit;
extern double dZeitInkrement;
//Standard-Konstruktor
PKW::PKW():Fahrzeug()
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
	p_dTankinhalt = dTankvolumen / 2;
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

double PKW::dTanken(double dMenge)
{
	double dTankMenge;
	if (dMenge == 0)  //Wenn kein Parameter übergeben wird, soll voll tanken
	{
		dTankMenge = p_dTankvolumen - p_dTankinhalt;		// zu tankende Menge berechnet werden
		p_dTankinhalt = p_dTankvolumen;	// Tankinhalt auf Tankvolumen gesetzt werden (volltanken)
		return dTankMenge;
	}
	else				//Wenn Parameter übergeben wird
	{
		if (dMenge >= (p_dTankvolumen - p_dTankinhalt))		//und zu tankende Menge größer oder gleich dem Platz im Tank ist, soll
		{
			dTankMenge = p_dTankvolumen - p_dTankinhalt;			// zu tankende Menge berechnet werden
			p_dTankinhalt = p_dTankvolumen;						// Tankinhalt auf Tankvolumen gesetzt werden (volltanken)
			return dTankMenge;
		}
		else												//und zu tankende Menge kleiner als der Platz im Tank ist, soll
		{
			p_dTankinhalt += dMenge;							//übergebene Menge getankt werden
			return dMenge;
		}
	}
}

void PKW::vInitialisierung()
{
	p_dTankvolumen = 55.0;
	p_dTankinhalt = 27.5;
	p_dVerbrauch = 0;
}

void PKW::vAbfertigung()
{
	if (p_dTankinhalt != 0)	//wenn PKW bei Aufruf der Funktion noch fährt (da Treibstoff im Tank), soll
	{
		double dTankinhaltcheck;
		dTankinhaltcheck = p_dTankinhalt - p_pVerhalten->dStrecke(this, (dGlobaleZeit - p_dZeit))*p_dVerbrauch / 100;
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
		if ((dGlobaleZeit - p_dZeit) >= dZeitInkrement)			//Zeitliche Abfertigung für evtl. Berechnung nach erneutem Tanken 
		{
			//p_dGesamtZeit += (dGlobaleZeit - p_dZeit);
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
	// Falls das Fahrzeug kein FzgVerhalten hat, kann es auch nicht fahren :
	if (!p_pVerhalten)
	{
		return 0;
	}

	double dGeschwindigkeitsbegrenzung = p_pVerhalten->wGetWeg()->eGetLimit();
	if (dGeschwindigkeitsbegrenzung >= 0 && p_dMaxGeschwindigkeit > dGeschwindigkeitsbegrenzung)
	{
		return dGeschwindigkeitsbegrenzung;
	}
	else
	{
		return p_dMaxGeschwindigkeit;
	}
}

ostream& PKW::ostreamAusgabe(ostream& out)
{
	Fahrzeug::ostreamAusgabe(out);
	out << setiosflags(ios::left) << setprecision(2)
		<< setw(18) << dVerbrauch()
		<< setw(15) << p_dTankinhalt;
	return out;
}

void PKW::vZeichnen(Weg* pweg)
{
	bZeichnePKW(p_sName, pweg->sGetName(), p_dAbschnittStrecke / pweg->dGetLaenge(), dGeschwindigkeit(), p_dTankinhalt);
}
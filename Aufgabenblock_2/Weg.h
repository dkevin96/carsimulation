#pragma once
#include "AktivesVO.h"
#include <list>
#include "Fahrzeug.h"
#include "LazyListe.h"

class Fahrzeug;
enum Begrenzung { Innerorts = 50 , Landstrasse = 100, Autobahn = -1};

class Weg :
	public AktivesVO
{
public:
	
	Weg();
	Weg(string sName, double dLaenge, Begrenzung eLimit = Autobahn);
	virtual ~Weg();
	void vAbfertigung();
	// Diese Funktion nimmt ein fahrendes Fahrzeug in die Liste seiner Fahrzeuge auf.
	void vAnnahme(Fahrzeug* pFahrzeug);
	// Diese Funktion nimmt ein parkendes Fahrzeug in die Liste seiner Fahrzeuge auf.
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeit);
	ostream& ostreamAusgabe(ostream& Stream);
	Begrenzung eGetLimit();
	double dGetLaenge();
	void vAbgabe(Fahrzeug*);// Diese Funktion löscht ein Fahrzeugzeiger aus der Liste der Fahrzeuge.
private:
	Begrenzung p_eLimit; //maximal zulaessige Geschwindigkeit
	double p_dLaenge;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	//list<Fahrzeug*> p_pFahrzeuge;//gom nhung Fahrzeug auf dem Weg
	//Fahrzeugobjekte (anstelle von Zeigern) können nicht in der Liste gespeichert werden,
	//da ansonsten ein AktivesVO (in Form eines Wegs) wiederum AktiveVO (in Form von Fahrzeugen) speichern würde
	
};

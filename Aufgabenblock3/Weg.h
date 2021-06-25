#pragma once
#include "AktivesVO.h"
#include <list>
#include "Fahrzeug.h"
#include "LazyListe.h"
class Kreuzung;
class Fahrzeug;
enum Begrenzung { Innerorts = 50 , Landstrasse = 100, Autobahn = -1};

class Weg :
	public AktivesVO
{
public:
	
	Weg();
	Weg(string sName, double dLaenge, Begrenzung eLimit = Autobahn, bool Verbot = true);
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
	
	void vSetzeSchranke(double dWert);
	double dGetSchranke();
	bool bGetVerbot();
	void vSetzeRueck(Weg* Weg);//Setter fuer den Rueckweg
	Kreuzung* kGetKreuzung();//Getter fuer den Ziel-Kreuzung
	void setZielkreuzung(Kreuzung* pZielkreuzung);//Setter fuer die Zielkreuzung
	Weg* pGetRueckweg();//Getter fuer den Rueckweg
private:
	Begrenzung p_eLimit; //maximal zulaessige Geschwindigkeit
	double p_dLaenge;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	//list<Fahrzeug*> p_pFahrzeuge;//gom nhung Fahrzeug auf dem Weg
	//Fahrzeugobjekte (anstelle von Zeigern) können nicht in der Liste gespeichert werden,
	//da ansonsten ein AktivesVO (in Form eines Wegs) wiederum AktiveVO (in Form von Fahrzeugen) speichern würde
	
	bool p_bUeberholverbot;// Gibt an, ob es auf diesem Weg ein Überholverbot gibt
	double p_dSchranke;// Zeigt auf die Position des aktuell auf diesem Weg abgefertigten Fahrzeugs
	Kreuzung* p_pkKreuzung; //Zeiger auf die Ziel-Kreuzung
	Weg* p_pwRueckWeg;//Zeiger aud den Rueckweg
};

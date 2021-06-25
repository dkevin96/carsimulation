#pragma once
#include <list>
#include "Weg.h"
#include "AktivesVO.h"
class Weg;
class Kreuzung :
	public AktivesVO
{
public:
	Kreuzung();
	Kreuzung(string Name, double Tank = 0.0);
	virtual ~Kreuzung();
	void vVerbinde(string sWegHin, string sWegRueck, double dWegLaenge, Kreuzung* kPoint, Begrenzung Limit, bool bUebVer = true);
	void vTanken(Fahrzeug* Fzg);
	void vAnnahme(Fahrzeug* Fzg, double dStartzeitpunkt);
	void vAbfertigung();
	//// Diese Methode liefert einen Zeiger auf einen zufälligen Weg zurück, der nicht der Rückweg ist.
	Weg* ptZufaelligerWeg(Weg* pWeg);
	// Getter für den Inhalt der Tankstelle.
	double dgetTankstelle();
	virtual istream& istreamEingabe(istream& Stream);
	virtual ostream& ostreamAusgabe(ostream& stream);
private:
	double p_dTankstelle;
	list <Weg*> p_wWege;
};




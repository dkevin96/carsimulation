#include "Weg.h"
#include "FzgFahren.h"
#include "FzgParken.h"
#include "FahrAusnahme.h"

//Standard-Konstruktor
Weg::Weg() :
	AktivesVO()
{
	p_eLimit = Autobahn;
	p_dLaenge = 0;
}

//Konstruktor mit Initialisierung von p_sName, p_dLaenge und optional p_eLimit
Weg::Weg(string sName, double dLaenge, Begrenzung eLimit) : AktivesVO(sName)
{
	this->p_dLaenge = dLaenge;
	this->p_eLimit = eLimit;
}

Weg::~Weg()
{
}

//Alle Fahrzeuge, die sich auf diesem Weg (in der p_pFahrzeuge-Liste) befinden, werden abgefertigt
void Weg::vAbfertigung()
{
	LazyListe<Fahrzeug*>::iterator iter;
	//list<Fahrzeug*>::iterator iter;
	for (iter = p_pFahrzeuge.begin(); iter != p_pFahrzeuge.end(); iter++)
	{
		try
		{
			(*iter)->vAbfertigung();
		}
		catch (FahrAusnahme *pFahrAusnahme)
		{
			pFahrAusnahme->vBearbeiten();
		}
		//Eine Catch-Anweisung reicht zum Abfangen beider Ausnahmen aus, weil beide Ausnahmen (Losfahren, Streckenende)
		//eine gemeinsame Basisklasse haben, und die Funktion vBearbeiten rein virtuell ist.
	}
	p_pFahrzeuge.vAktualisieren();
}

ostream& Weg::ostreamAusgabe(ostream& out)
{
	AktivesVO::ostreamAusgabe(out);
	out << setw(6) << setiosflags(ios::left) << p_dLaenge << "( ";
	LazyListe<Fahrzeug*>::iterator it;
	//list<Fahrzeug*>::iterator it;
	//Ausgabe der Fahrzeuge auf dem Weg (aufgabe 4.6 vAnnahme)
	for (it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		out << setw(9) << setiosflags(ios::left) << (*it)->sGetName();
	}
	out << " )" << endl;
	return out;
}

//zur Annahme eines fahrenden Fahrzeugs
void Weg::vAnnahme(Fahrzeug* fahrzeug)
{
	fahrzeug->vNeueStrecke(this);
	this->p_pFahrzeuge.push_back(fahrzeug);
}

//Überladung der Funktion zur Annahme eines parkenden Fahrzeugs
void Weg::vAnnahme(Fahrzeug *fahrzeug, double dStartzeitpunkt)
{
	fahrzeug->vNeueStrecke(this, dStartzeitpunkt);
	this->p_pFahrzeuge.push_front(fahrzeug);
}

Begrenzung Weg::eGetLimit()
{
	return p_eLimit;
}

double Weg::dGetLaenge()
{
	return p_dLaenge;
}

void Weg::vAbgabe(Fahrzeug* fzg)
{
	LazyListe<Fahrzeug*>::iterator  iter;
	//list<Fahrzeug*>::iterator iter;
	for (iter = p_pFahrzeuge.begin(); iter != p_pFahrzeuge.end(); iter++)
	{
		if (*iter == fzg)
		{
			p_pFahrzeuge.erase(iter);
		}
	}
}
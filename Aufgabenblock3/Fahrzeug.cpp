#include "Fahrzeug.h"
#include <iomanip>
#include "FzgVerhalten.h"
#include "FzgFahren.h"
#include "FzgParken.h"
//int Fahrzeug::p_iMaxID = 0;
extern double dGlobaleZeit;
extern double dZeitInkrement;
//Standard constructor
Fahrzeug::Fahrzeug() :
	AktivesVO()
{
	vInitialisierung();
	//cout << "Fahrzeug wird erzeugt mit Name: " << p_sName << " und ID " << p_iID << endl;
}

//Constructor with parameter name
Fahrzeug::Fahrzeug(string sName):AktivesVO(sName)
{
	vInitialisierung();

	//cout << "Fahrzeug wird erzeugt mit Name: " << p_sName << " und ID " << p_iID << endl;
}

// Constructor with parameter name and speed
Fahrzeug::Fahrzeug(string sName, double speed):AktivesVO(sName)
{
	vInitialisierung();
	this->p_dMaxGeschwindigkeit = speed;
	//cout << "Fahrzeug wird erzeugt mit Name: " << p_sName << " und ID " << p_iID << endl;
}


Fahrzeug::~Fahrzeug()
{
	//cout << "Fahrzeug mit Name: " << p_sName << " und ID " << p_iID << " ist geloescht" << endl;
}


void Fahrzeug::vInitialisierung() //alle Werte mit dem Angfangswert initialisieren
{
	p_dMaxGeschwindigkeit = 0.0;
	p_dGesamtStrecke = 0.0;
	p_dGesamtZeit = 0.0;
	p_dZeit = 0.0;
	p_dAbschnittStrecke = 0;
	//p_iID = p_iMaxID++;
	p_pVerhalten = NULL;
}


void Fahrzeug::vAusgabe()
{
	cout << setiosflags(ios::left)
		<< setw(4) << p_iID
		<< setw(8) << p_sName
		<< setw(5) << ":"
		<< setiosflags(ios::fixed) << setprecision(2)
		<< setw(15) << p_dMaxGeschwindigkeit
		<< setw(15) << p_dGesamtStrecke
		<< setw(15) << dGeschwindigkeit()
		<< setw(13) << p_dAbschnittStrecke;
}


void Fahrzeug::vAbfertigung()
{
	//Abfertigung nur wenn verstrichene Zeit seit letzter Abfertigung mindestens einen Zeitschritt groß ist.

	if (fabs(dGlobaleZeit - p_dZeit - dZeitInkrement) >= 0)
	{
		double dZeitIntervall = dGlobaleZeit - p_dZeit;
		double dStrecke = p_pVerhalten->dStrecke(this, dZeitIntervall); //thay bang dStrecke trong FzgVerhalten
		p_dAbschnittStrecke += dStrecke;
		p_dGesamtStrecke += dStrecke;
		p_dGesamtZeit += (dGlobaleZeit - p_dZeit);
		/*p_dGesamtStrecke += dGeschwindigkeit() * (dGlobaleZeit - p_dZeit);
		p_dAbschnittStrecke += dGeschwindigkeit() * (dGlobaleZeit - p_dZeit);*/
		p_dZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& out)
{
	AktivesVO::ostreamAusgabe(out);
	/*out << setiosflags(ios::left)
		<< setw(4) << p_iID
		<< setw(8) << p_sName*/
	out << setw(5) << ":"
		<< setiosflags(ios::fixed) << setprecision(2)
		<< setw(15) << p_dMaxGeschwindigkeit
		<< setw(15) << p_dGesamtStrecke
		<< setw(15) << dGeschwindigkeit();
	return out;
}


//Gibt true zurück, wenn die eigene Gesamtstrecke kleiner als die Gesamtstrecke des übergebenen Fahrzeugs ist
bool Fahrzeug::operator<(Fahrzeug& f)
{
	if (this->p_dGesamtStrecke < f.p_dGesamtStrecke)
		return true;
	else
		return false;
}

//Zuweisungsoperator, kopiert alle Attribute außer die p_iID
//p_iID wird nicht kopiert, da es sonst zeitgleich zwei Objekt mit der selben ID gibt.
void Fahrzeug::operator=(Fahrzeug& f)
{
	this->p_sName = f.p_sName;
	this->p_dMaxGeschwindigkeit = f.p_dMaxGeschwindigkeit;
	//this->p_iID = f.p_iID;
	this->p_dZeit = f.p_dZeit;
	this->p_dGesamtZeit = f.p_dGesamtZeit;
	this->p_dGesamtStrecke = f.p_dGesamtStrecke;
}

void Fahrzeug::vNeueStrecke(Weg *weg)
{
	if (p_pVerhalten) //if khac NULL thi xoa
	{
		delete p_pVerhalten;// Speicherlocks vermeiden
	}
	p_pVerhalten = new FzgFahren(weg);
	p_dAbschnittStrecke = 0;
}

void Fahrzeug::vNeueStrecke(Weg *weg, double dStartzeitpunkt)
{
	if (p_pVerhalten)
	{
		delete p_pVerhalten;
	}
	p_pVerhalten = new FzgParken(weg, dStartzeitpunkt);
	p_dAbschnittStrecke = 0;
}

double Fahrzeug::dGetAbschnittStrecke()
{
	return p_dAbschnittStrecke;
}

istream& Fahrzeug::istreamEingabe(istream& in)
{
	AktivesVO::istreamEingabe(in);
	in >> p_dMaxGeschwindigkeit;
	return in;
}
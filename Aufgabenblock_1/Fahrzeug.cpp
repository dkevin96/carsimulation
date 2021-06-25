#include "Fahrzeug.h"
#include <iomanip>
int Fahrzeug::p_iMaxID = 0;
extern double dGlobaleZeit;

//Standard constructor
Fahrzeug::Fahrzeug()
{
	vInitialisierung();
	//cout << "Fahrzeug wird erzeugt mit Name: " << p_sName << " und ID " << p_iID << endl;
}

//Constructor with parameter name
Fahrzeug::Fahrzeug(string Name)
{
	vInitialisierung();
	this->p_sName = Name;

	//cout << "Fahrzeug wird erzeugt mit Name: " << p_sName << " und ID " << p_iID << endl;
}

// Constructor with parameter name and speed
Fahrzeug::Fahrzeug(string Name, double speed)
{
	vInitialisierung();
	this->p_sName = Name;
	this->p_dMaxGeschwindigkeit = speed;
	//cout << "Fahrzeug wird erzeugt mit Name: " << p_sName << " und ID " << p_iID << endl;
}


Fahrzeug::~Fahrzeug()
{
	//cout << "Fahrzeug mit Name: " << p_sName << " und ID " << p_iID << " ist geloescht" << endl;
}


void Fahrzeug::vInitialisierung() //alle Werte mit dem Angfangswert initialisieren
{
	p_sName = "";
	p_dMaxGeschwindigkeit = 0.0;
	p_dGesamtStrecke = 0.0;
	p_dGesamtZeit = 0.0;
	p_dZeit = 0.0;
	p_iID = p_iMaxID++;
}

double Fahrzeug::dTanken(double Menge)
{
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
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
		<< setw(15) << dGeschwindigkeit();
}


void Fahrzeug::vAbfertigung()
{
	if (dGlobaleZeit > p_dZeit)
	{
		p_dGesamtZeit = p_dGesamtZeit + dGlobaleZeit - p_dZeit;
		p_dGesamtStrecke += dGeschwindigkeit() * (dGlobaleZeit - p_dZeit);
		p_dZeit = dGlobaleZeit;
	}
}

ostream& Fahrzeug::ostreamAusgabe(ostream& out)
{
	out << setiosflags(ios::left)
		<< setw(4) << p_iID
		<< setw(8) << p_sName
		<< setw(5) << ":"
		<< setiosflags(ios::fixed) << setprecision(2)
		<< setw(15) << p_dMaxGeschwindigkeit
		<< setw(15) << p_dGesamtStrecke
		<< setw(15) << dGeschwindigkeit();
	return out;
}

// Uberladen
ostream& operator << (std::ostream& out, Fahrzeug& fahrzeug)
{
	return fahrzeug.ostreamAusgabe(out);
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
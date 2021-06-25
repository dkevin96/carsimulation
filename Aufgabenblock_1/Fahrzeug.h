#pragma once
#include <string>
#include <iostream>
using namespace std;

class Fahrzeug
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
protected:
	string p_sName;
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	static int p_iMaxID;
private:
	void vInitialisierung();


};

ostream& operator << (ostream& out, Fahrzeug& fahrzeug);

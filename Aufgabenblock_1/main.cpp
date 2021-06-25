#pragma once
#include "Fahrzeug.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "PKW.h"
#include "Fahrrad.h"
#include <vector>

using namespace std;
double  dGlobaleZeit = 0.0;
void vAufgabe_1();
void vAufgabe_1_deb();
void vAufgabe_2();
void vAufgabe_3();

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	vAufgabe_2();
	//vAufgabe_3();
	system("pause");
	return 0;
}

void vAufgabe_1()
{
	//Fahrzeug f1;
	Fahrzeug f2("PKW1", 40);

	string name1;
	cout << "Geben Sie einen Namen ein: " << endl;
	cin >> name1;

	Fahrzeug *f3; 			// dynamisch erstellt
	Fahrzeug *f4 = new Fahrzeug(name1, 30);
	f3 = new Fahrzeug();
	cout << "\n" << setiosflags(ios::left)
		<< setw(4) << "ID"
		<< setw(8) << "Name"
		<< setw(5) << ":"
		<< setw(11) << "MaxKmh"
		<< setw(15) << "GesamtStrecke" << endl;
	cout << setfill('+');
	cout << setw(43) << '+' << endl;
	cout << setfill(' ');

	while (dGlobaleZeit <= 1) //fertigen Fahrzeuge über eine gewisse Zeitspanne
	{
		cout << "dGlobaleZeit: " << dGlobaleZeit << endl;
		//f1.vAbfertigung();
		f2.vAbfertigung();
		f3->vAbfertigung();
		f4->vAbfertigung();

		//f1.vAusgabe(); cout << endl;
		f2.vAusgabe(); cout << endl;
		f3->vAusgabe(); cout << endl;
		f4->vAusgabe(); cout << endl;

		dGlobaleZeit += 0.25;
		cout << "Ende________________________________________" << endl;
	}

	delete f4;
	delete f3;
}

void vAufgabe_1_deb()
{
	Fahrzeug* fFeld[4];
	fFeld[0] = new Fahrzeug("Ferrari", 120.5);
	fFeld[1] = new Fahrzeug("VinFast", 100.140);
	fFeld[2] = new Fahrzeug("Porsche", 130.0);
	fFeld[3] = new Fahrzeug("VW", 80.15);

	for (int i = 0; i < 4; i++)
	{
		fFeld[i]->vAusgabe();
		cout << endl;
	}

	fFeld[2] = 0;// Fehler: pointer zeigt auf NULL
	for (int i = 0; i < 4; i++)
	{
		fFeld[i]->vAusgabe();
		cout << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		delete fFeld[i];
	}
}

void vAufgabe_2()
{
	int inumPKW, inumFahhrad;
	cout << "\nGeben Sie die Anzahl der zu erzeugenden PKWs ein: " << endl;
	cin >> inumPKW;
	cout << "\nGeben Sie die Anzahl der zu erzeugenden Fahhrad ein: " << endl;
	cin >> inumFahhrad;

	vector<Fahrzeug*> FahrzeugPtrList;

	vector<Fahrzeug*>::iterator it;
	int a = 1;
	for (int i = 0; i < inumPKW; i++)
	{
		//Pkw(string Name,double p_dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen)
		FahrzeugPtrList.push_back(new PKW(string("PKW_" + to_string(i + 1)), 40 + i * 5, 5.0, 55.0));
	}
	for (int i = inumPKW; i < inumPKW + inumFahhrad; i++)
	{
		//Fahrrad(string Name, double p_dMaxGeschwindigkeit);
		FahrzeugPtrList.push_back(new Fahrrad(string("Rad_" + to_string(a)), 15));
		a++;
	}
	cout << "\n" << setiosflags(ios::left)
		<< setw(4) << "ID"
		<< setw(8) << "Name"
		<< setw(5) << ":"
		<< setw(11) << "MaxKmh"
		<< setw(15) << "GesamtStrecke"
		<< setw(15) << "akt.Geschw."
		<< setw(18) << "GesamtVerbrauch"
		<< setw(15) << "akt.Tankinhalt"
		<< endl;
	cout << setfill('+');
	cout << setw(91) << '+' << endl;
	cout << setfill(' ');

	while (dGlobaleZeit <= 5) //fertigen Fahrzeuge über eine gewisse Zeitspanne
	{
		cout << "dGlobaleZeit: " << dGlobaleZeit << endl;
		for (it = FahrzeugPtrList.begin(); it < FahrzeugPtrList.end(); it++)
		{
			(*it)->vAbfertigung();
			(*it)->vAusgabe();
			cout << endl;
		}
		if (dGlobaleZeit == 3)
		{
			cout << "Tanken" << endl;
			for (it = FahrzeugPtrList.begin(); it != FahrzeugPtrList.end(); it++)
			{
				(*it)->dTanken();
				(*it)->vAusgabe(); cout << endl;
			}
		}
		cout << "\n" << endl;
		dGlobaleZeit += 1;
	}

	for (it = FahrzeugPtrList.begin(); it != FahrzeugPtrList.end(); it++)
	{
		delete (*it);
	}
}

void vAufgabe_3()
{
	//Objekte erstellen
	PKW p1("pkw1", 100, 10);
	PKW p2("pkw2", 150, 20);
	PKW p3;
	Fahrrad r1("rad1", 50);
	cout << "\n" << setiosflags(ios::left)
		<< setw(4) << "ID"
		<< setw(8) << "Name"
		<< setw(5) << ":"
		<< setw(11) << "MaxKmh"
		<< setw(15) << "GesamtStrecke"
		<< setw(15) << "akt.Geschw."
		<< setw(18) << "GesamtVerbrauch"
		<< setw(15) << "akt.Tankinhalt"
		<< endl;
	cout << setfill('+');
	cout << setw(91) << '+' << endl;
	cout << setfill(' ');
	//<< operator
	cout << "GlobaleZeit: " << dGlobaleZeit << "\n" << p1 << "\n" << p2 << "\n" << r1 << endl;
	dGlobaleZeit = 1;
	p1.vAbfertigung();
	p2.vAbfertigung();
	cout << "GlobaleZeit: " << dGlobaleZeit << "\n" << p1 << "\n" << p2 << "\n" << r1 << endl;
	//Vergleichoperator (base on Gesamtstrecke)
	if (p1 < p2)
	{
		cout << "Die Gesamtstrecke des p2 is groesser als p1" << endl;
	}
	else
		cout << "Die Gesamtstrecke des p1 is groesser als p2" << endl;

	//p1 kopieren in p3
	p3 = p1;
	cout << p3 << endl;

}
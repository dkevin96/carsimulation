#pragma once
#include "Fahrzeug.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "PKW.h"
#include "Fahrrad.h"
#include <vector>
#include "AktivesVO.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "LazyAktion.h"
#include <stdlib.h>

using namespace std;
double  dGlobaleZeit = 0.0;
double dZeitInkrement = 0.3;
void vTable();
//void vAufgabe_1();
//void vAufgabe_1_deb();
//void vAufgabe_2();
//void vAufgabe_3();
void vAufgabe_4();
void vAufgabe_5();
void vAufgabe_5Simu();
void vAufgabe_6();
void vAufgabe_6a();

int main()
{
	//vAufgabe_4();
	//vAufgabe_5();
	//vAufgabe_5Simu();
	vAufgabe_6();
	//vAufgabe_6a();
	system("pause");
	return 0;
}

void vTable()
{
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
}
/*void vAufgabe_1()
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

		dGlobaleZeit += dZeitInkrement;
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

	while (dGlobaleZeit <= 5) //fertigen Fahrzeuge über eine gewisse Zeitspanne
	{
		vTable();
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
		dGlobaleZeit += dZeitInkrement;
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
*/
void vAufgabe_4()
{
	Weg *weg1 = new Weg("Weg 1", 150.0, Landstrasse);
	Fahrzeug *fzg1 = new PKW("BMW", 135.0, 6.9, 66.0);
	Fahrzeug *fzg2 = new Fahrrad("BMX", 25.0);

	weg1->vAnnahme(fzg1);
	weg1->vAnnahme(fzg2);

	while(dGlobaleZeit <= 1.5)
	{	vTable();
		cout << "dGlobalZeit: " << dGlobaleZeit << endl;
		weg1->vAbfertigung();
		cout << *fzg1 << endl << *fzg2 << endl << endl;
		dGlobaleZeit += dZeitInkrement;
	}

	cout << endl << *weg1 << endl << endl;
	cout << endl << *fzg1 << endl << *fzg2 << endl << endl;

}

void vAufgabe_5()
{
	Weg *w1 = new Weg("weg1", 200, Landstrasse);					// Name, Laenge, Begrenzung
	Fahrzeug *fzg1 = new PKW("pkw1", 152, 5, 200);
	Fahrzeug *fzg2 = new Fahrrad("rad", 25.0);
	Fahrzeug *fzg3 = new PKW("pkw2", 131.0, 4.9, 56.0);
	w1->vAnnahme(fzg1);
	w1->vAnnahme(fzg2);	
	w1->vAnnahme(fzg3,3.0);

	while (dGlobaleZeit < 5)
	{
		vTable();
		cout << "GlobaleZeit: " << dGlobaleZeit << endl;
		w1->vAbfertigung();
		cout << *fzg1 << endl;
		cout << *fzg2 << endl;
		cout << *fzg3 << endl;
		dGlobaleZeit += dZeitInkrement;
	}
}

void vAufgabe_5Simu()
{
	Weg* Weg1 = new Weg("Weg1", 500, Innerorts);
	Weg* Weg2= new Weg("Weg2", 500, Innerorts);
	PKW* PKW1 = new PKW("PKW1", 70, 6.00);
	PKW* PKW2= new PKW("PKW2", 70, 6.00);
	Weg1->vAnnahme(PKW1,3);
	Weg2->vAnnahme(PKW2);
	int Array[4] = { 700,250,100,250 };
	bInitialisiereGrafik(800, 500);
	bZeichneStrasse("Weg1", "Weg2", 500, 2, Array);
	
	while (dGlobaleZeit < 10)
	{
		vSetzeZeit(dGlobaleZeit);
		vTable();
		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		Weg1->vAbfertigung();
		Weg2->vAbfertigung();
		PKW1->vZeichnen(Weg1);
		PKW2->vZeichnen(Weg2);
		cout << *PKW1 << endl;
		cout << *PKW2 << endl;
		vSleep(500);
		dGlobaleZeit += dZeitInkrement;
	}
	vBeendeGrafik();
}

void vAufgabe_6()
{
	Weg* Weg1 = new Weg("Weg1", 500, Autobahn);
	Weg* Weg2 = new Weg("Weg2", 500, Autobahn);
	PKW* PKW1 = new PKW("PKW1", 70, 6.00);
	PKW* PKW2 = new PKW("PKW2", 150, 6.00);
	//Fahrrad* F1 = new Fahrrad("F1", 30);
	Weg1->vAnnahme(PKW1, 3);
	Weg2->vAnnahme(PKW2);
	//Weg1->vAnnahme(F1, 1);
	int Array[4] = { 700,250,100,250 };
	bInitialisiereGrafik(800, 500);
	bZeichneStrasse("Weg1", "Weg2", 500, 2, Array);

	while (dGlobaleZeit < 10)
	{
		vSetzeZeit(dGlobaleZeit);
		vTable();
		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		Weg1->vAbfertigung();
		Weg2->vAbfertigung();
		PKW1->vZeichnen(Weg1);
		PKW2->vZeichnen(Weg2);
		//F1->vZeichnen(Weg1);
		cout << *PKW1 << endl;
		cout << *PKW2 << endl;
		//cout << *F1 << endl;
		vSleep(500);
		dGlobaleZeit += dZeitInkrement;
	}
	vBeendeGrafik();
}

void vAufgabe_6a()
{
	LazyListe<int> ZufallsZahlenList;
	LazyListe<int>::iterator it;

	for (int i = 0; i < 10; i++)
	{
		ZufallsZahlenList.push_back(rand() % 11);
	}
	ZufallsZahlenList.vAktualisieren();

	for (it = ZufallsZahlenList.begin(); it != ZufallsZahlenList.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl << endl;

	for (it = ZufallsZahlenList.begin(); it != ZufallsZahlenList.end(); it++)
	{
		if (*it > 5)
		{
			ZufallsZahlenList.erase(it);
		}
	}

	for (it = ZufallsZahlenList.begin(); it != ZufallsZahlenList.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl << endl;

	ZufallsZahlenList.vAktualisieren();

	for (it = ZufallsZahlenList.begin(); it != ZufallsZahlenList.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl << endl;

	ZufallsZahlenList.push_front(rand() % 11);
	ZufallsZahlenList.push_front(rand() % 11);
	ZufallsZahlenList.push_back(rand() % 11);
	ZufallsZahlenList.push_back(rand() % 11);
	ZufallsZahlenList.vAktualisieren();

	for (it = ZufallsZahlenList.begin(); it != ZufallsZahlenList.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl << endl;
}
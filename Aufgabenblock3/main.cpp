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
#include "Kreuzung.h"
#include <fstream>
#include"Welt.h"

using namespace std;
double  dGlobaleZeit = 0.0;
double dZeitInkrement = 0.05;
void vTable();
//void vAufgabe_4();
//void vAufgabe_5();
//void vAufgabe_5Simu();
//void vAufgabe_6();
//void vAufgabe_6a();
void vAufgabe_7();
void vAufgabe_8();
void vAufgabe_9();
void vAufgabe_9simu();
void vAufgabe_9simugrafik();
int main()
{
	//vAufgabe_7();
	//vAufgabe_8();
	//vAufgabe_9();
	//vAufgabe_9simu();
	vAufgabe_9simugrafik();
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



void vAufgabe_7()
{
	Weg* Weg1 = new Weg("Weg1", 400, Innerorts);
	Weg* Weg2 = new Weg("Weg2", 400, Innerorts);
	PKW* PKW1 = new PKW("PKW1", 70, 6,20);
	PKW* PKW2 = new PKW("PKW2", 150, 6);
	Fahrrad* Fahrrad1 = new Fahrrad("Fahrrad", 30);
	Weg1->vAnnahme(PKW1, 2);
	Weg1->vAnnahme(Fahrrad1, 0.5);
	int Array[4] = { 700,250,100,250 };
	bInitialisiereGrafik(800, 500);
	bZeichneStrasse("Weg1", "Weg2", 500, 2, Array);
	while (dGlobaleZeit < 15)
	{
		if (dGlobaleZeit == 6)
		{
			cout << "neues Fahrzeug wird hinzugefuegt" << endl;
			Weg1->vAnnahme(PKW2,7);
		}
		vSetzeZeit(dGlobaleZeit);
		vTable();
		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		Weg1->vAbfertigung();
		//PKW1->vZeichnen(Weg1);
		//PKW2->vZeichnen(Weg1);
		//Fahrrad1->vZeichnen(Weg1);
		cout << *PKW1 << endl;
		cout << *PKW2 << endl;
		cout << *Fahrrad1 << endl;
		cout << *Weg1 << endl;
		vSleep(500);
		
		dGlobaleZeit += dZeitInkrement;
	}
	vBeendeGrafik();
	delete Weg1, Weg2, PKW1, PKW2, Fahrrad1;
}

void vAufgabe_8()
{
	Kreuzung* Kr1 = new Kreuzung("Kr1");
	Kreuzung* Kr2 = new Kreuzung("Kr2", 1000);
	Kreuzung* Kr3 = new Kreuzung("Kr3");
	Kreuzung* Kr4 = new Kreuzung("Kr4");

	Kr1->vVerbinde("W12", "W21", 40, Kr2, Innerorts);
	Kr2->vVerbinde("W23a", "W32a", 115, Kr3, Autobahn, false);
	Kr2->vVerbinde("W23b", "W32b", 40, Kr3, Innerorts);
	Kr2->vVerbinde("W24", "W42", 55, Kr4, Innerorts);
	Kr3->vVerbinde("W34", "W43", 85, Kr4, Autobahn, false);
	Kr4->vVerbinde("W44a", "W44b", 130, Kr4, Landstrasse, false);

	int s1[] = { 680, 40, 680, 300 };
	int s2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	int s3[] = { 680, 300, 680, 570 };
	int s4[] = { 680, 300, 320, 300 };
	int s5[] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	int s6[] = { 320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300 };
	PKW* PKW1 = new PKW("PKW", 100, 10, 100);
	Fahrrad* Fahrrad1 = new Fahrrad("Fahrrad", 30);
	Kr1->vAnnahme(PKW1,1);
	Kr1->vAnnahme(Fahrrad1, 3);

	bInitialisiereGrafik(1100, 700);

	bZeichneStrasse("W12", "W21", 40, 2, s1);
	bZeichneStrasse("W23a", "W32a", 115, 6, s2);
	bZeichneStrasse("W23b", "W32b", 40, 2, s3);
	bZeichneStrasse("W24", "W42", 55, 2, s4);
	bZeichneStrasse("W34", "W43", 85, 5, s5);
	bZeichneStrasse("W44a", "W44b", 130, 7, s6);

	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	cout << *Kr1 << endl << endl
		<< *Kr2 << endl << endl
		<< *Kr3 << endl << endl
		<< *Kr4 << endl << endl;


	while (dGlobaleZeit < 15)
	{
		vSetzeZeit(dGlobaleZeit);
		Kr1->vAbfertigung();
		Kr2->vAbfertigung();
		Kr3->vAbfertigung();
		Kr4->vAbfertigung();
		
		vTable();
		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		cout << *PKW1 << endl;
		cout << *Fahrrad1 << endl;
		vSleep(500);
		dGlobaleZeit += dZeitInkrement;
	}

	vBeendeGrafik();
	delete PKW1, Fahrrad1, Kr1, Kr2, Kr3, Kr4;
}

void vAufgabe_9()
{
	try
	{
		ifstream inputFile("VO.dat");

		if (!inputFile.good())
		{
			throw string("Error: Datei konnte nicht geoeffnet werden!\n");
		}
		PKW car;
		Fahrrad bike;
		Kreuzung x;
		
		inputFile >> car>> bike >> x ;
		vTable();
		cout << car << endl << bike << endl << x << endl <<endl;
		cout << *AktivesVO::ptObjekt("Porsche") << endl;
		cout << *AktivesVO::ptObjekt("Rennrad") << endl;
		cout << *AktivesVO::ptObjekt("abc") << endl;

	}
	catch (string error) { cout << error; }
}

void vAufgabe_9simu()
{
	
	try
	{
		ifstream fin("Simu.dat");
		if (!fin.good())
		{
			throw string("Error: Datei konnte nicht geoeffnet werden!\n");
		}
		Welt neueWelt;
		neueWelt.vEinlesen(fin);
	}
	catch (string s) { cout << s; }
}

void vAufgabe_9simugrafik()
{
	bInitialisiereGrafik(1200, 1000);
	try
	{
		ifstream fin("SimuDisplay.dat");
		if (!fin.good())
		{
			throw string("Error: Datei konnte nicht geoeffnet werden!\n");
		}

		Welt* neueWelt = new Welt();
		neueWelt->vEinlesenMitGrafik(fin);

		while(dGlobaleZeit < 120)
		{
			vSetzeZeit(dGlobaleZeit);
			neueWelt->vSimulation();
			dGlobaleZeit += dZeitInkrement;
		}

	}
	catch (string s) { cout << s; }
	vBeendeGrafik();
}
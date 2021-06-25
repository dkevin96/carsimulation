#include "Welt.h"
#include <string>
#include "Fahrrad.h"
#include "PKW.h"
#include "AktivesVO.h"
#include "Kreuzung.h"
#include "Weg.h"
#include "SimuClient.h"

using namespace std;

Welt::Welt(void)
{
}

Welt::~Welt(void)
{
}

void Welt::vEinlesen(ifstream& in)
{
	while(!in.eof())
	{
		string key;
		in >> key;

		if(key == "KREUZUNG") 
		{
			Kreuzung* pKR = new Kreuzung();
			in >> *pKR;

			p_lKreuzung.push_back(pKR);
		}

		

		else if(key == "PKW") 
		{
			PKW* PKW1 = new PKW();
			string sStartKr;
			double dStartzeit;

			in >> *PKW1 >> sStartKr >> dStartzeit;
			Kreuzung* pKreuz = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sStartKr));
			if (pKreuz != nullptr)
				pKreuz->vAnnahme(PKW1, dStartzeit);
			else
				throw string("Error! Kein Kreuzung Objekt");
		}

		else if(key == "FAHRRAD") 
		{
			Fahrrad* Fahrrad1 = new Fahrrad();
			string sStartKr;

			double dStartzeit;

			in >> *Fahrrad1 >> sStartKr >> dStartzeit;
			Kreuzung* pKreuz = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sStartKr));
			if(pKreuz != nullptr)
				pKreuz->vAnnahme(Fahrrad1, dStartzeit);
			else
				throw string("Error! Kein Kreuzung Objekt");
		}

		else if(key == "STRASSE") 
		{
			string sQuellKr, sZielKr, sNameHin, sNameRueck;
			double dLaenge;
			int iLimit, iUeberholverbot;
			bool bUeberholverbot;
			Begrenzung eLimit;

			in >> sQuellKr >> sZielKr >> sNameHin >> sNameRueck >> dLaenge >> iLimit >> iUeberholverbot;

			switch(iLimit) 
			{
				case 1:
					eLimit = Innerorts;
					break;
				case 2:
					eLimit = Landstrasse;
					break;
				case 3:
					eLimit = Autobahn;
					break;
				default:
					throw string("ERROR : Ungueltige Geschwindigkeitsbegrenzung!");
			}

			switch(iUeberholverbot) 
			{
				case 0:
					bUeberholverbot = false;
					break;
				case 1:
					bUeberholverbot = true;
					break;
				default:
					throw string("ERROR: Ungueltiger Wert fuer ein Ueberholverbot!");
			}

			if(!dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sZielKr)) || !dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sQuellKr)))
			{
				throw string("Error! Kein Kreuzung Objekt!\n");
			}

			dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sQuellKr))->vVerbinde(sNameHin, sNameRueck, dLaenge, dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sZielKr)), eLimit, bUeberholverbot);
		}

		else
		{
			throw string("Error: Falscher Schluessel beim Einlesen: " + key + "\n");
		}
	}

}

void Welt::vEinlesenMitGrafik(ifstream& Stream)
{
	while(!Stream.eof()) 
	{
		string key;
		Stream >> key;

		if(key == "KREUZUNG") 
		{
			Kreuzung* pKR = new Kreuzung();
			double dx, dy;
			Stream >> *pKR >> dx >> dy;
			bZeichneKreuzung(dx,dy);
			p_lKreuzung.push_back(pKR);
		}

		

		else if(key == "PKW") 
		{
			PKW* PKW1 = new PKW();
			string sStartKr;
			double dStartzeit;

			Stream >> *PKW1 >> sStartKr >> dStartzeit;
			Kreuzung* pKreuz = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sStartKr));
			if (pKreuz != nullptr)
				pKreuz->vAnnahme(PKW1, dStartzeit);
			else
				throw string("Error! Kein Kreuzung Objekt");
		}

		else if(key == "FAHRRAD") {
			Fahrrad* Fahrrad1 = new Fahrrad();
			string sStartKr;

			double dStartzeit;

			Stream >> *Fahrrad1 >> sStartKr >> dStartzeit;
			Kreuzung* pKreuz = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sStartKr));
			if (pKreuz != nullptr)
				pKreuz->vAnnahme(Fahrrad1, dStartzeit);
			else
				throw string("Error! Kein Kreuzung Objekt");
		}

		else if(key == "STRASSE") 
		{
			string sQuellKr, sZielKr, sNameHin, sNameRueck;
			double dLaenge;
			int iLimit, iUeberholverbot, iPaare;
			bool bUeberholverbot;
			Begrenzung eLimit;

			Stream >> sQuellKr >> sZielKr >> sNameHin >> sNameRueck >> dLaenge >> iLimit >> iUeberholverbot >> iPaare;
			
			int* Array = new int[iPaare*2];
			for (int i=0;i<(iPaare*2);i++)
			{
				Stream >> Array[i];
			}

			switch(iLimit) 
			{
				case 1:
					eLimit = Innerorts;
					break;
				case 2:
					eLimit = Landstrasse;
					break;
				case 3:
					eLimit = Autobahn;
					break;
				default:
					throw string("ERROR : Ungueltige Geschwindigkeitsbegrenzung!");
			}

			switch(iUeberholverbot) 
			{
				case 0:
					bUeberholverbot = false;
					break;
				case 1:
					bUeberholverbot = true;
					break;
				default:
					throw string("ERROR: Ungueltiger Wert fuer ein Ueberholverbot!");
			}

			if(!dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sZielKr)) || !dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sQuellKr)))
			{
				throw string("Error!Kein Kreuzung Objekt!\n");
			}

			dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sQuellKr))->vVerbinde(sNameHin, sNameRueck, dLaenge, dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sZielKr)), eLimit, bUeberholverbot);
			
			bZeichneStrasse(sNameHin,sNameRueck,dLaenge,iPaare,Array);
		}

		else
		{
			throw string("Error: Falscher Schluessel beim Einlesen: " + key + "\n");
		}
	}

}

void Welt::vSimulation()
{
	for(list<Kreuzung*>::iterator it=p_lKreuzung.begin();it!=p_lKreuzung.end();it++)
	{
		(*it)->vAbfertigung();
	}
}	
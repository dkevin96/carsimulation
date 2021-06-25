#include "Kreuzung.h"



Kreuzung::Kreuzung() : AktivesVO()
{
}

Kreuzung::Kreuzung(string Name, double Tank) : AktivesVO(Name)
{
	p_dTankstelle = Tank;
}


Kreuzung::~Kreuzung()
{
}

void Kreuzung::vVerbinde(string sWegHin, string sWegRueck, double dWegLaenge, Kreuzung* kPoint, Begrenzung Limit, bool bUebVer)
{
	Weg* pWegH = new Weg(sWegHin, dWegLaenge, Limit, bUebVer);
	Weg* pWegR = new Weg(sWegRueck, dWegLaenge, Limit, bUebVer);

	pWegH->vSetzeRueck(pWegR);//set Rueck cua Hin la Rueck
	pWegR->vSetzeRueck(pWegH);//set Rueck cua Rueck la Hin

	pWegH->setZielkreuzung(kPoint); //set Ziel cua Hin
	pWegR->setZielkreuzung(this);//set Ziel cua Rueck la chinh' Kreuzung nay`

	p_wWege.push_back(pWegH);//This Kreuzung add them Hin
	kPoint->p_wWege.push_back(pWegR);//Ziel Kreuzung add them Rueck
}
void Kreuzung::vTanken(Fahrzeug* Fzg)
{
	if (p_dTankstelle > 0)
	{
		p_dTankstelle -= Fzg->dTanken();//volltankt das angegebene Fahrzeug und den Inhalt der Tankstelle reduziert
	}
	else
	{
		p_dTankstelle = 0;
	}
}

void Kreuzung::vAnnahme(Fahrzeug* Fzg, double dStartzeitpunkt)
{
	vTanken(Fzg); //Die Fahrzeuge sollen aufgetankt werden
	Weg* pFirstWeg = p_wWege.front();//pFirstWeg la 1st member cua list p_wWege
	pFirstWeg->vAnnahme(Fzg, dStartzeitpunkt);//nimmt ein parkendes Fahrzeug in die Liste seiner Fahrzeuge auf
}


void Kreuzung::vAbfertigung()
{
	list<Weg*>::iterator itL;
	for (itL = p_wWege.begin(); itL != p_wWege.end(); itL++)
	{
		(*itL)->vAbfertigung();
	}

}

Weg* Kreuzung::ptZufaelligerWeg(Weg* pWeg)
{
	if (p_wWege.size() > 1)
	{
		list<Weg*>::iterator itL;
		do
		{
			itL = p_wWege.begin();
			int rnd = rand() % p_wWege.size();//Zufallszahl zwischen 0 und Listengröße - 1
			for (int i = 0; i < rnd; i++)
				itL++;
		} while (*itL == pWeg->pGetRueckweg());//neu trung Rueckweg thi lap lai

		return *itL;
	}
	else //Sackgasse duong` cung`
		return pWeg->pGetRueckweg();

}

double Kreuzung::dgetTankstelle()
{
	return p_dTankstelle;
}

ostream& Kreuzung::ostreamAusgabe(ostream& oStream)
{
	AktivesVO::ostreamAusgabe(oStream) << resetiosflags(ios_base::adjustfield) << setiosflags(ios_base::left)
		<< p_dTankstelle << " Liter";
	list<Weg*>::iterator it;
	if (!p_wWege.empty())
	{
		oStream << "( ";
		for (it = p_wWege.begin(); it != p_wWege.end(); it++)
		{
			oStream << (*it)->sGetName() << " ";
		}
		oStream << ")";
	}
	oStream << endl;
	return oStream;
}

istream& Kreuzung::istreamEingabe(istream& in)
{
	AktivesVO::istreamEingabe(in);
	in >> p_dTankstelle;
	return in;
}

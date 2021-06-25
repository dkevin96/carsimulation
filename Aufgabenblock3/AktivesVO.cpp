#include "AktivesVO.h"
int AktivesVO::p_iMaxID = 0;
map<string, AktivesVO*> AktivesVO::mapVO;

//Konstruktor ohne Parameter
AktivesVO::AktivesVO()
{
	vInitialisierung();
}

//Konstruktor mit Initialisierung von p_sName
AktivesVO::AktivesVO(string sName)
{
	vInitialisierung();
	p_sName = sName;
	if (mapVO.find(p_sName) == mapVO.end()) //Falls es den Namen in der Liste noch nicht gibt:
	{
		mapVO[p_sName] = this;
	}
	else
	{
		throw string("Error: Objekt " + p_sName + " hat bereits einen Namen");
	}
}


AktivesVO::~AktivesVO()
{
}

void AktivesVO::vInitialisierung()
{
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dZeit = 0.0;
}

ostream& AktivesVO::ostreamAusgabe(ostream& out)
{
	out << setiosflags(ios::left)
		<< setw(4) << p_iID
		<< setw(8) << p_sName;
	return out;
}

ostream& operator<<(ostream& out, AktivesVO& aktivesVO)
{
	aktivesVO.ostreamAusgabe(out);
	return out;
}

string AktivesVO::sGetName()
{
	return p_sName;
}
istream& AktivesVO::istreamEingabe(istream& in)
{
	if (p_sName == "")
	{
		in >> p_sName;
		if (mapVO.find(p_sName) == mapVO.end()) //Falls es den Namen in der Liste noch nicht gibt:
		{
			mapVO[p_sName] = this;
		}
		else
		{
			throw string("Error: Objekt mit diesem Namen existert bereits");
		}
	}
	else
	{
		throw string("Error: Objekt " + p_sName + " hat bereits einen Namen");
	}

	return in;
}

istream& operator>>(istream& in, AktivesVO& AktivesVO)
{
	return AktivesVO.istreamEingabe(in);
}

AktivesVO* AktivesVO::ptObjekt(string sName)
{
	if (mapVO.find(sName) == mapVO.end())
	{
		throw string("Error: Objekt kann nicht gefunden werden: " + sName + "\n");
	}
	else
	{
		return mapVO.find(sName)->second;
	}
}
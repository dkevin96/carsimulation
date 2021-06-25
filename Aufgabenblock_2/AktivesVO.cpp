#include "AktivesVO.h"
int AktivesVO::p_iMaxID = 0;

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
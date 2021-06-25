#pragma once
#include<string>
#include<iomanip>
using namespace std;

class AktivesVO
{
public:
	AktivesVO();
	AktivesVO(string sName);
	virtual ~AktivesVO();
	virtual void vAbfertigung(void) = 0;
	virtual ostream& ostreamAusgabe(ostream& Stream);
	string sGetName();
protected:
	string p_sName; //
	int p_iID;		//Fahrzeug xoa, dung bien o Class nay
	double p_dZeit;	//
private:
	void vInitialisierung();
	static int p_iMaxID; //xoa o Fahrzeug
};

ostream& operator << (ostream& out, AktivesVO& aktivesVO); //ko can o Fahrzeug
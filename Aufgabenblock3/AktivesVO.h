#pragma once
#include<string>
#include<iomanip>
#include<map>
using namespace std;

class AktivesVO
{
public:
	AktivesVO();
	AktivesVO(string sName);
	virtual ~AktivesVO();
	virtual void vAbfertigung(void) = 0;
	virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual istream& istreamEingabe(istream& Stream);
	string sGetName();
	static AktivesVO* ptObjekt(string sName);
	//Diese Funktion liefert den Zeiger auf das Verkehrsobjekt mit dem Namen des Parameters.
protected:
	string p_sName; //
	int p_iID;		//Fahrzeug xoa, dung bien o Class nay
	double p_dZeit;	//
	void vInitialisierung();
private:
	static map<string, AktivesVO*> mapVO;// Diese STL-map enthält Zeiger auf alle Verkehrsobjekte mit Namensindex.
	static int p_iMaxID; //xoa o Fahrzeug
};
istream& operator >> (istream& in, AktivesVO& AktivesVO);
ostream& operator << (ostream& out, AktivesVO& aktivesVO); //ko can o Fahrzeug
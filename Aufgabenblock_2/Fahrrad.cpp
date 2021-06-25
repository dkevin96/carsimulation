#include "Fahrrad.h"
#include "SimuClient.h"
#include "Weg.h"

Fahrrad::Fahrrad()
{
}

Fahrrad::Fahrrad(string sName) : Fahrzeug(sName)
{
	//cout << "neues Fahrrad: " << p_sName << " " << p_iID << endl;
}

Fahrrad::~Fahrrad()
{
}

Fahrrad::Fahrrad(string Name, double p_dMaxGeschwindigkeit) : Fahrzeug(Name, p_dMaxGeschwindigkeit)
{
	//cout << "neues Fahrrad: " << p_sName << " " << p_iID << " " << p_dMaxGeschwindigkeit << " " << endl;
}

double Fahrrad::dTanken(double dMenge)
{
	// ein Fahrrad kann nicht getankt werden
	return 0;
}


double Fahrrad::dGeschwindigkeit()
{
	int a = (int)(p_dGesamtStrecke / 20.0);
	double neueGeschwindigkeit = p_dMaxGeschwindigkeit * pow(0.9, a);
	if (neueGeschwindigkeit < 12.0)
		return 12.0;
	else
		return neueGeschwindigkeit;

}

// Ausgabe der speziellen Fahrrad Informationen
ostream& Fahrrad::ostreamAusgabe(ostream& out)
{
	Fahrzeug::ostreamAusgabe(out);
	out << setiosflags(ios::left) << setprecision(2)
		<< setw(18) << "--"
		<< setw(15) << "--";
	return out;
}

void Fahrrad::vZeichnen(Weg* pweg)
{
	bZeichneFahrrad(p_sName, pweg->sGetName(), p_dAbschnittStrecke / pweg->dGetLaenge(), dGeschwindigkeit());
}
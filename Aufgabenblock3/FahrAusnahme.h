#pragma once
#include<iostream>
class Fahrzeug;
class Weg;

class FahrAusnahme
{
public:
	FahrAusnahme(Fahrzeug*, Weg *);// Erstellt ein Ausnahmeobjekt mit dem Zeiger auf ein Fahrzeug und einen Weg.
	virtual ~FahrAusnahme();
	virtual void vBearbeiten() = 0;
protected:
	Fahrzeug* p_ptrFahrzeugZeiger;// Zeiger auf das Fahrzeug, welches die Ausnahme auslöst.
	Weg* p_ptrWegZeiger;// Zeiger auf den Weg, wo die Ausnahme auftrat.
};


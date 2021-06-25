#pragma once
#include <list>
#include <fstream>
using namespace std;

class Kreuzung;

class Welt
{
public:
	Welt(void);
	virtual ~Welt(void);

	void vEinlesen(ifstream& Stream);
	void vEinlesenMitGrafik(ifstream& Stream);
	void vSimulation();

private:
	list<Kreuzung*> p_lKreuzung;
};


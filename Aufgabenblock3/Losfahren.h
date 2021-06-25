#pragma once
#include <iostream>
#include "FahrAusnahme.h"
class Losfahren :
	public FahrAusnahme
{
public:
	Losfahren(Fahrzeug * fzgPtr, Weg *wegPtr);
	virtual ~Losfahren();
	void vBearbeiten();
};


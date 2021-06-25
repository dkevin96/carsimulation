#pragma once
#include "FahrAusnahme.h"
#include <iostream>
class Streckenende :
	public FahrAusnahme
{
public:
	Streckenende(Fahrzeug * fzgPtr, Weg *wegPtr);
	virtual ~Streckenende();
	void vBearbeiten();
};


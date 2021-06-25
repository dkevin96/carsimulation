#include "FzgVerhalten.h"



FzgVerhalten::FzgVerhalten(Weg * ptrWeg)
{
	p_pWeg = ptrWeg;
}


FzgVerhalten::~FzgVerhalten()
{
}

Weg* FzgVerhalten::wGetWeg()
{
	return p_pWeg;
}
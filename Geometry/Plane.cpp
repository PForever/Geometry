#include "stdafx.h"
#include "Plane.h"

using namespace Geometry3D;

Plane::Plane()
{
	_nY = 1;
	_nZ = 2;
}


Plane::~Plane()
{
}

void Plane::Switch()
{
	_nZ ^= _nY ^= _nZ ^= _nY;
}

int Plane::GetNY() {return _nY;}
int Plane::GetNZ() {return _nZ;}

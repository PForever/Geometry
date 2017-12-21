#include "stdafx.h"
#include "Rolf3D.h"
#include "Rolf.h"
#include "IFigure3D.h"
using namespace Geometry3D;
using namespace Geometry;

void Rolf3D::TurnAll(IFigure3D& fgr, double const aCoal, double const bCoal)
{
	Rolf::TurnAll(fgr, aCoal);
	fgr.Switch();
	Rolf::TurnAll(fgr, bCoal);
	fgr.Switch();
}

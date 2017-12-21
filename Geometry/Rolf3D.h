#pragma once
#include "Geometry.h"

namespace Geometry3D
{
	class IFigure3D;
	class Rolf3D
	{
	public:
		MATHFUNCSDLL_API static void TurnAll(IFigure3D& fgr, double const aCoal, double const bCoal);
	};
}



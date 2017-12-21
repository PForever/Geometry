#pragma once
#include "Geometry.h"

namespace Geometry3D
{
	namespace Geometry
	{
		__interface IPoint;
		__interface IFigure;
		/* Класс поворота фигуры */
		class Rolf
		{
		public:
			MATHFUNCSDLL_API static void TurnAll(IFigure& fgr, double const coal);
			//MATHFUNCSDLL_API static void TurnCopy(IFigure& fgr, double const coal, IPoint * newpoints);
			MATHFUNCSDLL_API static IPoint& TurnOne(IPoint& a, IPoint& c, double const coal);
			//MATHFUNCSDLL_API static double GetLength(IPoint& a, IPoint& b);
		};

	}
}


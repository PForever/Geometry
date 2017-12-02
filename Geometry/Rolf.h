#pragma once
#include "Geometry.h"

namespace Geometry
{
	class Point;
	__interface IFigure;
	/* Класс поворота фигуры */
	class Rolf
	{
	public:
		MATHFUNCSDLL_API static void TurnAll(IFigure& fgr, double const coal);
		MATHFUNCSDLL_API static void TurnCopy(IFigure& fgr, double const coal, Point * newpoints);

		MATHFUNCSDLL_API static Point& TurnOne(Point& a, Point& c, double const coal);
		MATHFUNCSDLL_API static double GetLength(Point& a, Point& b);
	};

}

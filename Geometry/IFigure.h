#pragma once
#include "stdafx.h"
#include "Geometry.h"

namespace Geometry
{
	/* Интерфейс фигур. */
	class Point;
	__interface  IFigure
	{
		/* Точка вращения. */
		MATHFUNCSDLL_API Point& GetCenter();
		/* Число точек у фигуры */
		MATHFUNCSDLL_API size_t GetCount();
		/* вектор точек */
		MATHFUNCSDLL_API std::vector<Point>& GetPoints();
	};
}

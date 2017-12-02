#pragma once
#include "stdafx.h"
#include "Geometry.h"

namespace Geometry
{
	class Point;
	__interface  IFigure
	{
		MATHFUNCSDLL_API Point& GetCenter();
		MATHFUNCSDLL_API size_t GetCount();
		MATHFUNCSDLL_API std::vector<Point>& GetPoints();
	};
}

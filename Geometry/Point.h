#pragma once
#include "Geometry.h"

namespace Geometry
{
	/* Представление точки. */
	MATHFUNCSDLL_API class Point
	{
	public:

		double PointX;
		double PointY;
		MATHFUNCSDLL_API Point(double x, double y);

		Point(const Point& point)
		{
			PointX = point.PointX;
			PointY = point.PointY;
		}

		MATHFUNCSDLL_API ~Point();


		MATHFUNCSDLL_API Point GetCopy();

		MATHFUNCSDLL_API void operator=(Point&);
	};
}

#pragma once
#include "Geometry.h"
#include "IPoint.h"

namespace Geometry3D
{
	namespace Geometry
	{
		/* Представление точки. */
		MATHFUNCSDLL_API class Point : public IPoint
		{
		public:
			double GetX() override { return PointX; };
			double GetY() override { return PointY; };
			void SetX(double x) override { PointX = x; };
			void SetY(double y) override { PointY = y; };

			double PointX;
			double PointY;
			MATHFUNCSDLL_API Point(const double x,const double y);

			Point(const Point& point)
			{
				PointX = point.PointX;
				PointY = point.PointY;
			}

			MATHFUNCSDLL_API ~Point();
			MATHFUNCSDLL_API Point & GetCopy() override;
			MATHFUNCSDLL_API void operator=(Point&);
			MATHFUNCSDLL_API void SetCopy(IPoint &) override;

		};
	}
}


#pragma once
#include "IFigure.h"
namespace Geometry
{
	/* Реализация интефейса. Квадрат. */
	struct MySqr : IFigure
	{
		Point * _center;
		size_t _count;
		std::vector<Point> _points;
	public:

		MATHFUNCSDLL_API MySqr();
		MATHFUNCSDLL_API MySqr(std::vector<Point>& points, Point& center);

		virtual ~MySqr()
		{
		}
		MATHFUNCSDLL_API Point& GetCenter() override;
		MATHFUNCSDLL_API size_t GetCount() override;
		MATHFUNCSDLL_API std::vector<Point>& GetPoints() override;

		//void operator=(const IFigure&);
		MATHFUNCSDLL_API void operator=(const MySqr&);
	};
}

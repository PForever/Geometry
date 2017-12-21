#pragma once
#include "IFigure.h"
namespace Geometry3D
{
	namespace Geometry
	{
		/* Реализация интефейса. Квадрат. */
		struct MySqr : IFigure
		{
			IPoint & _center;
			size_t _count;
			std::vector<IPoint*> _points;
		public:

			MATHFUNCSDLL_API MySqr();
			MATHFUNCSDLL_API MySqr(std::vector<IPoint*>& points, IPoint& center);

			virtual ~MySqr(){}
			MATHFUNCSDLL_API IPoint& GetCenter() override;
			MATHFUNCSDLL_API size_t GetCount() override;
			MATHFUNCSDLL_API std::vector<IPoint*>& GetPoints() override;

			//void operator=(const IFigure&);
			MATHFUNCSDLL_API void operator=(const MySqr&);
		};
	}
}


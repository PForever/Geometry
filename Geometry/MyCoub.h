#pragma once
#include "IFigure3D.h"

namespace Geometry3D
{
	struct MyCoub : IFigure3D
	{
		Geometry::IPoint & _center;
		size_t _count;
		std::vector<Geometry::IPoint*> _points;
	public:
		void Switch() override;
		MATHFUNCSDLL_API MyCoub();
		MATHFUNCSDLL_API ~MyCoub();
		MATHFUNCSDLL_API Geometry::IPoint& GetCenter() override;
		MATHFUNCSDLL_API size_t GetCount() override;
		MATHFUNCSDLL_API std::vector<Geometry::IPoint*>& GetPoints() override;
		MATHFUNCSDLL_API void operator=(const MyCoub&);
	};
}



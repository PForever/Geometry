#pragma once
#include "stdafx.h"
#include "Geometry.h"

namespace Geometry3D
{
	namespace Geometry
	{
		/* Интерфейс фигур. */
		__interface IPoint;
		__interface  IFigure
		{
			/* Точка вращения. */
			MATHFUNCSDLL_API IPoint& GetCenter();
			/* Число точек у фигуры */
			MATHFUNCSDLL_API size_t GetCount();
			/* вектор точек */
			MATHFUNCSDLL_API std::vector<IPoint*>& GetPoints();

		};
	}
}


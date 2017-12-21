#pragma once
#include "Geometry.h"
namespace Geometry3D
{
	namespace Geometry
	{
		MATHFUNCSDLL_API __interface  IPoint
		{
			double GetX();
			double GetY();
			void SetX(double);
			void SetY(double);
			IPoint & GetCopy();
			void SetCopy(IPoint &);
		};
	}
}



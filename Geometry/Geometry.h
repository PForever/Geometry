// Geometry.h

#pragma once

#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport) 
#else
#define MATHFUNCSDLL_API __declspec(dllimport) 
#endif

namespace Geometry3D
{
	namespace Geometry
	{
		const double eps = 0.00000001;
#define M_PI 3.141592653589793238462643383279502884L
#define ENQ(a, b) (abs(a - b) < eps)
	}
}

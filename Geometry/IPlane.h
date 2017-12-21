#pragma once
#include "Geometry.h"
namespace Geometry3D
{
	MATHFUNCSDLL_API __interface IPlane
	{
		void Switch();
		int GetNY();
		int GetNZ();
	};
}
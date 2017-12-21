#pragma once
#include "IPlane.h"

namespace Geometry3D
{
	MATHFUNCSDLL_API class Plane : public IPlane
	{
		int _nY;
		int _nZ;
	public:
		MATHFUNCSDLL_API Plane();
		~Plane();
		void Switch() override;
		int GetNY() override;
		int GetNZ() override;
	};
}



#pragma once
#include "IPoint.h"
#include "IPoint3D.h"
#include "IPlane.h"

namespace Geometry3D
{
	MATHFUNCSDLL_API class Point3D : public IPoint3D
	{
	public:
		MATHFUNCSDLL_API Point3D(const double x,const double y, const double z);
		MATHFUNCSDLL_API Point3D(const double x, const double y, const double z, IPlane * xoy);

		MATHFUNCSDLL_API ~Point3D();
	private:
		double _points[3];
	public:
		void ChangePlane() override;
		void SetPlane(IPlane*) override;

		double GetZ();
		double GetX() override;
		double GetY() override;
		void SetX(double) override;
		void SetY(double) override;
		MATHFUNCSDLL_API IPoint& GetCopy() override;
		MATHFUNCSDLL_API void SetCopy(IPoint&) override;
		MATHFUNCSDLL_API void operator=(Point3D&);

	};
}



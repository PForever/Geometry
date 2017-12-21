#pragma once
#include "Geometry.h"
#include "IPoint.h"

namespace Geometry3D
{
	__interface IPlane;
	class IPoint3D : public Geometry::IPoint
	{
	protected:
		IPlane * _plane;
	public:
		virtual void ChangePlane() = 0;
		virtual void SetPlane(IPlane*) = 0;
		double GetX() override = 0;
		double GetY() override = 0;
		void SetX(double) override = 0;
		void SetY(double) override = 0;
		IPoint& GetCopy() override = 0;
		void SetCopy(IPoint&) override = 0;
	};
}



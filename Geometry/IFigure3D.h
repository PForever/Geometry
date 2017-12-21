#pragma once
#include "IFigure.h"
#include "IPlane.h"

namespace Geometry3D
{
	class IFigure3D : public Geometry::IFigure
	{
	protected:
		IPlane * _plane;
	public:
		virtual void Switch() = 0;
		Geometry::IPoint& GetCenter() override = 0;
		size_t GetCount() override = 0;
		std::vector<Geometry::IPoint*>& GetPoints() override = 0;
	};
}

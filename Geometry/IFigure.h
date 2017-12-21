#pragma once
#include "stdafx.h"
#include "Geometry.h"

namespace Geometry3D
{
	namespace Geometry
	{
		/* ��������� �����. */
		__interface IPoint;
		__interface  IFigure
		{
			/* ����� ��������. */
			MATHFUNCSDLL_API IPoint& GetCenter();
			/* ����� ����� � ������ */
			MATHFUNCSDLL_API size_t GetCount();
			/* ������ ����� */
			MATHFUNCSDLL_API std::vector<IPoint*>& GetPoints();

		};
	}
}


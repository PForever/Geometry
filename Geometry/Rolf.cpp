#include "stdafx.h"
#include "Rolf.h"
#include "IFigure.h"
#include "IPoint.h"
using namespace Geometry3D::Geometry;

/* Поворачивает все точки фигуры */
void Rolf::TurnAll(IFigure& fgr, const double coal)
{
	std::vector<IPoint*>& points = fgr.GetPoints();
	IPoint & center = fgr.GetCenter();

	auto iter = points.begin();
	//IPoint & a = nullptr;
	while (iter != points.end())
	{
		IPoint & a = TurnOne(**iter, center, coal);
		(**iter).SetCopy(a);
		++iter;
	}
}
/* Создаёт повёрнутую копию фигуры */
//TODO не уверен, что работает правильно
//void Rolf::TurnCopy(IFigure& fgr, double const coal, IPoint * newpoints)
//{
//	std::vector<IPoint>& points = fgr.GetPoints();
//	IPoint center = fgr.GetCenter();
//	std::vector<IPoint>::const_iterator iter = points.cbegin();
//	int i = 0;
//	while (iter != points.end())
//	{
//		delete &newpoints[i];
//		newpoints[i++] = TurnOne(const_cast<IPoint&>(*iter++).GetCopy(), center, coal);
//	}
//}
/* Поворачивает точку а вокруг точки c на угол coal */
IPoint& Rolf::TurnOne(IPoint& a, IPoint& c, double const coal)
{
	//const double line = GetLength(a, c);
	//auto e = static_cast<Point3D&>(a);
	//auto u = static_cast<Point3D&>(c);
	const double cosB = cos(coal);
	const double sinB = sin(coal);
	IPoint & res = a.GetCopy();
	res.SetX(c.GetX() + (a.GetX() - c.GetX())*cosB - (a.GetY() - c.GetY())*sinB);
	res.SetY(c.GetY() + (a.GetY() - c.GetY())*cosB + (a.GetX() - c.GetX())*sinB);
	//res->SetCopy(a);
	return res;
}

/* Вычисляет растояние между точками a и b */
//double Rolf::GetLength(IPoint& a, IPoint& b)
//{
//	return sqrt(pow(a.PointX - b.PointX, 2) + pow(a.PointY - b.PointY, 2));
//}

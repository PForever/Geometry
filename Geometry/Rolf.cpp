#include "stdafx.h"
#include "Rolf.h"
#include "Point.h"
#include "IFigure.h"
using namespace Geometry;
/* Поворачивает все точки фигуры */
void Rolf::TurnAll(IFigure& fgr, const double coal)
{
	std::vector<Point>& points = fgr.GetPoints();
	Point center = fgr.GetCenter();
	std::vector<Point>::const_iterator iter = points.begin();
	while (iter != points.end())
	{
		auto a = TurnOne(const_cast<Point&>(*iter), center, coal);
		const_cast<Point&>(*iter) = a;
		++iter;
	}
}
/* Создаёт повёрнутую копию фигуры */
//TODO не уверен, что работает правильно
void Rolf::TurnCopy(IFigure& fgr, double const coal, Point * newpoints)
{
	std::vector<Point>& points = fgr.GetPoints();
	Point center = fgr.GetCenter();
	std::vector<Point>::const_iterator iter = points.cbegin();
	int i = 0;
	while (iter != points.end())
	{
		delete &newpoints[i];
		newpoints[i++] = TurnOne(const_cast<Point&>(*iter++).GetCopy(), center, coal);
	}
}
/* Поворачивает точку а вокруг точки c на угол coal */
Point& Rolf::TurnOne(Point& a, Point& c, double const coal)
{
	//const double line = GetLength(a, c);
	const double cosB = cos(coal);
	const double sinB = sin(coal);
	Point * res = new Point(
		c.PointX + (a.PointX - c.PointX)*cosB - (a.PointY - c.PointY)*sinB,
		c.PointY + (a.PointY - c.PointY)*cosB + (a.PointX - c.PointX)*sinB);

	return *res;
}

/* Вычисляет растояние между точками a и b */
double Rolf::GetLength(Point& a, Point& b)
{
	return sqrt(pow(a.PointX - b.PointX, 2) + pow(a.PointY - b.PointY, 2));
}

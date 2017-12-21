#include "stdafx.h"
#include "Point.h"
using namespace Geometry3D::Geometry;


Point::Point(const double x, const double y)
{
	PointX = x;
	PointY = y;
}

Point::~Point()
{
}

Point & Point::GetCopy()
{
	Point * a = new Point(PointX, PointY);
	return *a;
}

void Point::operator=(Point& a)
{
	//if(PointY)delete &PointX;
	//if(PointY)delete &PointY;
	PointX = a.PointX;
	PointY = a.PointY;
}

void Point::SetCopy(IPoint& a)
{
	PointX = a.GetX();
	PointY = a.GetY();
}

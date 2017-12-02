#include "stdafx.h"
#include "Point.h"
using namespace Geometry;

Point::Point(double x, double y)
{
	PointX = x;
	PointY = y;
}

Point::~Point()
{
}

Point Point::GetCopy()
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

#include "stdafx.h"
#include "MySqr.h"
#include "Point.h"
//#include "MySqr.h"
//#include "Point.h"
using namespace Geometry;

MySqr::MySqr() : _points{ { { 34, 14 },{ 34, 22 },{ 42, 22 },{ 42, 14 } } }
//MySqr::MySqr()
{
	
	_count = _points.capacity();
	//for (int i = 0; i < 100; ++i)
	//{
	//	_points.push_back({static_cast<double>(15*i /100 * sin(i*M_PI / 12) + 20),static_cast<double>(15*i/100*cos(i*M_PI / 12) +20)});
	//}
	_center = new Point{ 38, 18 };
}


MySqr::MySqr(std::vector<Point>& points, Point& center) : _center(&center), _count(points.capacity()), _points(points)
{
}

Point& MySqr::GetCenter()
{
	return *_center;
}
size_t MySqr::GetCount()
{
	return _count;
}


std::vector<Point>& MySqr::GetPoints()
{
	return _points;
}

//void MySqr::operator=(const IFigure& f)
void MySqr::operator=(const MySqr& f)
{
	auto iter =_points.begin();
	//for (Point point : _points)
	//{
	//	if(&point)delete & point;
	//}
	//if(_center)delete _center;

	for (Point point : f._points)
	{
		*iter++ = point;
		if (iter == _points.end()) break;
	}
	*_center = *f._center;
}


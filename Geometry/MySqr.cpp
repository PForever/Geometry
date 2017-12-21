#include "stdafx.h"
#include "MySqr.h"
#include "Point.h"
//#include "MySqr.h"
//#include "Point.h"
using namespace Geometry3D::Geometry;

MySqr::MySqr() : _points(std::vector<IPoint*>()), _center(*new Point{ 38, 18 })
//MySqr::MySqr()
{
	_points.push_back(new Point{ 34, 14 });
	_points.push_back(new Point{ 34, 22 });
	_points.push_back(new Point{ 42, 22 });
	_points.push_back(new Point{ 42, 14 });
	_count = _points.size();
	//for (int i = 0; i < 100; ++i)
	//{
	//	_points.push_back({static_cast<double>(15*i /100 * sin(i*M_PI / 12) + 20),static_cast<double>(15*i/100*cos(i*M_PI / 12) +20)});
	//}
	;
}


MySqr::MySqr(std::vector<IPoint*>& points, IPoint& center) 
: _center(center), _count(points.size()), _points(points) {}

IPoint& MySqr::GetCenter() {return _center;}
size_t MySqr::GetCount() {return _count;}
std::vector<IPoint*>& MySqr::GetPoints() {return _points;}

//void MySqr::operator=(const IFigure& f)
void MySqr::operator=(const MySqr& f)
{
	auto iter =_points.begin();
	//for (Point point : _points)
	//{
	//	if(&point)delete & point;
	//}
	//if(_center)delete _center;
	const size_t size = f._points.size();
	for (int i = 0; i < size; ++i)
	{
		(*iter) = &(f._points[i])->GetCopy();
		++iter;
		if (iter == _points.end()) break;
	}
	//for (Point point : f._points)
	//{

	//}
	_count = f._count;
	_center.SetCopy(f._center);
}


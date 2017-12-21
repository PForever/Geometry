#include "stdafx.h"
#include "MyCoub.h"
#include "Point3D.h"
#include "Plane.h"
#include "Point.h"

using namespace Geometry3D;
using namespace Geometry;

void MyCoub::Switch() {_plane->Switch();}

MyCoub::MyCoub() : _points(std::vector<IPoint*>()), _center(*new Point3D{ 38, 18, 18 })
{
	_plane = new Plane();
	_points.push_back(new Point3D{ 34, 14, 14, _plane });
	_points.push_back(new Point3D{ 34, 22, 14, _plane });
	_points.push_back(new Point3D{ 42, 22, 14, _plane });
	_points.push_back(new Point3D{ 42, 14, 14, _plane });

	_points.push_back(new Point3D{ 34, 14, 22, _plane });
	_points.push_back(new Point3D{ 34, 22, 22, _plane });
	_points.push_back(new Point3D{ 42, 22, 22, _plane });
	_points.push_back(new Point3D{ 42, 14, 22, _plane });

	static_cast<IPoint3D&>(_center).SetPlane(_plane);
	_count = _points.size();
}


MyCoub::~MyCoub()
{
}

IPoint& MyCoub::GetCenter() {return _center;}
size_t MyCoub::GetCount() {return _count;}
std::vector<IPoint*>& MyCoub::GetPoints() {return _points;}

void MyCoub::operator=(const MyCoub& f)
{
	auto iter = _points.begin();
	const size_t size = f._points.size();
	for (int i = 0; i < size; ++i)
	{
		(*iter) = &(f._points[i])->GetCopy();
		++iter;
		if (iter == _points.end()) break;
	}
	_center.SetCopy(f._center);
	_count = f._count;
	_plane = f._plane;
}

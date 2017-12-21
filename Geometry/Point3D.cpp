#include "stdafx.h"
#include "Point3D.h"
#include "IPoint.h"
#include "IPlane.h"
using namespace Geometry3D;
using namespace Geometry;
Point3D::Point3D(const double x, const double y, const double z)
{
	_points[0] = x;
	_points[1] = y;
	_points[2] = z;
}

Point3D::Point3D(const double x, const double y, const double z, IPlane * plane)
{
	_plane = plane;
	_points[0] = x;
	_points[1] = y;
	_points[2] = z;
}


Point3D::~Point3D() {}
void Point3D::ChangePlane() {_plane->Switch();}
void Point3D::SetPlane(IPlane * plane) {_plane = plane;}
double Point3D::GetZ() {return _points[_plane->GetNZ()];}
double Point3D::GetX() {return _points[0];}
double Point3D::GetY() {return _points[_plane->GetNY()];}
void Point3D::SetX(double x) {_points[0] = x;}
void Point3D::SetY(double y) {_points[_plane->GetNY()] = y;}

IPoint& Point3D::GetCopy()
{
	Point3D * a = new Point3D(_points[0], _points[1], _points[2], _plane);
	return *a;
}

void Point3D::SetCopy(IPoint& a)
{
	auto p = static_cast<Point3D&>(a);
	_points[0] = p._points[0];
	_points[1] = p._points[1];
	_points[2] = p._points[2];
	_plane = p._plane;
}

void Point3D::operator=(Point3D& a)
{
	_points[0] = a._points[0];
	_points[1] = a._points[1];
	_points[2] = a._points[2];
	_plane = a._plane;
}

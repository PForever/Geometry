// ConsolePrinter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Point.h"
#include "Rolf.h"
#include "MySqr.h"
#include "IPoint3D.h"
#include "Point3D.h"
#include "Plane.h"
#include "MyCoub.h"
#include "Rolf3D.h"

using namespace Geometry3D;
using namespace Geometry;
using namespace std;
using namespace chrono;
void prin(const Point * points, const int countPoints, char printPoints[][80], const int len1, const int len2);

int main()
{
	int const del = 100;
	int const del2 = 70;
	//double const x0 = 1, y0 = 1, x1 = 2, y1 = 1;
	//Point a(x1, y1);
	//Point c(x0, y0);

	//for (int i = 0; i < del; ++i)
	//{ Rolf::TurnOne(a, c, M_PI / del); }

	Plane * plane = new Plane();
	plane->Switch();
	//auto vec = vector<IPoint*>();
	//vec.push_back(new Point3D( 34, 14, 14, plane));
	//vec.push_back(new Point3D{ 34, 22, 22, plane });
	//vec.push_back(new Point3D{ 42, 22, 22, plane });
	//vec.push_back(new Point3D{ 42, 14, 14, plane });

	//auto vec2 = vector<IPoint*>();
	//vec2.push_back(new Point3D{ 34, 14, 14, plane });
	//vec2.push_back(new Point3D{ 34, 22, 22, plane });
	//vec2.push_back(new Point3D{ 42, 22, 22, plane });
	//vec2.push_back(new Point3D{ 42, 14, 14, plane });

	//Point3D point(38, 18, 18, plane);

	//MySqr* sq = new MySqr(vec, point);
	//MySqr* sqtemp = new MySqr(vec2, point.GetCopy());
	MyCoub sq;
	MyCoub sqtemp;
	int const len2 = 80;
	int const len1 = 40;
	int const timeout = 10;
	char printPoints[len1][len2];
	int k = 1;
	//IPoint * points = new Point(0, 0);
	auto points = vector<IPoint*>();
	while (true)
	{
		this_thread::sleep_for(milliseconds(timeout));
		system("cls");

		sqtemp = sq;
		//Rolf::TurnAll(sqtemp, M_PI / del * k++);
		Rolf3D::TurnAll(sqtemp, M_PI / del * k, M_PI / del2 * k++);
		points = sqtemp.GetPoints();/*&const_cast<Point&>(*sqtemp->GetPoints().cbegin());*/

		for (int i = 0; i < len1; ++i)
		{
			for (int t = 0; t < len2; ++t)
			{
				printPoints[i][t] = ' ';
			}
		}

		for (int i = 0; i < sqtemp._count; ++i)
		{
			auto a = static_cast<int>(round(points[i]->GetY()));
			auto b = static_cast<int>(round(points[i]->GetX()));
			printPoints[static_cast<int>(round(points[i]->GetY()))][static_cast<int>(round(points[i]->GetX()))] = '%';
		}
		for (int i = 0; i < len1; ++i)
		{
			for (int t = 0; t < len2; ++t)
			{
				cout << printPoints[i][t];//"#";
			}
			cout << endl;
		}
	}
	cin.get();
	return 0;
}

void prin(const Point * points, const int countPoints, char printPoints[][80], const int len1, const int len2)
{
	for (int i = 0; i < len1; ++i)
	{
		for (int t = 0; t < len2; ++t)
		{
			printPoints[i][t] = '_';
		}
	}

	for (int i = 0; i < countPoints; ++i)
	{
		printPoints[static_cast<int>(round(points[i].PointY))][static_cast<int>(round(points[i].PointX))] = '%';
	}
	for (int i = 0; i < len1; ++i)
	{
		for (int t = 0; t < len2; ++t)
		{
			cout << printPoints[i][t];//"#";
		}
		cout << endl;
	}

}




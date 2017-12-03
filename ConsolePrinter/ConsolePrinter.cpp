// ConsolePrinter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Point.h"
#include "Rolf.h"
#include "MySqr.h"

using namespace Geometry;
using namespace std;
using namespace chrono;
void prin(const Geometry::Point * points, const int countPoints, char printPoints[][80], const int len1, const int len2);

int main()
{
	int const del = 12;

	double const x0 = 1, y0 = 1, x1 = 2, y1 = 1;
	Point a(x1, y1);
	Point c(x0, y0);

	for (int i = 0; i < del; ++i)
	{
		Rolf::TurnOne(a, c, M_PI / del);
	}

	auto vec = vector<Point>({ { 34, 14 },{ 34, 22 },{ 42, 22 },{ 42, 14 } });
	Point point(38, 18);
	MySqr* sq = new MySqr(vec, point);
	MySqr* sqtemp = new MySqr();

	int const len2 = 80;
	int const len1 = 40;
	int const timeout = 10;
	char printPoints[len1][len2];
	int k = 1;
	Point * points = new Point(0, 0);
	while (true)
	{
		this_thread::sleep_for(milliseconds(timeout));
		system("cls");

		*sqtemp = *sq;
		Rolf::TurnAll(*sqtemp, M_PI / del * k++);
		points = &const_cast<Point&>(*sqtemp->GetPoints().cbegin());

		for (int i = 0; i < len1; ++i)
		{
			for (int t = 0; t < len2; ++t)
			{
				printPoints[i][t] = ' ';
			}
		}

		for (int i = 0; i < sqtemp->_count; ++i)
		{
			printPoints[static_cast<int>(round(points[i].PointY))][static_cast<int>(round(points[i].PointX))] = '%';
		}
		for (int i = 0; i < len1; ++i)
		{
			for (int t = 0; t < len2; ++t)
			{
				std::cout << printPoints[i][t];//"#";
			}
			std::cout << std::endl;
		}
	}
	cin.get();
	return 0;
}

void prin(const Geometry::Point * points, const int countPoints, char printPoints[][80], const int len1, const int len2)
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




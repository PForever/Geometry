// ConsolePrinter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "../Geometry/IFigure.h"
//#include "../Geometry/Rolf.h"
//#include "../Geometry/Point.h"
//#include "../Geometry/MySqr.h"
#include "Point.h"
#include "Rolf.h"
#include "MySqr.h"

using namespace Geometry;
using namespace std;
using namespace chrono;
void prin(const Geometry::Point * points, const int countPoints, char printPoints[][80], const int len1, const int len2);
const double eps = pow(10, -8);
#define ENQ(a, b) (abs(a - b) < eps)

int main()
{
	int const del = 12;

	double const x0 = 1, y0 = 1, x1 = 2, y1 = 1;
	Geometry::Point a(x1, y1);
	Geometry::Point c(x0, y0);

	double temp;
	for (int i = 0; i < del; ++i)
	{
		Rolf::TurnOne(a, c, M_PI / del);
		//temp = cos(M_PI / del) + x0;
		temp = Rolf::GetLength(a, c);
		if (!ENQ(temp, sqrt(2)))
		{
			temp = 0;
		}
		//temp = sin(M_PI / del) + y0;
		//if(!ENQ(a.PointY, temp))
		//{
		//	temp = 0;
		//};
	}

	auto vec = vector<Geometry::Point>({ { 34, 14 },{ 34, 22 },{ 42, 22 },{ 42, 14 } });
	Geometry::Point point(38, 18);
	MySqr* sq = new MySqr(vec, point);
	MySqr* sqtemp = new MySqr();

	//Rolf::TurnAll(*sq, M_PI/3);
	int const len2 = 80;
	int const len1 = 40;
	int const timeout = 10;
	//int const countPoints = 100;
	char printPoints[len1][len2];
	//Point * points = &const_cast<Point&>(*sq->GetPoints().cbegin());
	int k = 1;
	Geometry::Point * points = new Geometry::Point(0, 0);
	while (true)
	{
		//Point * points = new Point(0, 0);
		std::this_thread::sleep_for(milliseconds(timeout));
		system("cls");
		//if(points)delete points;
		//if(sqtemp)delete sqtemp;
		*sqtemp = *sq;
		Rolf::TurnAll(*sqtemp, M_PI / del * k++);
		points = &const_cast<Geometry::Point&>(*sqtemp->GetPoints().cbegin());

		//if(printPoints)delete[] printPoints;
		for (int i = 0; i < len1; ++i)
		{
			for (int t = 0; t < len2; ++t)
			{
				//if(&printPoints[i][t])delete &printPoints[i][t];
				printPoints[i][t] = ' ';
			}
		}

		for (int i = 0; i < sqtemp->_count; ++i)
		{
			printPoints[static_cast<int>(round(points[i].PointY))][static_cast<int>(round(points[i].PointX))] = '%';
			temp = Rolf::GetLength(a, c);
			//if (!ENQ(temp, sqrt(2)))
			//{
			//	temp = 0;
			//}
		}
		for (int i = 0; i < len1; ++i)
		{
			for (int t = 0; t < len2; ++t)
			{
				std::cout << printPoints[i][t];//"#";
			}
			std::cout << std::endl;
		}
		//prin(points, countPoints, printPoints, len1, len2);
		//for (int i = 0; i < 4; ++i)
		//{
		//	delete &points[i];
		//}
	}
	std::cin.get();
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
			std::cout << printPoints[i][t];//"#";
		}
		std::cout << std::endl;
	}

}




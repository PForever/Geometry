#include "stdafx.h"
#include "CppUnitTest.h"
#include "Rolf.h"
#include "Point.h"
#include "IPoint.h"
#include <complex>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry3D::Geometry;
using namespace std;
namespace GeometryTest
{		
	TEST_CLASS(RolfTest)
	{
		TEST_CLASS_INITIALIZE(classInitializer)
		{
			// происходит в начале тестирования 
		}
		TEST_CLASS_CLEANUP(classCleanUp)
		{
			// происходит по завершению тестирования
		}
		TEST_METHOD_INITIALIZE(methodInitializer)
		{
			// происходит в начале каждого теста
		}
		TEST_METHOD_CLEANUP(methodCleanUp)
		{
			// происходит в конце каждого теста 
		}
	public:
		
		TEST_METHOD(TestTurnOneTurning)
		{
			Point a(10, 0), c(5, 5);
			IPoint & b = Rolf::TurnOne(a, c, M_PI / 4);
			auto p = sqrt(5 * 5 + 5 * 5) + 5.;
			Assert::IsTrue(ENQ(b.GetX(), p));
			Assert::IsTrue(ENQ(b.GetY(), 5.));
		}


		TEST_METHOD(TestTemp)
		{
			auto b = 5 * 2;
			auto p = sqrt(5 * 5 + 5 * 5) + 5.;
		}
	};
}
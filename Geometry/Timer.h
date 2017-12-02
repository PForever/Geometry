#pragma once
#include <chrono>
#include <vector>
#include "Geometry.h"
typedef int(*t_handler)(int);

void PeriodFunction(std::chrono::milliseconds period, std::vector<t_handler> handler);
namespace Geometry
{
	class Timer
	{
	public:
		MATHFUNCSDLL_API Timer(int period);
		MATHFUNCSDLL_API ~Timer();
		MATHFUNCSDLL_API void Handler_add(t_handler);
		MATHFUNCSDLL_API void Start();
	private:

		std::chrono::milliseconds _period;
		std::vector<t_handler> _handler;
	};
}
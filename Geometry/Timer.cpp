#include "stdafx.h"
#include "Timer.h"
#include <thread>
using namespace Geometry;

using namespace std;
using namespace chrono;
void PeriodFunction(milliseconds period, vector<t_handler> handler)
{
	milliseconds time = milliseconds(0);
	while (true)
	{
		//_time.operator+=(period);
		time += period;
		this_thread::sleep_for(period);
		for (t_handler method : handler)
		{
			method(static_cast<int>(time.count()));
			//thread thr(method, time.count());
			//thr.join();

		}
	}
}

Timer::Timer(int period)
{
	_period = milliseconds(period);
}


Timer::~Timer()
{
}

void Timer::Handler_add(t_handler method)
{
	_handler.push_back(method);
}

void Timer::Start()
{
	thread thr(PeriodFunction, _period, _handler);
	thr.detach();
}

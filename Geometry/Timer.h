#pragma once
#include <chrono>
#include <vector>
#include "Geometry.h"
typedef int(*t_handler)(int);

void PeriodFunction(std::chrono::milliseconds period, std::vector<t_handler> handler);
namespace Geometry3D
{
	namespace Geometry
	{
		/* Таймер поддерживающий вызов колбеков */
		//TODO надо бы переписать согласно паттерну Наблюдатель
		class Timer
		{
		public:
			/* создаёт таймер с периодом заданым в миллисекундах */
			MATHFUNCSDLL_API Timer(int period);
			MATHFUNCSDLL_API ~Timer();
			/* Добавляет обработчик в лист кодбэков */
			MATHFUNCSDLL_API void Handler_add(t_handler);
			/* Запускает таймер */
			MATHFUNCSDLL_API void Start();
		private:

			std::chrono::milliseconds _period;
			std::vector<t_handler> _handler;
		};
	}
}

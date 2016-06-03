#include "schedule.h"

void Schedule::initialize()
{
	id = 0;
	movie.initialize();
	date.initialize();
	screen.initialize();
	startTime = 0;
	endTime = 0;
}

void Schedule::show()
{
	if (date.getValue() != 0)
	{
		cout << "상영일: ";
		date.show();
	}

	if (screen.getNumber() != 0)
	{
		cout << "상영관: " << screen.getNumber() << "관\n";
	}

	if (movie.getCode() != 0)
	{
		cout << "상영작: ";
		movie.show();
	}

	showTime();
}

void Schedule::showTime()
{
	if (0 < startTime)
	{
		cout << "시작시간: " << startTime / 100 << "시 " << startTime % 100 << "분\n";
	}
	
	if (0 < endTime)
	{
		cout << "종료시간: " << endTime / 100 << "시 " << endTime % 100 << "분\n";
	}
}

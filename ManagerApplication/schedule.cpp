#include "schedule.h"

void Schedule::initialize()
{
	id = 0;
	movie.initialize();
	screen.initialize();
	startTime = 0;
	endTime = 0;
}

void Schedule::show() const
{
	wcout << movie.getTitle() << L"(";
	
	if (0 == movie.getAge())
	{
		cout << "전체";
	}
	else
	{
		cout << movie.getAge() << "세";
	}

	cout << "), "
		<< startTime / 100 << "시 " << startTime % 100 << "분 ~ "
		<< endTime / 100 << "시 " << endTime % 100 << "분\n";
}

void Schedule::showTime() const
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

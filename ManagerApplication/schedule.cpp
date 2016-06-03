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
		cout << "����: ";
		date.show();
	}

	if (screen.getNumber() != 0)
	{
		cout << "�󿵰�: " << screen.getNumber() << "��\n";
	}

	if (movie.getCode() != 0)
	{
		cout << "����: ";
		movie.show();
	}

	showTime();
}

void Schedule::showTime()
{
	if (0 < startTime)
	{
		cout << "���۽ð�: " << startTime / 100 << "�� " << startTime % 100 << "��\n";
	}
	
	if (0 < endTime)
	{
		cout << "����ð�: " << endTime / 100 << "�� " << endTime % 100 << "��\n";
	}
}

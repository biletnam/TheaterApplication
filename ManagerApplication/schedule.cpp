#include "schedule.h"

void Schedule::initialize()
{
	id = 0;
}

void Schedule::show()
{
	if (date.getValue() != 0)
	{
		cout << "날짜 ";
		date.show();
	}

	if (screen.getNumber() != 0)
	{
		cout << "상영관 " << screen.getNumber() << "관\n";
	}

	if (movie.getCode() != 0)
	{
		movie.show();
	}

	if (getStartTime() != 0)
	{
		cout << "시작시간 " << getStartTime() << endl;
		cout << "종료시간 " << getEndTime() << endl;
	}
}
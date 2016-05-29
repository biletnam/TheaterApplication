#include "schedule.h"

void Schedule::showInfo()
{
	if (date.getValue() != 0)
	{
		cout << "날짜 ";
		date.show();
		cout << endl;
	}

	if (screen.getNumber() != 0)
	{
		cout << "상영관 " << screen.getNumber() << "관\n";
	}

	if (movie.getCode() != 0)
	{
		movie.show();
	}
	
	if (time.getStartTime() != 0)
	{
		cout << "시작시간 " << time.getStartTime() << endl;
		cout << "종료시간 " << time.getEndTime() << endl;
	}
}
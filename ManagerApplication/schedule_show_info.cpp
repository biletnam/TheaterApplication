#include "schedule.h"

void Schedule::showInfo()
{
	if (date.value != 0)
	{
		cout << "날짜 " << date.value << endl;
	}

	if (screen.number != 0)
	{
		cout << "상영관 " << screen.number << endl;
	}

	if (movie.code != 0) 
	{
		cout << "영화코드 " << movie.code << endl;
		cout << "영화제목 " <<movie.title << endl;
		cout << "관람가 " << movie.age << endl;
	}
	
	if (startTime != 0)
	{
		cout << "시작시간 " << startTime << endl;
		cout << "종료시간 " << endTime << endl;
	}
	
	cout << endl;
}
#include "issue.h"

void Issue::showInfo()
{
	system("cls");

	cout << "\n발권 정보:\n";

	// 날짜
	if (date != 0)
	{
		int year = date / 10000 + 2000;
		int month = (date % 10000) / 100;
		int day = (date % 100);
		cout << year << "년 "
			<< month << "월 "
			<< day << "일\n";
	}

	// 영화
	if (movieCode != 0)
	{
		cout << "선택한 영화: " << movieTitle << endl;
	}

	// 시간
	if (startTime != 0)
	{
		int hour = startTime / 100;
		int minute = startTime % 100;

		cout << hour << "시 " << minute << "분\n";
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		Ticket ticket = tickets.at(i);
		cout << ticket.row << "열 "
			<< ticket.col << "번 "
			<< ticket.priceName << endl;
			
	}
}
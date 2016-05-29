#include "schedule.h"

void Schedule::showInfo()
{
	if (date.getValue() != 0)
	{
		cout << "��¥ ";
		date.show();
		cout << endl;
	}

	if (screen.getNumber() != 0)
	{
		cout << "�󿵰� " << screen.getNumber() << "��\n";
	}

	if (movie.getCode() != 0)
	{
		movie.show();
	}
	
	if (time.getStartTime() != 0)
	{
		cout << "���۽ð� " << time.getStartTime() << endl;
		cout << "����ð� " << time.getEndTime() << endl;
	}
}
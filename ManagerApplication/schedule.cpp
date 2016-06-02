#include "schedule.h"

void Schedule::initialize()
{
	id = 0;
}

void Schedule::show()
{
	if (date.getValue() != 0)
	{
		cout << "��¥ ";
		date.show();
	}

	if (screen.getNumber() != 0)
	{
		cout << "�󿵰� " << screen.getNumber() << "��\n";
	}

	if (movie.getCode() != 0)
	{
		movie.show();
	}

	if (getStartTime() != 0)
	{
		cout << "���۽ð� " << getStartTime() << endl;
		cout << "����ð� " << getEndTime() << endl;
	}
}
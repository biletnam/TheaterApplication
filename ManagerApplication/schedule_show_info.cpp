#include "schedule.h"

void Schedule::showInfo()
{
	if (date.value != 0)
	{
		cout << "��¥ ";
		date.show();
		cout << endl;
	}

	if (screen.number != 0)
	{
		cout << "�󿵰� " << screen.number << "��\n";
	}

	if (movie.code != 0) 
	{
		cout << "��ȭ�ڵ� " << movie.code << endl;
		cout << "��ȭ���� " <<movie.title << endl;
		cout << "������ " << movie.age << endl;
	}
	
	if (startTime != 0)
	{
		cout << "���۽ð� " << startTime << endl;
		cout << "����ð� " << endTime << endl;
	}
	
	cout << endl;
}
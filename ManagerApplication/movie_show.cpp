#include "movie.h"

void Movie::show()
{
	cout << title
		<< "(" << director << "), "
		<< runningTime << "��, ";
	if (age == 0)
	{
		cout << "��ü";
	}
	else
	{
		cout << age << "��";
	}
	cout << ", " << year << "��\n";
}

void Movie::showNullMessage()
{
	cout << "\n��ϵ� ��ȭ�� �����ϴ�.\n";
	system("pause");
}

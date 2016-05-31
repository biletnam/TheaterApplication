#include "movie.h"

void Movie::show()
{
	cout << title
		<< "(" << director << "), "
		<< runningTime << "분, ";
	if (age == 0)
	{
		cout << "전체";
	}
	else
	{
		cout << age << "세";
	}
	cout << ", " << year << "년\n";
}

void Movie::showNullMessage()
{
	cout << "\n등록된 영화가 없습니다.\n";
	system("pause");
}

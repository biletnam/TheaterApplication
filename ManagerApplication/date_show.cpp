#include "date.h"

void Date::show()
{
	if (0 != getYear())
	{
		cout << getYear() << "년 ";
	}

	if (0 != getMonth())
	{
		cout << getMonth() << "월 ";
	}

	if (0 != getDay())
	{
		cout << getDay() << "일";
	}
	cout << endl;
}
/*
FNRETURN Date::showSelectResult()
{
	bindCol();

	if (SQL_SUCCESS == execute(MDF_THEATER))
	{
		cout << endl;
		for (size_t i = 1;; i++)
		{
			switch (fetch(MDF_THEATER))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				show();
				continue;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "등록된 날짜가 없습니다\n";
					return FUNCTION_NULL;
				}
				else
				{
					return FUNCTION_SUCCESS;
				}
			}
			break;
		}
	}

	cout << "오류가 발생했습니다.(Date::showSelectResult)\n";
	system("pause");
	return FUNCTION_ERROR;
}
*/
#include "date.h"

void Date::show()
{
	if (0 != getYear())
	{
		cout << getYear() << "�� ";
	}

	if (0 != getMonth())
	{
		cout << getMonth() << "�� ";
	}

	if (0 != getDay())
	{
		cout << getDay() << "��";
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
					cout << "��ϵ� ��¥�� �����ϴ�\n";
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

	cout << "������ �߻��߽��ϴ�.(Date::showSelectResult)\n";
	system("pause");
	return FUNCTION_ERROR;
}
*/
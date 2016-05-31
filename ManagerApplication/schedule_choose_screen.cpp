#include "schedule.h"

FNRETURN Schedule::chooseScreen()
{
	cout << "�󿵰� ����\n";
	
	screen.bindCol(MDF_THEATER, SCREEN_NUMBER);
	if (SQL_SUCCESS == execute(MDF_THEATER, L"SELECT number FROM screen;"))
	{
		for (int i = 1;; i++)
		{
			switch (fetch(MDF_THEATER))
			{
			case SQL_SUCCESS:
				cout << i << ". " << screen.getNumber() << "��\n";
				break;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "��� ������ �󿵰��� �����ϴ�\n";
					system("pause");

					return FUNCTION_NULL;
				}
				else
				{
					screen.setNumber(0);
					cout << 
						"0. ����\n"
						"\n"
						"����: ";
					return moveCursor(MDF_THEATER);
				}
			}
		}
	}
			
	cout << "������ �߻��߽��ϴ�.\n";
	system("pause");

	return FUNCTION_ERROR;
}
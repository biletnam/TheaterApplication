#include "schedule.h"

FNRETURN Schedule::chooseScreen()
{
	cout << "�󿵰� ����\n";
	
	screen.bindParameter(MDF_THEATER, SCREEN_NUMBER);
	if (SQL_SUCCESS == dbHelper.execute(MDF_THEATER, L"SELECT number FROM screen;"))
	{
		for (int i = 1; SQL_SUCCESS; i++)
		{
			switch (dbHelper.fetch(MDF_THEATER))
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
					return dbHelper.moveCursor(MDF_THEATER);
				}
			}
		}
	}
		
	
	
	cout << "������ �߻��߽��ϴ�.\n";
	system("pause");

	return FUNCTION_ERROR;
}
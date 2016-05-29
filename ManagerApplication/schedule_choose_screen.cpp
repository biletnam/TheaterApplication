#include "schedule.h"

FNRETURN Schedule::chooseScreen()
{
	cout << "상영관 선택\n";
	
	screen.bindParameter(MDF_THEATER, SCREEN_NUMBER);
	if (SQL_SUCCESS == dbHelper.execute(MDF_THEATER, L"SELECT number FROM screen;"))
	{
		for (int i = 1; SQL_SUCCESS; i++)
		{
			switch (dbHelper.fetch(MDF_THEATER))
			{
			case SQL_SUCCESS:
				cout << i << ". " << screen.getNumber() << "관\n";
				break;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "등록 가능한 상영관이 없습니다\n";
					system("pause");

					return FUNCTION_NULL;
				}
				else
				{
					screen.setNumber(0);
					cout << 
						"0. 종료\n"
						"\n"
						"선택: ";
					return dbHelper.moveCursor(MDF_THEATER);
				}
			}
		}
	}
		
	
	
	cout << "오류가 발생했습니다.\n";
	system("pause");

	return FUNCTION_ERROR;
}
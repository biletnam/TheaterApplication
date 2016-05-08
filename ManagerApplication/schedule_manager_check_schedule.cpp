#include "schedule_manager.h"

void ScheduleManager::checkSchedule()
{
	system("cls");
	cout << "�� ���� Ȯ��\n";

	Schedule schedule(dbHelper);
	schedule.chooseDate();
	schedule.chooseScreen();
	
	// saleinfo select
	SQLHSTMT &stmt = dbHelper.saleInfoStmt;
	SQLWCHAR sql[BUFSIZ];
	swprintf_s(sql,	L""
		"SELECT movie_code, movie_title, age, start_time, end_time FROM d%d "
		"WHERE screen = %d "
		"ORDER BY start_time ASC;", schedule.date.value, schedule.screen.number);
	
	schedule.bindCol();

	SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ".";
			schedule.showInfo();
			cout << endl;
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "��ϵ� ������ �����ϴ�.\n"
					"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
				_getch();
				
			}
			else 
			{
				switch (dbHelper.moveCursor(stmt, "������ �����ϼ���"))
				{
				case FUNCTION_CANCEL:
					return;
				case FUNCTION_SUCCESS:
					return;
				case FUNCTION_ERROR:
					break;
				}
			}
		default:
			break;
		}
	}

	cout << "������ �߻��߽��ϴ�..\n"
		"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
	_getch();
}



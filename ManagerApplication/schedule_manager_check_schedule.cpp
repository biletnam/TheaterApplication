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
		"SELECT screen, movie_code, movie_title, start_time, end_time FROM d%d "
		"ORDER BY screen ASC, start_time ASC;", schedule.date.value);
	
	SQLBindCol(stmt, 1, SQL_INTEGER, &schedule.screen.number, 
		sizeof schedule.screen.number, NULL);
	SQLBindCol(stmt, 2, SQL_INTEGER, &schedule.movie.code, 
		sizeof schedule.movie.code, NULL);
	SQLBindCol(stmt, 3, SQL_CHAR, &schedule.movie.title, BUFSIZ, NULL);
	SQLBindCol(stmt, 4, SQL_INTEGER, &schedule.startTime, sizeof schedule.startTime, NULL);
	SQLBindCol(stmt, 5, SQL_INTEGER, &schedule.endTime, sizeof schedule.endTime, NULL);

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



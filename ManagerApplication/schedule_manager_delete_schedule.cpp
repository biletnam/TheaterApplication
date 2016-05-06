#include "schedule_manager.h"
#include <conio.h>

void ScheduleManager::deleteSchedule()
{
	for (;;)
	{
		Schedule schedule(dbHelper);
		schedule.chooseScreen();
		schedule.chooseDate();
		SQLHSTMT &stmt = dbHelper.saleInfoStmt;

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT movie_code, movie_title, start_time, end_time, age, price_code, price_name, price_won, id"
			"FROM d%d "
			"WHERE screen=%d", schedule.date.value, schedule.screen.number);
		SQLBindCol(stmt, 1, SQL_INTEGER, &schedule.movie.code, sizeof(schedule.movie.code), NULL);
		SQLBindCol(stmt, 2, SQL_WVARCHAR, schedule.movie.title, BUFSIZ, NULL);
		SQLBindCol(stmt, 3, SQL_INTEGER, &schedule.startTime, sizeof(schedule.startTime), NULL);
		SQLBindCol(stmt, 4, SQL_INTEGER, &schedule.endTime, sizeof(schedule.endTime), NULL);
		SQLBindCol(stmt, 5, SQL_INTEGER, &schedule.movie.age, sizeof(schedule.movie.age), NULL);
		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		for (int i = 0; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				schedule.showInfo();
				break;
			case SQL_NO_DATA:
				dbHelper.moveCursor(stmt, "������ ������ �����ϼ���");
				break;
			default:
				cout << "������ �߻��߽��ϴ�.\n";
				_getch();
			}
		}

		SQLINTEGER id;
		SQLGetData(stmt, 1, SQL_INTEGER, &id, sizeof(id), NULL);
		swprintf_s(sql,	L"DELETE FROM d%d WHERE id=%d;", schedule.date, id);

		if (SQLExecDirect(stmt, sql, SQL_NTS) == SQL_SUCCESS)
		{
			cout << "����\n";
		}
		else
		{
			cout << "����\n";
		}
		SQLCancel(stmt);
	}
}
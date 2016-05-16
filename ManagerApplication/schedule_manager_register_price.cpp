#include "schedule_manager.h"

FNRETURN ScheduleManager::registerPrice(Schedule &schedule)
{
	system("cls");
	cout <<
		"���� ���� �ý���\n"
		" > �� ���� ����\n"
		"  > �� ���� Ȯ��/����\n"
		"   > ���� ���\n\n"

		"������ �� ����\n";
	schedule.showInfo();
	cout << endl;

	Price price;
	SQLCancel(dbHelper.theaterStmt);
	SQLBindCol(dbHelper.theaterStmt, 1, SQL_INTEGER, &price.code, sizeof price.code, NULL);
	SQLBindCol(dbHelper.theaterStmt, 2, SQL_WVARCHAR, price.name, BUFSIZ, NULL);
	SQLBindCol(dbHelper.theaterStmt, 3, SQL_INTEGER, &price.won, sizeof price.won, NULL);
	SQLRETURN ret = SQLExecDirect(dbHelper.theaterStmt, L"SELECT code, name, won FROM price;", SQL_NTS);

	for (int i = 1; SQL_SUCCESS == ret; i++)
	{
		switch (ret = SQLFetch(dbHelper.theaterStmt))
		{
		case SQL_SUCCESS:
			cout << i << ". " << price.name << " " << price.won << "��\n";
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "��ϵ� ���� ������ �����ϴ�.\n"
					"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
				_getch();
				return FUNCTION_NULL;
			}
			else
			{
				cout << "0. ����\n";

				switch (dbHelper.moveCursor(dbHelper.theaterStmt, "\n����: "))
				{
				case FUNCTION_CANCEL:
					return FUNCTION_CANCEL;
				case FUNCTION_SUCCESS:
					{
						SQLWCHAR sql[BUFSIZ];
						swprintf_s(sql, L""
							"INSERT INTO d%d "
							"(movie_code, movie_title, age, start_time, end_time, screen, price_code, price_name, price_won) "
							"VALUES (%d, ?, %d, %d, %d, %d, %d, ?, %d);",
							schedule.date.value,
							schedule.movie.code, schedule.movie.age,
							schedule.startTime, schedule.endTime,
							schedule.screen.number,
							price.code, price.won);

						SQLCancel(dbHelper.saleInfoStmt);
						SQLBindParameter(dbHelper.saleInfoStmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
							BUFSIZ, 0, schedule.movie.title, 0, NULL);
						SQLBindParameter(dbHelper.saleInfoStmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
							BUFSIZ, 0, price.name, 0, NULL);
						SQLExecDirect(dbHelper.saleInfoStmt, sql, SQL_NTS);
					}
				}
			}
		}
	}

	cout << "������ �߻��߽��ϴ�..\n"
		"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
	_getch();
	return FUNCTION_ERROR;
}

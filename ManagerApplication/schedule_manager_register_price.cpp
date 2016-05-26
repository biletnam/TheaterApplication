#include "schedule_manager.h"

void ScheduleManager::registerPrice(Schedule &schedule)
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

	Price price(dbHelper);
	SQLHSTMT &theaterStmt = dbHelper.getStmt(MDF_THEATER);
	SQLCancel(theaterStmt);
	price.bindCol(theaterStmt);
	SQLRETURN ret = SQLExecDirect(theaterStmt, L"SELECT code, name, won FROM price;", SQL_NTS);
	if (ret != SQL_SUCCESS)
	{
		cout << "������ �߻��߽��ϴ�.(registerPrice)\n";
		system("pause");
		return;
	}

	for (int i = 1; SQL_SUCCESS == ret; i++)
	{
		switch (ret = SQLFetch(theaterStmt))
		{
		case SQL_SUCCESS:
			cout << i << ". " << price.name << " " << price.won << "��\n";
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "��ϵ� ���� ������ �����ϴ�.\n";
				system("pause");
				return;
			}

			cout << "0. ����\n";
			switch (dbHelper.moveCursor(MDF_THEATER, "\n����: "))
			{
			case FUNCTION_CANCEL:
				return;
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

				SQLHSTMT saleInfoStmt = dbHelper.getStmt(MDF_SALE_INFO);
				SQLCancel(saleInfoStmt);
				SQLBindParameter(saleInfoStmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
					BUFSIZ, 0, schedule.movie.title, 0, NULL);
				SQLBindParameter(saleInfoStmt, 2, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
					BUFSIZ, 0, price.name, 0, NULL);

				if (SQL_SUCCESS == SQLExecDirect(saleInfoStmt, sql, SQL_NTS))
				{
					cout << "������ ��ϵǾ����ϴ�.\n";
				}
				else
				{
					cout << "������ �߻��߽��ϴ�.(registerPrice)\n";
				}
				system("pause");
			}
			}
		}
	}
}

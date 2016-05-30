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
	schedule.show();
	cout << endl;

	Price price;
	SQLHSTMT &theaterStmt = price.getStmt(MDF_THEATER);
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
			price.show();
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "��ϵ� ���� ������ �����ϴ�.\n";
				system("pause");
				return;
			}

			cout << "0. ����\n";
			switch (price.moveCursor(MDF_THEATER))
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
			{
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L""
					"INSERT INTO d%d "
					"(movie_code, movie_title, age, start_time, end_time, screen, price_code, price_name, price_won) "
					"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);", schedule.date.getValue());
					
				schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_CODE);
				schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_TITLE);
				schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_AGE);
				schedule.time.bindParameter(MDF_SALE_INFO, START_TIME);
				schedule.time.bindParameter(MDF_SALE_INFO, END_TIME);
				schedule.screen.bindParameter(MDF_SALE_INFO, SCREEN_NUMBER);
				price.bindParameter(MDF_SALE_INFO, PRICE_CODE);
				price.bindParameter(MDF_SALE_INFO, PRICE_NAME);
				price.bindParameter(MDF_SALE_INFO, PRICE_WON);

				if (SQL_SUCCESS == price.execute(MDF_SALE_INFO, sql))
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

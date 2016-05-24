#include "schedule_manager.h"

FNRETURN ScheduleManager::deletePrice(Schedule &schedule)
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� Ȯ�� / ����\n"
			"   > ���� ���� ����\n\n"

			"������ �� ����\n";
		schedule.showInfo();
		cout << endl;

		
		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT price_code, price_name, price_won, id "
			"FROM d%d "
			"WHERE movie_code=%d AND start_time=%d AND screen=%d;",
			schedule.date.value, schedule.movie.code, schedule.startTime, schedule.screen.number);

		SQLINTEGER id;	// sale_info id

		Price price(dbHelper);
		SQLHSTMT &stmt = dbHelper.getStmt(SALE_INFO);
		SQLCancel(stmt);
		price.bindCol(stmt);
		SQLBindCol(stmt, 4, SQL_INTEGER, &id, sizeof id, NULL);

		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		for (int i = 1; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				cout << i << ". " << price.name << " " << price.won << "��\n";
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "\n��ϵ� ������ �����ϴ�\n";
					system("pause");

					return 0;
				}
				else
				{
					switch (dbHelper.moveCursor(stmt, "\n������ ������ �����ϼ���"))
					{
					case FUNCTION_SUCCESS:
					{
						swprintf_s(sql,
							L"DELETE FROM d%d WHERE id=%d;",
							schedule.date.value, id);
					}
					case FUNCTION_CANCEL:
						break;
					}
				}
			default:
				break;
			}
		}

		cout << "������ �߻��߽��ϴ�.\n";
		system("pause");
		return FUNCTION_ERROR;
	}
}
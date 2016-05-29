#include "schedule_manager.h"

void ScheduleManager::checkAndDeletePrice(Schedule &schedule)
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� Ȯ��/����\n"
			"   > ���� ���� Ȯ��/����\n"
			"\n"
			"������ �� ����\n";
		schedule.show();
		cout << endl;

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT price_code, price_name, price_won, id "
			"FROM d%d "
			"WHERE movie_code=? AND start_time=? AND screen=?;",
			schedule.date.getValue());
		schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_CODE);
		schedule.time.bindParameter(MDF_SALE_INFO, START_TIME);
		schedule.screen.bindParameter(MDF_SALE_INFO, SCREEN_NUMBER);

		SQLINTEGER id;	// sale_info id

		Price price(dbHelper);
		SQLHSTMT &stmt = dbHelper.getStmt(MDF_SALE_INFO);
		SQLCancel(stmt);
		price.bindCol(stmt);
		SQLBindCol(stmt, 4, SQL_INTEGER, &id, sizeof id, NULL);

		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);
		if (ret != SQL_SUCCESS)
		{
			cout << "������ �߻��߽��ϴ�.(deletePrice)\n";
			system("pause");
			return;
		}

		cout << "0. ���\n";
		for (size_t i = 1; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				price.show();
			case SQL_NO_DATA:
				if (i == 1)		// ��ϵ� ������ ���� ��
				{
					cout << "\n��ϵ� ������ �����ϴ�\n";
					system("pause");
					return;
				}

				cout << 
					"0. ���\n"
					"\n"
					"������ ������ �����ϼ���";
				switch (dbHelper.moveCursor(MDF_SALE_INFO))
				{
				case FUNCTION_CANCEL:	// ����
					return;
				case FUNCTION_SUCCESS:	// ���� ����: �ݺ�
					swprintf_s(sql, L"DELETE FROM d%d WHERE id=%d;", schedule.date.getValue(), id);
					SQLCancel(stmt);
					if (SQL_SUCCESS == SQLExecDirect(stmt, sql, SQL_NTS))
					{
						cout << "������ �����Ǿ����ϴ�.\n";
					}
					else	// ���� ����: �ݺ�
					{
						cout << "������ �߻��߽��ϴ�.(deletePrice)\n";
					}
					system("pause");
				}
			}
		}
	}
}
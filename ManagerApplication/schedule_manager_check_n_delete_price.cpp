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
		Price price;
		price.bindCol(MDF_SALE_INFO);
		schedule.DBHelper::bindCol(MDF_SALE_INFO, BIND_INTEGER, &id);
		//SQLBindCol(stmt, 4, SQL_INTEGER, &id, sizeof id, NULL);

		if (SQL_SUCCESS != schedule.prepare(sql) )
		{
			cout << "������ �߻��߽��ϴ�.(checkAndDeletePrice)\n";
			system("pause");
			return;
		}

		switch (schedule.choose())
		{
		case FUNCTION_SUCCESS:
			swprintf_s(sql, L"DELETE FROM d%d WHERE id=%d;", schedule.date.getValue(), id);
		case FUNCTION_CANCEL:
		case FUNCTION_ERROR:
		case FUNCTION_NULL:
		default:
			break;
		}


		cout << "0. ���\n";
		for (size_t i = 1;; i++)
		{
			switch (schedule.fetch(MDF_SALE_INFO))
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
				switch (price.moveCursor(MDF_SALE_INFO))
				{
				case FUNCTION_CANCEL:	// ����
					return;
				case FUNCTION_SUCCESS:	// ���� ����: �ݺ�
					swprintf_s(sql, L"DELETE FROM d%d WHERE id=%d;", schedule.date.getValue(), id);
					if (SQL_SUCCESS == schedule.execute(MDF_SALE_INFO, sql))
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
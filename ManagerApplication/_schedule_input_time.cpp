#include "schedule.h"

FNRETURN Schedule::insertPrice()
{
	return FNRETURN();
}

FNRETURN Schedule::inputTime(const SQLSMALLINT time)
{
	/*cin >> time;
	return checkTime(time);*/

	return FNRETURN();
}

FNRETURN Schedule::inputTime()
{
	/*cout << "���� �ð��� �Է��ϼ���(0�� �Է��ϸ� ����): ";
	switch (inputTime(time.getStartTime()))
	{
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	case FUNCTION_SUCCESS:
		cout << "���� �ð��� �Է��ϼ���(0�� �Է��ϸ� ����): ";
		switch (inputTime(endTime))
		{
		case FUNCTION_CANCEL:
			return inputTime();
		case FUNCTION_SUCCESS:
			return FUNCTION_SUCCESS;
		}
	case FUNCTION_ERROR:
		return inputTime();
	default:
		return FUNCTION_ERROR;
	}*/

	return FNRETURN();
}

FNRETURN Schedule::checkTime(const SQLSMALLINT time)
{
	if (time == FUNCTION_CANCEL)
	{
		return FUNCTION_CANCEL;
	}
	else if (cin.fail() == false)
	{
		SQLHSTMT &stmt = getStmt(MDF_SALE_INFO);
		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT * FROM d%d "
			"WHERE screen = %d AND start_time <= %d AND end_time >= %d;",
			date.getValue(), screen.getNumber(), time, time);
		SQLExecDirect(stmt, sql, SQL_NTS);
		SQLRETURN ret = SQLFetch(stmt);
		SQLCancel(stmt);

		if (ret == SQL_NO_DATA)
		{
			return FUNCTION_SUCCESS;
		}
	}
	else
	{
		cout << "�ٽ� ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	return FUNCTION_ERROR;
}
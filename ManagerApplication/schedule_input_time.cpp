#include "schedule.h"

int16_t Schedule::inputTime(SQLSMALLINT& time, const char *output)
{
	cout << output;
	cin >> time;
	return checkTime(time);
}

int16_t Schedule::inputTime()
{
	switch (inputTime(startTime, "시작 시간을 입력하세요(0을 입력하면 종료): "))
	{
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	case FUNCTION_SUCCESS:
		switch (inputTime(endTime, "종료 시간을 입력하세요(0을 입력하면 종료): "))
		{
		case FUNCTION_CANCEL:
			return inputTime();
		case FUNCTION_SUCCESS:
			return FUNCTION_SUCCESS;
		}
	case FUNCTION_ERROR:
		return inputTime();
	}
}

int16_t Schedule::checkTime(const SQLSMALLINT time)
{
	if (time == FUNCTION_CANCEL)
	{
		return FUNCTION_CANCEL;
	}
	else if (cin.fail() == false)
	{
		SQLHSTMT &stmt = dbHelper.saleInfoStmt;
		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT * FROM d%d "
			"WHERE screen = %d AND start_time <= %d AND end_time >= %d;",
			date.value, screen.number, time, time);
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
		cout << "다시 ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	return FUNCTION_ERROR;
}

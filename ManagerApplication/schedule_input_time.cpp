#include "schedule.h"

FNRETURN Schedule::inputTime()
{
	if (0 == startTime)
	{
		return inputStartTime();
	}
	else if (0 == endTime)
	{
		switch (inputEndTime())
		{
		case FUNCTION_CANCEL:
			startTime = 0;
		case FUNCTION_SUCCESS:
			return FUNCTION_SUCCESS;
		}
	}

	return FUNCTION_ERROR;
}

FNRETURN Schedule::inputStartTime()
{
	cout << "시작 시간을 입력하세요(0을 입력하면 종료): ";

	int32_t time;
	switch (inputPositiveInteger(time))
	{
	case FUNCTION_SUCCESS:
		if ((0 == endTime || time < endTime)
			&& true == isPossibleTime(time))
		{
			startTime = time;
			return FUNCTION_SUCCESS;
		}
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	}

	return FUNCTION_ERROR;
	
}

FNRETURN Schedule::inputEndTime()
{
	cout << "종료 시간을 입력하세요(0을 입력하면 종료): ";

	int32_t time;
	switch (inputPositiveInteger(time))
	{
	case FUNCTION_SUCCESS:
		if ((0 == startTime || time > startTime)
			&& true == isPossibleTime(time))
		{
			endTime = time;
			return FUNCTION_SUCCESS;
		}
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	}

	return FUNCTION_ERROR;
}

bool Schedule::isPossibleTime(SQLINTEGER time)
{
	SQLWCHAR sql[BUFSIZ];
	swprintf_s(sql, L""
		"SELECT * FROM d%d "
		"WHERE screen = %d AND start_time <= %d AND end_time >= %d;",
		date.getValue(), screen.getNumber(), time, time);
	execute(MDF_SCHEDULE, sql);
	
	if (SQL_NO_DATA == fetch(MDF_SCHEDULE))
	{
		return true;
	}
	else
	{
		return false;
	}
}

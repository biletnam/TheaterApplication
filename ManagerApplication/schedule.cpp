#include "schedule.h"

SQLRETURN Schedule::prepare(SQLWCHAR *sql)
{
	return DBHelper::prepare(MDF_SCHEDULE, sql);
}
FNRETURN Schedule::choose()
{
	return DBHelper::choose(MDF_SCHEDULE);
}

void Schedule::initialize()
{
	movie.initialize();
	screen.initialize();
	date.initialize();
	time.initialize();
}
#include "schedule.h"

SQLRETURN Schedule::prepare(SQLWCHAR *sql)
{
	return DBHelper::prepare(MDF_SALE_INFO, sql);
}
FNRETURN Schedule::choose()
{
	return DBHelper::choose(MDF_SALE_INFO);
}

void Schedule::initialize()
{
	movie.initialize();
	screen.initialize();
	date.initialize();
	time.initialize();
	price.initialize();
}
#ifndef SCHEDULE_MANAGE_H
#define SCHEDULE_MANAGE_H

#include "schedule.h"
#include "price.h"

class ScheduleManager {
public:
	ScheduleManager(DBHelper *);

private:
	void addDate();	
	void registerSchedule();
	void checkSchedule();

	FNRETURN registerPrice(Schedule &);
	FNRETURN deletePrice(Schedule &);
	FNRETURN modifySchedule(Schedule & schedule);
		
	DBHelper *pDBHelper;
};

#endif // !SCHEDULE_MANAGE_H
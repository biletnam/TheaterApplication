#ifndef SCHEDULE_MANAGE_H
#define SCHEDULE_MANAGE_H

#include "schedule.h"

class ScheduleManager {
public:
	ScheduleManager(DBHelper&);

private:
	void addDate();	
	void registerSchedule();
	void registerPrice();
	void checkSchedule();
	void deleteSchedule();
		
	DBHelper dbHelper;
};

#endif // !SCHEDULE_MANAGE_H
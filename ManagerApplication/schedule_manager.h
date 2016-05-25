#ifndef SCHEDULE_MANAGE_H
#define SCHEDULE_MANAGE_H

#include "schedule.h"
#include "price.h"

class ScheduleManager {
public:
	ScheduleManager(DBHelper &);

private:
	void addDate();	
	void registerSchedule();
	void checkSchedule();

	void registerPrice(Schedule &);
	void deletePrice(Schedule &);
	void modifySchedule(Schedule &);
		
	DBHelper &dbHelper;
};

#endif // !SCHEDULE_MANAGE_H
#ifndef SCHEDULE_MANAGE_H
#define SCHEDULE_MANAGE_H

#include "schedule.h"
#include "price.h"

class ScheduleManager {
public:
	ScheduleManager(DBHelper &);

private:
	void checkAndDeleteDate();
	void addDate();	
	void checkAndModifySchedule();
	void registerSchedule();
	
	void registerPrice(Schedule &);
	void checkAndDeletePrice(Schedule &);
	void modifySchedule(Schedule &);
		
	DBHelper &dbHelper;
};

#endif // !SCHEDULE_MANAGE_H
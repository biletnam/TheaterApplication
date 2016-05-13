#ifndef SCHEDULE_MANAGE_H
#define SCHEDULE_MANAGE_H

#include "schedule.h"
#include "price.h"

class ScheduleManager {
public:
	ScheduleManager(DBHelper&);

private:
	void addDate();	
	void registerSchedule();
	void registerPrice();
	void checkSchedule();
	void deleteSchedule();
	int16_t deletePrice(Schedule &);
		
	DBHelper dbHelper;
};

#endif // !SCHEDULE_MANAGE_H
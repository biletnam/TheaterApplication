#ifndef SCHEDULE_MANAGE_H
#define SCHEDULE_MANAGE_H

#include "schedule.h"
#include "price.h"

class ScheduleManager {
public:
	ScheduleManager();

private:
	void checkAndDeleteDate();
	void addDate();	
	void checkAndModifySchedule();
	void registerSchedule();
	
	FNRETURN inputDate(Date &);
	void registerPrice(Schedule &);
	void checkAndDeletePrice(Schedule &);
	void modifySchedule(Schedule &);
		
public:
	FNRETURN setSchedule(Schedule & schedule);
};

#endif // !SCHEDULE_MANAGE_H
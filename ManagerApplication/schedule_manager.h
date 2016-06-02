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
	void modifySchedule(Schedule &);
	void deleteSchedule(Schedule &);
	void checkAndDeletePrice(Schedule &);
	void registerPrice(Schedule &);
	
	void registerSchedule();
	void setDate(Date &);
	void setScreen(Screen &);
	void setMovie(Movie &);
	void setTime(Schedule &);
public:
};

#endif // !SCHEDULE_MANAGE_H
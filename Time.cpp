#include "Time.h"

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time(int sec) {

	set_time(0, 0, sec);
}

Time::Time(int min, int sec) {

	set_time(0, min, sec);
}

Time::Time(int hour, int min, int sec) {

	set_time(hour, min, sec);
}

void Time::set_time(int hour, int min, int sec)
{
	if (min < 60 && sec < 60) {
		this->hour = hour;
		this->min = min;
		this->sec = sec;
	}
	else {
		this->hour = 0;
		this->min = 0;
		this->sec = 0;
	}
}

int Time::get_hour() const
{
	return hour;
}

int Time::get_min() const
{
	return min;
}

int Time::get_sec() const
{
	return sec;
}
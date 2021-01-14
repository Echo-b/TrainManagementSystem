#include"HeadFile.h"
TimeType get_time_difference(TimeType start_time, TimeType end_time)
{
	TimeType temp_time_difference;
	if (start_time.hour > end_time.hour)end_time.hour += 24;
	if (end_time.minute < start_time.minute)end_time.hour--, end_time.minute += 60;
	temp_time_difference.hour = end_time.hour - start_time.hour;
	temp_time_difference.minute = end_time.minute - start_time.minute;
	return temp_time_difference;
} 
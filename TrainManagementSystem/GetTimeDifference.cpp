#include"HeadFile.h"
//此函数为计算时间差函数，第一个参数为起始时间（我们定义的结构体），第二个参数为到达时间
//返回时间差（同样是我们定义的时间结构体）
TimeType get_time_difference(TimeType start_time, TimeType end_time)
{
	TimeType temp_time_difference;
	if (start_time.hour > end_time.hour)end_time.hour += 24;
	if (end_time.minute < start_time.minute)end_time.hour--, end_time.minute += 60;
	temp_time_difference.hour = end_time.hour - start_time.hour;
	temp_time_difference.minute = end_time.minute - start_time.minute;
	return temp_time_difference;
} 
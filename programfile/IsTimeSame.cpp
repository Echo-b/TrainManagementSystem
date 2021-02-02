#include"HeadFile.h"
//此函数用于比较时间结构体的参数是否相同
//两个参数都为时间结构体变量
//返回0则不同，返回1则相同
int IsTimeSame(TimeType start_time, TimeType end_time)
{
	TimeType temp_time_difference;
	if (start_time.hour == end_time.hour)
		if (end_time.minute == start_time.minute)return 1;
	return 0;
}
#include"HeadFile.h"
//此函数用来比较日期结构体是否相同
//两个参数都为日期结构体
//返回值，当返回1时相同，返回0时不同
int IsDateSame(DateType date1, DateType date2)
{
	if (date1.year == date2.year)
		if (date1.month == date2.month)
			if (date1.day == date2.day)return 1;
	return 0;
}
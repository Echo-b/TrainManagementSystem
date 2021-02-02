#include"HeadFile.h"
//此函数用于返回当前系统时间
//无参数
//返回值类型为系统时间DateType类型
DateType Get_Sys_Time()       //返回当前系统时间
{
    struct tm today;       //存放时间的结构体
    time_t one;            //存放时间的类型
    DateType now;
    one = time(&one);              //获得系统时间
    today = *(gmtime(&one));       //将time_t格式系统时间转为struct tm格式
    now.year = today.tm_year - 100 + 2000;     //2011年返回111
    now.month = today.tm_mon + 1;           //9月返回8;
    now.day = today.tm_mday;
    return now;
}

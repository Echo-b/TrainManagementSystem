#include"HeadFile.h"
//这个看起来超级简单的函数是用来初始化乘客表的函数
//返回值：int类型，OK为成功，OVERFLOW为内存不足
Status init_passenge_table(PassengerTableType &passenger_table)
{
	if (!(passenger_table.passengers = (Ppassenger)malloc(sizeof(PassengerInf) * MAXLENGTH)))return OVERFLOW;
	passenger_table.num_of_passenger = 0;
	passenger_table.size = MAXLENGTH;
	return OK;
}
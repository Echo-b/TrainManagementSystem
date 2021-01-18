#include"HeadFile.h"
//此函数是简单地初始化火车表，参数为火车表的结构体
//返回值：int类型，当为OK时初始化成功，当为OVERFLOW时初始化失败
Status init_ticket_table(TicketTableType& ticket_table)
{
	if (!(ticket_table.trains_ticket = (Pbook)malloc(sizeof(Book) * MAXLENGTH)))return OVERFLOW;
	ticket_table.num_of_book = 0;
	ticket_table.size = MAXLENGTH;
	return OK;
}
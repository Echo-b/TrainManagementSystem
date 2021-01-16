#include "HeadFile.h"
Pbook* search_realated_TraInf(TicketTableType& ticket_table, char* input_realated_info) {
	//参数为乘客数据表和一个输入的参数，可以是出发时间或者证件号，姓名等，查找成功返回一个结构体指针数组首地址
	int is_final_number = 0;//用于统计匹配人数 
	Pbook ticket_point[10] = { NULL };//声明一个结构体指针数组，用于储存查找结果
	for (int i = 0; i < ticket_table.size; i++) {
		if (strcmp(ticket_table.trains_ticket->id_name, input_realated_info) == 0 || strcmp(ticket_table.trains_ticket->id_number, input_realated_info) == 0
			|| strcmp(ticket_table.trains_ticket->train_name, input_realated_info) == 0 || strcmp(ticket_table.trains_ticket->start_time, input_realated_info) == 0) {
			ticket_point[is_final_number++] = ticket_table.trains_ticket;
		}
	}
	if (is_final_number == 0) {
		outtextxy(0, 0, _T("未找到匹配数据"));//输出位置后期确定
		return NULL;
	}
	return ticket_point;
}
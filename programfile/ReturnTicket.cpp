#include"HeadFile.h"
//该函数为退票函数
//参数为乘客表，火车表，票的表
//返回值默认为OK
Status ReturnTicket(PassengerTableType &passenger_table, TrainTableType &train_table, TicketTableType &ticket_table)
{
	train_information search_train;//火车用于查找的结构体
	init_search_train(search_train);//初始化火车结构体
	PassengerInf search_passenger;//乘客用于查找的结构体
	init_searchtable(search_passenger);//初始化乘客用于查找的结构体
	ticket_information search_ticket;
	InitTicketSearch(search_ticket);
	PtrainInf result_train[MAXLENGTH];//火车查找结果存放处
	Ppassenger result_passenger[MAXLENGTH];//乘客查找结果存放处
	Pbook result_ticket[MAXLENGTH];//票查找结果存放处
	wchar_t tempwchar[50];
	int is_final_number = 0;
	/************************************************************/
	if (InputBox(tempwchar, 50, L"输入你要退票的订单号")) {
		strcpy(search_ticket.order_number, WcharToChar(tempwchar));
		search_realated_TickInf(ticket_table, search_ticket, result_ticket,is_final_number);
		if (InputBox(tempwchar, 50, L"请输入你的姓名")) {
			if (strcmp(result_ticket[0]->id_name, WcharToChar(tempwchar))) {
				strcpy(search_train.train_name, result_ticket[0]->train_name);
				search_realated_TraInf(train_table, search_train, result_train,is_final_number);
				result_train[0]->seat.second_class--;//暂时只支持二等座退票
				*result_ticket[0] = ticket_table.trains_ticket[ticket_table.num_of_book];
				//后续更新增加功能
			}
		}
	}
	return OK;
}
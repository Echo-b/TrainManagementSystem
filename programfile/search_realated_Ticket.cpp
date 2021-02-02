#include "HeadFile.h"
//该函数用于根据信息查找票的函数
//参数为乘客数据表和一个输入的参数，可以是出发时间或者证件号，姓名等，查找成功返回一个结构体指针数组首地址
//返回值为OK查找成功，ERROR查找失败
Status search_realated_TickInf(TicketTableType& ticket_table, Book input_ticket_inf,Pbook *ticket_point,int &is_final_number)
{
	
	TimeType InitTime = { -1,-1 };
	DateType InitDate = { -1,-1,-1 };
	for (int i = 0; i < ticket_table.size; i++) {
		if ((strcmp(ticket_table.trains_ticket[i].id_name, input_ticket_inf.id_name) == 0 ||strcmp(input_ticket_inf.id_name,"\0") )&&
			(strcmp(ticket_table.trains_ticket[i].id_number, input_ticket_inf.id_number) == 0||strcmp(input_ticket_inf.id_number,"\0"))&&
			(strcmp(ticket_table.trains_ticket[i].train_name, input_ticket_inf.train_name) == 0 ||strcmp(input_ticket_inf.train_name,"\0"))&&
			(IsDateSame(InitDate,input_ticket_inf.travel_date)||(IsDateSame(ticket_table.trains_ticket[i].travel_date, input_ticket_inf.travel_date)))&&
			(IsTimeSame(InitTime,input_ticket_inf.start_time)||IsTimeSame(input_ticket_inf.start_time,ticket_table.trains_ticket[i].start_time))&&
			(IsTimeSame(InitTime,input_ticket_inf.arrival_time)||IsTimeSame(input_ticket_inf.arrival_time,ticket_table.trains_ticket[i].arrival_time))){
			ticket_point[is_final_number++] =&ticket_table.trains_ticket[i];
		}
	}
	if (is_final_number == 0) {
		//outtextxy(0, 0, _T("未找到匹配数据"));//todo输出位置后期确定
		return ERROR;
	}
	return OK;
}
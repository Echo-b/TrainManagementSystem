#include"HeadFile.h"
//此函数用于读取票的数据，将数据读入ticket
//此函数有两个参数，第一个为票的表，第二个为文件名
//返回值，返回0时为输入失败，1时为成功
Status TicketReadFile(TicketTableType &ticket_table, const char* file_name,TrainTableType &train_table,PassengerTableType &passenger_table)
{
	FILE* fp;
	fp = fopen(file_name, "r");
	int i = 0;
	int tempnum1, tempnum2;
	while (fscanf(fp, "%s", ticket_table.trains_ticket[i].order_number)!=-1) {
		fscanf(fp, "%4d%2d%2d", &ticket_table.trains_ticket[i].travel_date.year, &ticket_table.trains_ticket[i].travel_date.month, &ticket_table.trains_ticket[i].travel_date.day);//日期输入;
		fscanf(fp, "%s", ticket_table.trains_ticket[i].train_name);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].start_station);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].end_station);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].id_type);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].id_number);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].id_name);
		fscanf(fp, "%d:%d", &ticket_table.trains_ticket[i].start_time.hour, &ticket_table.trains_ticket[i].start_time.minute);
		fscanf(fp, "%d:%d", &ticket_table.trains_ticket[i].arrival_time.hour,&ticket_table.trains_ticket[i].arrival_time.minute);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].seat_level);
		fscanf(fp, "%d", &ticket_table.trains_ticket[i].seat_number);
		fscanf(fp, "%f", &ticket_table.trains_ticket[i].cost);
		ticket_table.num_of_book++;
		/*************************************************/
		/*************************************************/
		/*开始同步*/
		train_information search_train;//火车用于查找的结构体
		init_search_train(search_train);//初始化火车结构体
		PtrainInf result_train[2];//火车查找结果存放处
		Ppassenger result_passenger[2];//乘客查找结果存放处
		PassengerInf search_passenger;//乘客用于查找的结构体
		init_searchtable(search_passenger);//初始化乘客用于查找的结构体
		Ppassenger passenger_temp;
		/*以上都为查找必要的初始化*/
		//strcpy(search_train.train_name, ticket_table.trains_ticket[i].train_name);//对火车的查找进行赋值
		//search_realated_TraInf(train_table, search_train, result_train);//找到该车辆
		//strcpy(search_passenger.id_number, ticket_table.trains_ticket[i].id_number);//对用户的查找条件进行赋值
		//if (search_realated_Pasinf(passenger_table, search_passenger, result_passenger)) {//如果查找到这个人
		//	result_passenger[0]->is_book = 1;//标注此人买票了
		//	strcpy(result_passenger[0]->order_number, ticket_table.trains_ticket[i].order_number);
		//	passenger_temp = result_train[0]->frist_passenger;//后面就是链接乘客
		//	if (passenger_temp == NULL) {
		//		passenger_temp = result_passenger[0];
		//		continue;
		//	}
		//	while (passenger_temp->next != NULL) {
		//		passenger_temp = passenger_temp->next;
		//	}
		//	passenger_temp->next = result_passenger[0];
		//}
		//
		
	}




	fclose(fp);
	return OK;
}
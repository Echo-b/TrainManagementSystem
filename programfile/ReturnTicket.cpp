#include"HeadFile.h"
//�ú���Ϊ��Ʊ����
//����Ϊ�˿ͱ��𳵱�Ʊ�ı�
//����ֵĬ��ΪOK
Status ReturnTicket(PassengerTableType &passenger_table, TrainTableType &train_table, TicketTableType &ticket_table)
{
	train_information search_train;//�����ڲ��ҵĽṹ��
	init_search_train(search_train);//��ʼ���𳵽ṹ��
	PassengerInf search_passenger;//�˿����ڲ��ҵĽṹ��
	init_searchtable(search_passenger);//��ʼ���˿����ڲ��ҵĽṹ��
	ticket_information search_ticket;
	InitTicketSearch(search_ticket);
	PtrainInf result_train[MAXLENGTH];//�𳵲��ҽ����Ŵ�
	Ppassenger result_passenger[MAXLENGTH];//�˿Ͳ��ҽ����Ŵ�
	Pbook result_ticket[MAXLENGTH];//Ʊ���ҽ����Ŵ�
	wchar_t tempwchar[50];
	int is_final_number = 0;
	/************************************************************/
	if (InputBox(tempwchar, 50, L"������Ҫ��Ʊ�Ķ�����")) {
		strcpy(search_ticket.order_number, WcharToChar(tempwchar));
		search_realated_TickInf(ticket_table, search_ticket, result_ticket,is_final_number);
		if (InputBox(tempwchar, 50, L"�������������")) {
			if (strcmp(result_ticket[0]->id_name, WcharToChar(tempwchar))) {
				strcpy(search_train.train_name, result_ticket[0]->train_name);
				search_realated_TraInf(train_table, search_train, result_train,is_final_number);
				result_train[0]->seat.second_class--;//��ʱֻ֧�ֶ�������Ʊ
				*result_ticket[0] = ticket_table.trains_ticket[ticket_table.num_of_book];
				//�����������ӹ���
			}
		}
	}
	return OK;
}
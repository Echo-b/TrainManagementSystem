#include"HeadFile.h"
//�˺���������ʼ��Ʊ�Ľṹ��
//�������ΪƱ�Ľṹ�壬��Ըò��������޸�
//�ݶ�����ֵΪOK
Status InitTicketSearch(ticket_information& ticket)
{
	ticket.arrival_time = { -1,-1 };
	ticket.cost = -1;
	strcpy(ticket.end_station, "\0");
	strcpy(ticket.id_name, "\0");
	strcpy(ticket.id_number, "\0");
	strcpy(ticket.id_type, "\0");
	strcpy(ticket.order_number, "\0");
	strcpy(ticket.seat_level, "\0");
	ticket.seat_number=-1;
	strcpy(ticket.start_station, "\0");
	strcpy(ticket.train_name, "\0");
	ticket.start_time = { -1,-1 };
	ticket.travel_date = { -1,-1,-1 };
	return OK;
}
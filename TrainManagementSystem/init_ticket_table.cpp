#include"HeadFile.h"
//�˺����Ǽ򵥵س�ʼ���𳵱�����Ϊ�𳵱�Ľṹ��
//����ֵ��int���ͣ���ΪOKʱ��ʼ���ɹ�����ΪOVERFLOWʱ��ʼ��ʧ��
Status init_ticket_table(TicketTableType& ticket_table)
{
	if (!(ticket_table.trains_ticket = (Pbook)malloc(sizeof(Book) * MAXLENGTH)))return OVERFLOW;
	ticket_table.num_of_book = 0;
	ticket_table.size = MAXLENGTH;
	return OK;
}
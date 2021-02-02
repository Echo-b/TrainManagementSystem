#include "HeadFile.h"
//�˺���Ϊ�û������溯��
//�޲���
//����0ʱ�˳�����������1ʱ������һ��
Status PassengerUser()
{
	PassengerTableType passenger_table;
	TrainTableType train_table;
	TicketTableType ticket_table;

	init_passenge_table(passenger_table);								   //���г˿ͳ�ʼ��
	init_train_table(train_table);										   //���л𳵱�ĳ�ʼ��
	passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //�˿ͱ���ļ�����
	train_read_file(train_table, "DataAndExample\\train");				   //�𳵱���ļ�����
	init_ticket_table(ticket_table);
	TicketReadFile(ticket_table, "DataAndExample\\booking.txt", train_table, passenger_table);
	IMAGE manager_face;
	loadimage(&manager_face, L"Image\\usermainfounction.png", WIDTH, HEIGHT);
	putimage(0, 0, &manager_face); //���Ϸ���
	MOUSEMSG mouse;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			mouse = GetMouseMsg();
			printf("PassengerUser: x=%d,y=%d,%d\n", mouse.x, mouse.y, mouse.uMsg);
			if (WM_LBUTTONDOWN == mouse.uMsg)
			{
				if (mouse.x > 503 /*position*/ && mouse.x < 777 /*position*/ && mouse.y > 173 /*position*/ && mouse.y < 260 /*position*/)
				{
					//BookTicket(passenger_table, train_table, ticket_table); //��Ʊ
				}
				else if (mouse.x > 223 /*position*/ && mouse.x < 493 /*position*/ && mouse.y > 329 /*position*/ && mouse.y < 416 /*position*/)
				{
					ReturnTicket(passenger_table, train_table, ticket_table); //��Ʊ
				}
				else if (mouse.x > 223 /*position*/ && mouse.x < 493 /*position*/ && mouse.y > 545 /*position*/ && mouse.y < 625 /*position*/)
				{
					SearchInf(train_table, passenger_table, ticket_table, 2); //������Ϣ����
				}
				else if (mouse.x > 794 /*position*/ && mouse.x < 1059 /*position*/ && mouse.y > 329 /*position*/ && mouse.y < 416 /*position*/)
				{
					ModifyPasInf(passenger_table); //�޸���Ϣ
				}
				else if (mouse.x > 794 /*position*/ && mouse.x < 1059 /*position*/ && mouse.y > 545 /*position*/ && mouse.y < 625 /*position*/)
				{
					ticket_write_file(ticket_table, "DataAndExample\\book.txt");		   //Ʊ�ı��ļ�д��
					passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //�˿ͱ��ļ�д��
					TrainWriteFile(train_table, "DataAndExample\\train.txt");			   //�𳵱��ļ�д��
					return 0;															   //�˳�����
				}
				else if (mouse.x > 0 /*position*/ && mouse.x < 0 /*position*/ && mouse.y > 0 /*position*/ && mouse.y < 0 /*position*/)
				{
					ticket_write_file(ticket_table, "DataAndExample\\book.txt");		   //Ʊ�ı��ļ�д��
					passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //�˿ͱ��ļ�д��
					TrainWriteFile(train_table, "DataAndExample\\train.txt");			   //�𳵱��ļ�д��
					return 1;															   //������һ��
				}
				else if (mouse.x > 0 /*position*/ && mouse.x < 0 /*position*/ && mouse.y > 0 /*position*/ && mouse.y < 0 /*position*/)
				{
					GetTrainInf(train_table); //��ó������г���Ϣ
				}
			}
		}
	}
}
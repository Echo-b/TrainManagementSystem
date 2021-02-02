#include "HeadFile.h"
//此函数为用户主界面函数
//无参数
//返回0时退出函数，返回1时返回上一级
Status PassengerUser()
{
	PassengerTableType passenger_table;
	TrainTableType train_table;
	TicketTableType ticket_table;

	init_passenge_table(passenger_table);								   //进行乘客初始化
	init_train_table(train_table);										   //进行火车表的初始化
	passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //乘客表的文件输入
	train_read_file(train_table, "DataAndExample\\train");				   //火车表的文件输入
	init_ticket_table(ticket_table);
	TicketReadFile(ticket_table, "DataAndExample\\booking.txt", train_table, passenger_table);
	IMAGE manager_face;
	loadimage(&manager_face, L"Image\\usermainfounction.png", WIDTH, HEIGHT);
	putimage(0, 0, &manager_face); //放上封面
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
					//BookTicket(passenger_table, train_table, ticket_table); //订票
				}
				else if (mouse.x > 223 /*position*/ && mouse.x < 493 /*position*/ && mouse.y > 329 /*position*/ && mouse.y < 416 /*position*/)
				{
					ReturnTicket(passenger_table, train_table, ticket_table); //退票
				}
				else if (mouse.x > 223 /*position*/ && mouse.x < 493 /*position*/ && mouse.y > 545 /*position*/ && mouse.y < 625 /*position*/)
				{
					SearchInf(train_table, passenger_table, ticket_table, 2); //根据信息查找
				}
				else if (mouse.x > 794 /*position*/ && mouse.x < 1059 /*position*/ && mouse.y > 329 /*position*/ && mouse.y < 416 /*position*/)
				{
					ModifyPasInf(passenger_table); //修改信息
				}
				else if (mouse.x > 794 /*position*/ && mouse.x < 1059 /*position*/ && mouse.y > 545 /*position*/ && mouse.y < 625 /*position*/)
				{
					ticket_write_file(ticket_table, "DataAndExample\\book.txt");		   //票的表文件写入
					passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //乘客表文件写入
					TrainWriteFile(train_table, "DataAndExample\\train.txt");			   //火车表文件写入
					return 0;															   //退出程序
				}
				else if (mouse.x > 0 /*position*/ && mouse.x < 0 /*position*/ && mouse.y > 0 /*position*/ && mouse.y < 0 /*position*/)
				{
					ticket_write_file(ticket_table, "DataAndExample\\book.txt");		   //票的表文件写入
					passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //乘客表文件写入
					TrainWriteFile(train_table, "DataAndExample\\train.txt");			   //火车表文件写入
					return 1;															   //返回上一级
				}
				else if (mouse.x > 0 /*position*/ && mouse.x < 0 /*position*/ && mouse.y > 0 /*position*/ && mouse.y < 0 /*position*/)
				{
					GetTrainInf(train_table); //获得乘坐的列车信息
				}
			}
		}
	}
}
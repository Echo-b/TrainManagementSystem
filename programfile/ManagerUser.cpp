#include "HeadFile.h"
//此函数为管理员主页面的函数
//暂无参数
//返回0退出程序，返回其他都是重新进入选择函数
Status ManagerUser()
{
	PassengerTableType passenger_table;
	TrainTableType train_table;
	TicketTableType ticket_table;
	init_passenge_table(passenger_table);								   //进行乘客初始化
	init_train_table(train_table);										   //进行火车表的初始化
	passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //乘客表的文件输入
	train_read_file(train_table, "DataAndExample\\train.txt");				   //火车表的文件输入
	init_ticket_table(ticket_table); 
	TicketReadFile(ticket_table, "DataAndExample\\booking.txt", train_table, passenger_table);
	IMAGE manager_face;
	loadimage(&manager_face, L"Image\\mangerfunction.jpg", WIDTH, HEIGHT);
	
	MOUSEMSG mouse;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			putimage(0, 0, &manager_face); //放上封面
			mouse = GetMouseMsg();
			if (WM_LBUTTONDOWN == mouse.uMsg)
			{
				if (mouse.x > 194 /*position*/ && mouse.x < 435 /*position*/ && mouse.y > 133 /*position*/ && mouse.y < 209 /*position*/)
				{
					AddTrain(train_table); //增加一列车
				}
				else if (mouse.x > 194 /*position*/ && mouse.x < 435 /*position*/ && mouse.y > 263 /*position*/ && mouse.y < 337 /*position*/)
				{
					StopTrain(train_table); //停开一辆车
				}
				else if (mouse.x > 194 /*position*/ && mouse.x < 435 /*position*/ && mouse.y > 401 /*position*/ && mouse.y < 472 /*position*/)
				{
					SearchInf(train_table, passenger_table, ticket_table, 1); //根据信息查找
				}
				else if (mouse.x > 732 /*position*/ && mouse.x < 969 /*position*/ && mouse.y > 133 /*position*/ && mouse.y < 209 /*position*/)
				{
					//ModifyInf(train_table); //修改火车信息
				}
				else if (mouse.x > 1134 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 660 /*position*/ && mouse.y < 720 /*position*/)
				{
					ticket_write_file(ticket_table, "DataAndExample\\book.txt");		   //票的表文件写入
					passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //乘客表文件写入
					TrainWriteFile(train_table, "DataAndExample\\train.txt");			   //火车表文件写入
					return 0;															   //退出程序
				}
				else if (mouse.x > 0 /*position*/ && mouse.x < 110 /*position*/ && mouse.y > 660 /*position*/ && mouse.y < 720 /*position*/)
				{
					ticket_write_file(ticket_table, "DataAndExample\\book.txt");		   //票的表文件写入
					passenger_read_file(passenger_table, "DataAndExample\\passenger.txt"); //乘客表文件写入
					TrainWriteFile(train_table, "DataAndExample\\train.txt");			   //火车表文件写入
					return 1;															   //返回上一级
				}
				else if (mouse.x > 732 /*position*/ && mouse.x < 969 /*position*/ && mouse.y > 263 /*position*/ && mouse.y < 337 /*position*/)
				{
					DeletePassenger(passenger_table); //删除乘客函数
				}
				else if (mouse.x > 732 /*position*/ && mouse.x < 969 /*position*/ && mouse.y > 401 /*position*/ && mouse.y < 472 /*position*/)
				{
					AddPassenger(passenger_table); //增加乘客函数
				}
			}
		}
	}
}
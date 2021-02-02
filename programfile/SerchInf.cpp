#include "HeadFile.h"
//该函数是选择查找的函数
//参数为火车表，乘客表和票的表,和身份信息(1代表管理员，2代表乘客，若需要修改则修改输入参数和下面标注身份的变量
//返回值：暂时只许成功返回OK
Status SearchInf(TrainTableType train_table, PassengerTableType passenger_table, TicketTableType ticket_table, int User)
{
	const int pas_type = 2;	 //乘客标识
	const int mana_type = 1; //管理员标识
	int  is_final_number = 0;//计算查找的匹配人数
	/***********************************************************/
	train_information search_train;		//火车用于查找的结构体
	init_search_train(search_train);	//初始化火车结构体
	PassengerInf search_passenger;		//乘客用于查找的结构体
	init_searchtable(search_passenger); //初始化乘客用于查找的结构体
	ticket_information search_ticket;
	InitTicketSearch(search_ticket);
	PtrainInf result_train[MAXLENGTH];		//火车查找结果存放处
	Ppassenger result_passenger[MAXLENGTH]; //乘客查找结果存放处
	Pbook result_ticket[MAXLENGTH];			//票查找结果存放处
	wchar_t tempwchar[20];
	MOUSEMSG mouse;
	FlushMouseMsgBuffer();
	IMAGE ChooseSearch;
	IMAGE pas_choose_face;
	IMAGE tra_choose_face;
	IMAGE tic_choose_face;
	loadimage(&ChooseSearch, L"Image\\choosesearchway.jpg", WIDTH, HEIGHT);
	loadimage(&pas_choose_face, L"Image\\searchpassenger.jpg", WIDTH, HEIGHT);
	loadimage(&tic_choose_face, L"Image\\searchticket.jpg", WIDTH, HEIGHT);
	loadimage(&tra_choose_face, L"Image\\searchtrain.jpg", WIDTH, HEIGHT);
	int quit_flag1 = 0;
	int quit_flag2 = 0;
	/***********************************************************/
	while (true)
	{
		putimage(0, 0, &ChooseSearch);
		while (MouseHit)
		{
			if (quit_flag1 == 1)
				break;
			quit_flag2 = 0;
			mouse = GetMouseMsg();
			printf("SearchInf: x=%d,y=%d,%d\n", mouse.x, mouse.y, mouse.uMsg);
			if (WM_LBUTTONDOWN == mouse.uMsg)
			{
				/*************************************************************************************************/
				if (mouse.x > 528 /*position*/ && mouse.x < 687 /*position*/ && mouse.y > 175 /*position*/ && mouse.y < 247 /*position*/)
				{
					//乘客搜索选择输入
					FlushMouseMsgBuffer();
					while (true)
					{
						if (quit_flag2 == 1)
							break;
						putimage(0, 0, &pas_choose_face);
						while (MouseHit)
						{
							mouse = GetMouseMsg();
							printf("passengerSearch: x=%d,y=%d,%d\n", mouse.x, mouse.y, mouse.uMsg);
							if (WM_LBUTTONDOWN == mouse.uMsg)
							{
								if (mouse.x > 120 /*position*/ && mouse.x < 373 /*position*/ && mouse.y > 160 /*position*/ && mouse.y < 250 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的姓名"))
									{ //当输入姓名时
										strcpy(search_passenger.id_name, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 120 /*position*/ && mouse.x < 373 /*position*/ && mouse.y > 333 /*position*/ && mouse.y < 420 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找联系电话"))
									{ //查找联系电话
										strcpy(search_passenger.tel_nunmber, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 120 /*position*/ && mouse.x < 373 /*position*/ && mouse.y > 500 /*position*/ && mouse.y < 587 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的证件类型"))
									{ //查找的证件类型
										strcpy(search_passenger.id_type, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1079 /*position*/ && mouse.y > 160 /*position*/ && mouse.y < 250 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的身份证号"))
									{ //查找的身份证号
										strcpy(search_passenger.id_number, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1079 /*position*/ && mouse.y > 333 /*position*/ && mouse.y < 420 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的紧急联系人"))
									{ //查找的紧急联系人
										strcpy(search_passenger.emergency_contact, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1079 /*position*/ && mouse.y > 500 /*position*/ && mouse.y < 587 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的紧急联系人电话"))
									{ //紧急联系人电话
										strcpy(search_passenger.emergency_contact_tel, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 1167 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 647 /*position*/ && mouse.y < 720 /*position*/)
								{
									
									search_realated_Pasinf(passenger_table, search_passenger, result_passenger,is_final_number); //摁下确定
									if(is_final_number==0)
										passenger_output(passenger_table);
									else
										passenger_search_print(result_passenger,is_final_number);								 //todo显示结果
								}
								else if (mouse.x > 0 /*position*/ && mouse.x < 116 /*position*/ && mouse.y > 644 /*position*/ && mouse.y < 720 /*position*/)
								{
									quit_flag2 = 1;
									break; //摁下退出
								}
							}
						}
					}
				}
				/*************************************************************************************************/
				else if (mouse.x > 528 /*position*/ && mouse.x < 683 /*position*/ && mouse.y > 348 /*position*/ && mouse.y < 418 /*position*/)
				{
					putimage(0, 0, &tra_choose_face);
					FlushMouseMsgBuffer();
					while (true)
					{ //火车搜索
						while (MouseHit)
						{
							mouse = GetMouseMsg();
							printf("trainSearch: x=%d,y=%d,%d\n", mouse.x, mouse.y, mouse.uMsg);
							if (WM_LBUTTONDOWN == mouse.uMsg)
							{
								if (mouse.x > 141 /*position*/ && mouse.x < 452 /*position*/ && mouse.y > 138 /*position*/ && mouse.y < 248 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的车次"))
									{ //当输入车次时
										strcpy(search_train.train_name, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 141 /*position*/ && mouse.x < 452 /*position*/ && mouse.y > 290 /*position*/ && mouse.y < 404 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的起始站"))
									{ //查找的起始站
										strcpy(search_train.start_station, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 141 /*position*/ && mouse.x < 452 /*position*/ && mouse.y > 454 /*position*/ && mouse.y < 571 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的终点站"))
									{ //查找的终点站
										strcpy(search_train.end_station, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 767 /*position*/ && mouse.x < 1080 /*position*/ && mouse.y > 138 /*position*/ && mouse.y < 248 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的出发时间（小时）"))
									{ //查找的出发时间
										search_train.start_time.hour = _wtoi(tempwchar);
										if (InputBox(tempwchar, 20, L"请输入你要查找的出发时间（分钟）"))
										{
											search_train.start_time.minute = _wtoi(tempwchar);
										}
									}
								}
								else if (mouse.x > 767 /*position*/ && mouse.x < 1080 /*position*/ && mouse.y > 290 /*position*/ && mouse.y < 404 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的到达时间（小时）"))
									{ //查找的到达时间
										search_train.arrival_time.hour = _wtoi(tempwchar);
										if (InputBox(tempwchar, 20, L"请输入你要查找的到达时间（分钟）"))
										{
											search_train.arrival_time.minute = _wtoi(tempwchar);
										}
									}
								}
								else if (mouse.x > 767 /*position*/ && mouse.x < 1080 /*position*/ && mouse.y > 454 /*position*/ && mouse.y < 571 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入你要查找的火车状态"))
									{ //查找的火车状态
										strcpy(search_train.train_status, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 1163 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 613 /*position*/ && mouse.y < 720 /*position*/)
								{
									search_realated_TraInf(train_table, search_train, result_train,is_final_number); //摁下确定
									if(is_final_number==0)
										train_output(train_table);	//todo增加输出函数（火车查找后信息输出）
									else
										train_search_print(result_train,is_final_number);
									
								}
								else if (mouse.x > 0 /*position*/ && mouse.x < 156 /*position*/ && mouse.y > 625 /*position*/ && mouse.y < 720 /*position*/)
								{
									quit_flag2 = 1; //摁下退出
									break;
								}
							}
						}
					}
				}
				/*************************************************************************************************/
				else if (mouse.x > 536 /*position*/ && mouse.x < 685 /*position*/ && mouse.y > 527 /*position*/ && mouse.y < 595 /*position*/)
				{
					//票的查找
					putimage(0, 0, &tic_choose_face);
					FlushMouseMsgBuffer();
					while (true)
					{
						while (MouseHit())
						{
							mouse = GetMouseMsg();
							printf("ticketSearch: x=%d,y=%d,%d\n", mouse.x, mouse.y, mouse.uMsg);
							if (WM_LBUTTONDOWN == mouse.uMsg)
							{
								if (mouse.x > 129 /*position*/ && mouse.x < 369 /*position*/ && mouse.y > 162 /*position*/ && mouse.y < 252 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入要查找的订单号"))
									{
										strcpy(search_ticket.order_number, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 129 /*position*/ && mouse.x < 369 /*position*/ && mouse.y > 330 /*position*/ && mouse.y < 420 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入要查找的姓名"))
									{
										strcpy(search_ticket.id_name, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 129 /*position*/ && mouse.x < 369 /*position*/ && mouse.y > 504 /*position*/ && mouse.y < 587 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入要查找的证件号"))
									{
										search_ticket.seat_number = _wtoi(tempwchar);
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1077 /*position*/ && mouse.y > 162 /*position*/ && mouse.y < 252 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入要查找的车次"))
									{
										strcpy(search_ticket.train_name, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1077 /*position*/ && mouse.y > 330 /*position*/ && mouse.y < 420 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"请输入要查找的出发时间（年）"))
									{
										search_ticket.travel_date.year = _wtoi(tempwchar);
										if (InputBox(tempwchar, 20, L"请输入要查找的出发时间（月）"))
										{
											search_ticket.travel_date.month = _wtoi(tempwchar);
											if (InputBox(tempwchar, 20, L"请输入要查找的出发时间（日）"))
											{
												search_ticket.travel_date.day = _wtoi(tempwchar);
											}
										}
									}
								}
								else if (mouse.x > 1154 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 650 /*position*/ && mouse.y < 720 /*position*/)
								{
									search_realated_TickInf(ticket_table, search_ticket, result_ticket,is_final_number);
									if(is_final_number==0)
										ticket_output(ticket_table);//todo增加显示结果的函数
									else
										ticket_search_print(result_ticket,is_final_number);
									
								}
								else if (mouse.x > 0 /*position*/ && mouse.x < 128 /*position*/ && mouse.y > 650 /*position*/ && mouse.y < 720 /*position*/)
								{
									quit_flag2 = 1; //摁下退出
									break;
								}
							}
						}
					}
				}
				/*************************************************************************************************/
				else if (mouse.x > 1173 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 650 /*position*/ && mouse.y < 720 /*position*/)
				{
					quit_flag1 = 1;
					break;
				}
			}
		}
	}
}
#include "HeadFile.h"
//�ú�����ѡ����ҵĺ���
//����Ϊ�𳵱��˿ͱ��Ʊ�ı�,�������Ϣ(1�������Ա��2����˿ͣ�����Ҫ�޸����޸���������������ע��ݵı���
//����ֵ����ʱֻ��ɹ�����OK
Status SearchInf(TrainTableType train_table, PassengerTableType passenger_table, TicketTableType ticket_table, int User)
{
	const int pas_type = 2;	 //�˿ͱ�ʶ
	const int mana_type = 1; //����Ա��ʶ
	int  is_final_number = 0;//������ҵ�ƥ������
	/***********************************************************/
	train_information search_train;		//�����ڲ��ҵĽṹ��
	init_search_train(search_train);	//��ʼ���𳵽ṹ��
	PassengerInf search_passenger;		//�˿����ڲ��ҵĽṹ��
	init_searchtable(search_passenger); //��ʼ���˿����ڲ��ҵĽṹ��
	ticket_information search_ticket;
	InitTicketSearch(search_ticket);
	PtrainInf result_train[MAXLENGTH];		//�𳵲��ҽ����Ŵ�
	Ppassenger result_passenger[MAXLENGTH]; //�˿Ͳ��ҽ����Ŵ�
	Pbook result_ticket[MAXLENGTH];			//Ʊ���ҽ����Ŵ�
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
					//�˿�����ѡ������
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
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵ�����"))
									{ //����������ʱ
										strcpy(search_passenger.id_name, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 120 /*position*/ && mouse.x < 373 /*position*/ && mouse.y > 333 /*position*/ && mouse.y < 420 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ������ϵ�绰"))
									{ //������ϵ�绰
										strcpy(search_passenger.tel_nunmber, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 120 /*position*/ && mouse.x < 373 /*position*/ && mouse.y > 500 /*position*/ && mouse.y < 587 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵ�֤������"))
									{ //���ҵ�֤������
										strcpy(search_passenger.id_type, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1079 /*position*/ && mouse.y > 160 /*position*/ && mouse.y < 250 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵ����֤��"))
									{ //���ҵ����֤��
										strcpy(search_passenger.id_number, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1079 /*position*/ && mouse.y > 333 /*position*/ && mouse.y < 420 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵĽ�����ϵ��"))
									{ //���ҵĽ�����ϵ��
										strcpy(search_passenger.emergency_contact, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1079 /*position*/ && mouse.y > 500 /*position*/ && mouse.y < 587 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵĽ�����ϵ�˵绰"))
									{ //������ϵ�˵绰
										strcpy(search_passenger.emergency_contact_tel, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 1167 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 647 /*position*/ && mouse.y < 720 /*position*/)
								{
									
									search_realated_Pasinf(passenger_table, search_passenger, result_passenger,is_final_number); //����ȷ��
									if(is_final_number==0)
										passenger_output(passenger_table);
									else
										passenger_search_print(result_passenger,is_final_number);								 //todo��ʾ���
								}
								else if (mouse.x > 0 /*position*/ && mouse.x < 116 /*position*/ && mouse.y > 644 /*position*/ && mouse.y < 720 /*position*/)
								{
									quit_flag2 = 1;
									break; //�����˳�
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
					{ //������
						while (MouseHit)
						{
							mouse = GetMouseMsg();
							printf("trainSearch: x=%d,y=%d,%d\n", mouse.x, mouse.y, mouse.uMsg);
							if (WM_LBUTTONDOWN == mouse.uMsg)
							{
								if (mouse.x > 141 /*position*/ && mouse.x < 452 /*position*/ && mouse.y > 138 /*position*/ && mouse.y < 248 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵĳ���"))
									{ //�����복��ʱ
										strcpy(search_train.train_name, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 141 /*position*/ && mouse.x < 452 /*position*/ && mouse.y > 290 /*position*/ && mouse.y < 404 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵ���ʼվ"))
									{ //���ҵ���ʼվ
										strcpy(search_train.start_station, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 141 /*position*/ && mouse.x < 452 /*position*/ && mouse.y > 454 /*position*/ && mouse.y < 571 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵ��յ�վ"))
									{ //���ҵ��յ�վ
										strcpy(search_train.end_station, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 767 /*position*/ && mouse.x < 1080 /*position*/ && mouse.y > 138 /*position*/ && mouse.y < 248 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵĳ���ʱ�䣨Сʱ��"))
									{ //���ҵĳ���ʱ��
										search_train.start_time.hour = _wtoi(tempwchar);
										if (InputBox(tempwchar, 20, L"��������Ҫ���ҵĳ���ʱ�䣨���ӣ�"))
										{
											search_train.start_time.minute = _wtoi(tempwchar);
										}
									}
								}
								else if (mouse.x > 767 /*position*/ && mouse.x < 1080 /*position*/ && mouse.y > 290 /*position*/ && mouse.y < 404 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵĵ���ʱ�䣨Сʱ��"))
									{ //���ҵĵ���ʱ��
										search_train.arrival_time.hour = _wtoi(tempwchar);
										if (InputBox(tempwchar, 20, L"��������Ҫ���ҵĵ���ʱ�䣨���ӣ�"))
										{
											search_train.arrival_time.minute = _wtoi(tempwchar);
										}
									}
								}
								else if (mouse.x > 767 /*position*/ && mouse.x < 1080 /*position*/ && mouse.y > 454 /*position*/ && mouse.y < 571 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"��������Ҫ���ҵĻ�״̬"))
									{ //���ҵĻ�״̬
										strcpy(search_train.train_status, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 1163 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 613 /*position*/ && mouse.y < 720 /*position*/)
								{
									search_realated_TraInf(train_table, search_train, result_train,is_final_number); //����ȷ��
									if(is_final_number==0)
										train_output(train_table);	//todo��������������𳵲��Һ���Ϣ�����
									else
										train_search_print(result_train,is_final_number);
									
								}
								else if (mouse.x > 0 /*position*/ && mouse.x < 156 /*position*/ && mouse.y > 625 /*position*/ && mouse.y < 720 /*position*/)
								{
									quit_flag2 = 1; //�����˳�
									break;
								}
							}
						}
					}
				}
				/*************************************************************************************************/
				else if (mouse.x > 536 /*position*/ && mouse.x < 685 /*position*/ && mouse.y > 527 /*position*/ && mouse.y < 595 /*position*/)
				{
					//Ʊ�Ĳ���
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
									if (InputBox(tempwchar, 20, L"������Ҫ���ҵĶ�����"))
									{
										strcpy(search_ticket.order_number, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 129 /*position*/ && mouse.x < 369 /*position*/ && mouse.y > 330 /*position*/ && mouse.y < 420 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"������Ҫ���ҵ�����"))
									{
										strcpy(search_ticket.id_name, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 129 /*position*/ && mouse.x < 369 /*position*/ && mouse.y > 504 /*position*/ && mouse.y < 587 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"������Ҫ���ҵ�֤����"))
									{
										search_ticket.seat_number = _wtoi(tempwchar);
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1077 /*position*/ && mouse.y > 162 /*position*/ && mouse.y < 252 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"������Ҫ���ҵĳ���"))
									{
										strcpy(search_ticket.train_name, WcharToChar(tempwchar));
									}
								}
								else if (mouse.x > 839 /*position*/ && mouse.x < 1077 /*position*/ && mouse.y > 330 /*position*/ && mouse.y < 420 /*position*/)
								{
									if (InputBox(tempwchar, 20, L"������Ҫ���ҵĳ���ʱ�䣨�꣩"))
									{
										search_ticket.travel_date.year = _wtoi(tempwchar);
										if (InputBox(tempwchar, 20, L"������Ҫ���ҵĳ���ʱ�䣨�£�"))
										{
											search_ticket.travel_date.month = _wtoi(tempwchar);
											if (InputBox(tempwchar, 20, L"������Ҫ���ҵĳ���ʱ�䣨�գ�"))
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
										ticket_output(ticket_table);//todo������ʾ����ĺ���
									else
										ticket_search_print(result_ticket,is_final_number);
									
								}
								else if (mouse.x > 0 /*position*/ && mouse.x < 128 /*position*/ && mouse.y > 650 /*position*/ && mouse.y < 720 /*position*/)
								{
									quit_flag2 = 1; //�����˳�
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
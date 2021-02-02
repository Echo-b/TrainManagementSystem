#include"HeadFile.h"
//�ú���Ϊ���ӳ��εĺ���
//����Ϊ�𳵱�
//����ֵΪ1
Status AddTrain(TrainTableType &train_table)
{
	train_information train_temp;
	init_search_train(train_temp);
	wchar_t tempwchar1[MAXLENGTH];
	wchar_t tempwchar2[MAXLENGTH];
	MOUSEMSG mouse;
	FlushMouseMsgBuffer();
	IMAGE addtrain;
	loadimage(&addtrain, L"Image\\addtrain.jpg",WIDTH,HEIGHT);
	while (true) {
		putimage(0, 0, &addtrain);
		while (MouseHit()) {
			mouse = GetMouseMsg();
			if (WM_LBUTTONDOWN == mouse.uMsg) {
				if (mouse.x > 250/*position*/ && mouse.x < 411/*position*/ && mouse.y>144/*position*/ && mouse.y < 212/*position*/) {//������복��ʱ
					if (InputBox(tempwchar1, MAXLENGTH, L"��������Ҫ���ӵĳ���", 0, 0, false)) {
						strcpy(train_temp.train_name, WcharToChar(tempwchar1));
					}

				}
				else if (mouse.x > 250/*position*/ && mouse.x < 411/*position*/ && mouse.y>290/*position*/ && mouse.y < 360/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"��������Ҫ������ʼվ", 0, 0, false)) {
						strcpy(train_temp.start_station, WcharToChar(tempwchar1));
					}
					if (InputBox(tempwchar1, MAXLENGTH, L"��������Ҫ�����յ�վ", 0, 0, false)) {
						strcpy(train_temp.end_station, WcharToChar(tempwchar1));
					}
				}
				else if (mouse.x > 250/*position*/ && mouse.x < 411/*position*/ && mouse.y>430/*position*/ && mouse.y < 504/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"���������", 0, 0, false)) {
						train_temp.total_distance = _wtoi(tempwchar1);
					}
				}
				else if (mouse.x > 250/*position*/ && mouse.x < 411/*position*/ && mouse.y>556/*position*/ && mouse.y < 624/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"��������г���״̬", 0, 0, false)) {
						strcpy(train_temp.train_status, WcharToChar(tempwchar1));
					}
				}
				else if (mouse.x > 844/*position*/ && mouse.x < 1000/*position*/ && mouse.y>142/*position*/ && mouse.y < 212/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"�����뼸����������Ӻ������룩", 0, 0, false)) {
						train_temp.start_time.hour = _wtoi(tempwchar1);
						if (InputBox(tempwchar1, MAXLENGTH, L"�����뼸�ֳ�����������Ĭ��0��", 0, 0, false)) {
							train_temp.start_time.minute = _wtoi(tempwchar1);
						}
					}
					if (InputBox(tempwchar1, MAXLENGTH, L"�����뼸�㵽�յ�վ�����Ӻ������룩", 0, 0, false)) {
						train_temp.arrival_time.hour = _wtoi(tempwchar1);
						if (InputBox(tempwchar1, MAXLENGTH, L"�����뼸�ֵ��յ�վ��������Ĭ��0��", 0, 0, false)) {
							train_temp.arrival_time.minute = _wtoi(tempwchar1);
						}
					}
				}
				else if (mouse.x > 844/*position*/ && mouse.x < 1000/*position*/ && mouse.y>290/*position*/ && mouse.y < 356/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"������ͣ��վ����(����˺�ſ�����ͣ��վ��Ϣ��", 0, 0, false)) {
						train_temp.stop_station_number = _wtoi(tempwchar1);
					}
				}
				else if (mouse.x > 844/*position*/ && mouse.x < 1000/*position*/ && mouse.y>430/*position*/ && mouse.y < 502/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"�������ص���������������Ĭ��Ϊ0��", 0, 0, false)) {
						train_temp.seat.special = _wtoi(tempwchar1);
					}
					if (InputBox(tempwchar1, MAXLENGTH, L"������һ����������������Ĭ��Ϊ0��", 0, 0, false)) {
						train_temp.seat.first_class = _wtoi(tempwchar1);
					}
					if (InputBox(tempwchar1, MAXLENGTH, L"�����������������������Ĭ��Ϊ0��", 0, 0, false)) {
						train_temp.seat.second_class = _wtoi(tempwchar1);
					}
				}
				else if (mouse.x > 844/*position*/ && mouse.x < 1000/*position*/ && mouse.y>554/*position*/ && mouse.y < 626/*position*/) {
					if (train_temp.stop_station_number == 0) {
						//todo��ʾ��������ͣ��վ����
						sprintf(WcharToChar(tempwchar2), "%d", train_temp.stop_station_number);
						MessageBox(NULL,tempwchar2, _T("ͣ��վ����"), MB_OKCANCEL);
						continue;
					}
					PStopStation tempnow = NULL, tempnext = NULL;
					wcscpy(tempwchar2, L"ͣ��վ1��Ϣ����:ͣ��վ����");
					for (int i = 0; i < train_temp.stop_station_number; i++) {
						tempnext = (PStopStation)malloc(sizeof(StopStationType));
						InputBox(tempwchar1, MAXLENGTH, tempwchar2, 0, 0, false);
						strcpy(tempnext->stop_station, WcharToChar(tempwchar1));
						InputBox(tempwchar1,MAXLENGTH, L"�����ʱ�䣨Сʱ��", 0, 0, false);
						tempnext->arrival_time.hour = _wtoi(tempwchar1);
						InputBox(tempwchar1,MAXLENGTH, L"�����ʱ�䣨���ӣ�", 0, 0, false);
						tempnext->arrival_time.minute = _wtoi(tempwchar1);
						InputBox(tempwchar1,MAXLENGTH, L"������ʱ�䣨Сʱ��", 0, 0, false);
						tempnext->start_time.hour = _wtoi(tempwchar1);
						InputBox(tempwchar1,MAXLENGTH, L"������ʱ�䣨���ӣ�", 0, 0, false);
						tempnext->start_time.minute = _wtoi(tempwchar1);
						InputBox(tempwchar1,MAXLENGTH, L"�����", 0, 0, false);
						tempnext->total_distance= _wtoi(tempwchar1);
						tempwchar2[3]++;
						if (i == 0) {
							train_temp.first_stop_station = tempnext;
							tempnow = tempnext;
							tempnow->next_station = NULL;
							continue;
						}

						tempnow->next_station = tempnext;
						tempnow = tempnext;
						tempnow->next_station = NULL;
					}
				}
				else if (mouse.x > 1173/*position*/ && mouse.x < 1280/*position*/ && mouse.y>654/*position*/ && mouse.y < 720/*position*/) {
					train_table.trains[train_table.num_of_train] = train_temp;//��ȷ����
					train_table.num_of_train++;
					//todo��ʾ��ӳɹ�
					MessageBox(NULL, _T("��ӳɹ�"), _T("���ս��"), MB_OKCANCEL);
					return OK;
				}
				else if (mouse.x > 0/*position*/ && mouse.x < 107/*position*/ && mouse.y>654/*position*/ && mouse.y < 720/*position*/) {
					//����˳����
					//todo��ʾ���ʧ��
					MessageBox(NULL, _T("���ʧ��"), _T("���ս��"), MB_OKCANCEL);
					return OK;
				}

			}
		}
	}
}
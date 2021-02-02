#include"HeadFile.h"
//该函数为增加车次的函数
//参数为火车表
//返回值为1
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
				if (mouse.x > 250/*position*/ && mouse.x < 411/*position*/ && mouse.y>144/*position*/ && mouse.y < 212/*position*/) {//点击输入车次时
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要增加的车次", 0, 0, false)) {
						strcpy(train_temp.train_name, WcharToChar(tempwchar1));
					}

				}
				else if (mouse.x > 250/*position*/ && mouse.x < 411/*position*/ && mouse.y>290/*position*/ && mouse.y < 360/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要增加起始站", 0, 0, false)) {
						strcpy(train_temp.start_station, WcharToChar(tempwchar1));
					}
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要增加终点站", 0, 0, false)) {
						strcpy(train_temp.end_station, WcharToChar(tempwchar1));
					}
				}
				else if (mouse.x > 250/*position*/ && mouse.x < 411/*position*/ && mouse.y>430/*position*/ && mouse.y < 504/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入里程", 0, 0, false)) {
						train_temp.total_distance = _wtoi(tempwchar1);
					}
				}
				else if (mouse.x > 250/*position*/ && mouse.x < 411/*position*/ && mouse.y>556/*position*/ && mouse.y < 624/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入该列车的状态", 0, 0, false)) {
						strcpy(train_temp.train_status, WcharToChar(tempwchar1));
					}
				}
				else if (mouse.x > 844/*position*/ && mouse.x < 1000/*position*/ && mouse.y>142/*position*/ && mouse.y < 212/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入几点出发（分钟后面输入）", 0, 0, false)) {
						train_temp.start_time.hour = _wtoi(tempwchar1);
						if (InputBox(tempwchar1, MAXLENGTH, L"请输入几分出发（不输入默认0）", 0, 0, false)) {
							train_temp.start_time.minute = _wtoi(tempwchar1);
						}
					}
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入几点到终点站（分钟后面输入）", 0, 0, false)) {
						train_temp.arrival_time.hour = _wtoi(tempwchar1);
						if (InputBox(tempwchar1, MAXLENGTH, L"请输入几分到终点站（不输入默认0）", 0, 0, false)) {
							train_temp.arrival_time.minute = _wtoi(tempwchar1);
						}
					}
				}
				else if (mouse.x > 844/*position*/ && mouse.x < 1000/*position*/ && mouse.y>290/*position*/ && mouse.y < 356/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入停靠站数量(输入此后才可输入停靠站信息）", 0, 0, false)) {
						train_temp.stop_station_number = _wtoi(tempwchar1);
					}
				}
				else if (mouse.x > 844/*position*/ && mouse.x < 1000/*position*/ && mouse.y>430/*position*/ && mouse.y < 502/*position*/) {
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入特等座数量（不输入默认为0）", 0, 0, false)) {
						train_temp.seat.special = _wtoi(tempwchar1);
					}
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入一等座数量（不输入默认为0）", 0, 0, false)) {
						train_temp.seat.first_class = _wtoi(tempwchar1);
					}
					if (InputBox(tempwchar1, MAXLENGTH, L"请输入二等座数量（不输入默认为0）", 0, 0, false)) {
						train_temp.seat.second_class = _wtoi(tempwchar1);
					}
				}
				else if (mouse.x > 844/*position*/ && mouse.x < 1000/*position*/ && mouse.y>554/*position*/ && mouse.y < 626/*position*/) {
					if (train_temp.stop_station_number == 0) {
						//todo显示请先输入停靠站数量
						sprintf(WcharToChar(tempwchar2), "%d", train_temp.stop_station_number);
						MessageBox(NULL,tempwchar2, _T("停靠站数量"), MB_OKCANCEL);
						continue;
					}
					PStopStation tempnow = NULL, tempnext = NULL;
					wcscpy(tempwchar2, L"停靠站1信息输入:停靠站名称");
					for (int i = 0; i < train_temp.stop_station_number; i++) {
						tempnext = (PStopStation)malloc(sizeof(StopStationType));
						InputBox(tempwchar1, MAXLENGTH, tempwchar2, 0, 0, false);
						strcpy(tempnext->stop_station, WcharToChar(tempwchar1));
						InputBox(tempwchar1,MAXLENGTH, L"到达的时间（小时）", 0, 0, false);
						tempnext->arrival_time.hour = _wtoi(tempwchar1);
						InputBox(tempwchar1,MAXLENGTH, L"到达的时间（分钟）", 0, 0, false);
						tempnext->arrival_time.minute = _wtoi(tempwchar1);
						InputBox(tempwchar1,MAXLENGTH, L"出发的时间（小时）", 0, 0, false);
						tempnext->start_time.hour = _wtoi(tempwchar1);
						InputBox(tempwchar1,MAXLENGTH, L"出发的时间（分钟）", 0, 0, false);
						tempnext->start_time.minute = _wtoi(tempwchar1);
						InputBox(tempwchar1,MAXLENGTH, L"里程数", 0, 0, false);
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
					train_table.trains[train_table.num_of_train] = train_temp;//摁确定后
					train_table.num_of_train++;
					//todo显示添加成功
					MessageBox(NULL, _T("添加成功"), _T("最终结果"), MB_OKCANCEL);
					return OK;
				}
				else if (mouse.x > 0/*position*/ && mouse.x < 107/*position*/ && mouse.y>654/*position*/ && mouse.y < 720/*position*/) {
					//点击退出添加
					//todo显示添加失败
					MessageBox(NULL, _T("添加失败"), _T("最终结果"), MB_OKCANCEL);
					return OK;
				}

			}
		}
	}
}
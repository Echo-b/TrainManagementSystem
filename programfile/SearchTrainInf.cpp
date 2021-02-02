#include "HeadFile.h"
//该函数为根据信息查找火车函数
//参数第一个为火车表，第二个为带有查找信息的结构体，第三个为存储查找结果的数组
//返回值：当返回OK时表示查找成功，返回ERROR时查找失败
Status search_realated_TraInf(TrainTableType& train_table, train_information input_train_inf, PtrainInf *train_point, int& is_final_number)
{
	TimeType InitTime = { -1,-1 };
	DateType InitDate = { -1,-1,-1 };
	PStopStation temp_stop;
	for (int i = 0; i < train_table.num_of_train; i++) {
		if ((strcmp(train_table.trains[i].train_name, input_train_inf.train_name) == 0 || strcmp(input_train_inf.train_name, "\0")) &&
			(strcmp(train_table.trains[i].end_station, input_train_inf.end_station) == 0 || strcmp(input_train_inf.end_station, "\0")) &&
			(strcmp(train_table.trains[i].start_station, input_train_inf.start_station) == 0 || strcmp(input_train_inf.start_station, "\0")) &&
			(strcmp(train_table.trains[i].train_status, input_train_inf.train_status) || strcmp(input_train_inf.train_status, "\0")) &&
			(IsTimeSame(train_table.trains[i].arrival_time, input_train_inf.arrival_time) || IsTimeSame(input_train_inf.arrival_time, InitTime)) &&
			(IsTimeSame(train_table.trains[i].start_time, input_train_inf.start_time) || IsTimeSame(input_train_inf.start_time, InitTime))) {
			temp_stop = train_table.trains[i].first_stop_station;
			for (int j = 0; j < train_table.trains[i].stop_station_number; j++) {
				if (strcmp(input_train_inf.start_station, "\0") || strcmp(input_train_inf.start_station, temp_stop->stop_station)) {
					if (strcmp(input_train_inf.end_station, "\0") || strcmp(input_train_inf.end_station, temp_stop->stop_station)) {
						train_point[is_final_number++] = &train_table.trains[i];
					}
				}
			}
		}
	}
	if (is_final_number == 0) {
		//outtextxy(0, 0, _T("无匹配数据"));
		return ERROR;
	}
	return OK;
}
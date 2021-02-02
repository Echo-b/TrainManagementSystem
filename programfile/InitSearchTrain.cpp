#include "HeadFile.h"
//此函数用于初始化查找火车的结构体
//参数为火车信息的结构体
//返回值为OK只许成功
Status init_search_train(train_information& search_train)
{
	search_train.arrival_time = { -1,-1 };
	strcpy(search_train.end_station, "\0");
	search_train.first_stop_station = NULL;
	search_train.frist_passenger = NULL;
	search_train.seat = { -1,-1,-1 };
	strcpy(search_train.start_station, "\0");
	search_train.start_time = { -1,-1 };
	search_train.stop_station_number= -1;
	search_train.total_distance= -1;
	strcpy(search_train.train_name, "\0");
	strcpy(search_train.train_status, "\0");
	return OK;
}
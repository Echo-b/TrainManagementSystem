#include"HeadFile.h"
//此函数为火车文件的读取函数，第一个参数为火车表，第二个为文件名
//当返回OK时表示读取成功，返回ERROR时读取失败
Status train_read_file(TrainTableType &train_table,const char *file_name)
{
	FILE* fp;
	int i = 0;
	if(!(fp = fopen(file_name, "r")))return ERROR;
	while (fscanf(fp, "%s", train_table.trains[i].train_name) != -1) {
		fscanf(fp, "%s", train_table.trains[i].start_station);
		fscanf(fp, "%s", train_table.trains[i].end_station);
		fscanf(fp, "%s", train_table.trains[i].total_distance);
		fscanf(fp, "%s", train_table.trains[i].train_status);
		fscanf(fp, "%d:%d", &train_table.trains[i].start_time.hour, &train_table.trains[i].start_time.minute);
		fscanf(fp, "%d:%d", &train_table.trains[i].arrival_time.hour, &train_table.trains[i].arrival_time.minute);
		fscanf(fp, "%d", &train_table.trains[i].stop_station_number);
		fscanf(fp, "%d", &train_table.trains[i].seat.special);
		fscanf(fp, "%d", &train_table.trains[i].seat.first_class);
		fscanf(fp, "%d", &train_table.trains[i].seat.second_class);
		for (int j = 0; j < train_table.trains[i].stop_station_number; j++) {//停靠站链表输入
			PStopStation p_station_next;
			PStopStation p_station_now;
			p_station_next = (PStopStation)malloc(sizeof(StopStationType));
			fscanf(fp, "%s", p_station_next->stop_station);
			fscanf(fp, "%d:%d", &p_station_next->arrival_time.hour, &p_station_next->arrival_time.minute);
			fscanf(fp, "%d:%d", &p_station_next->start_time.hour, &p_station_next->start_time.minute);
			fscanf(fp, "%d", &p_station_next->total_distance);
			if (j == 0) {
				train_table.trains[i].first_stop_station = p_station_next;
				p_station_now = p_station_next;
				continue;
			}
			p_station_now->next_station = p_station_next;
			p_station_now = p_station_next;
			//todo加入realloc函数，防止第一次超过最大容量
		}
		train_table.num_of_train++;

	}
	return OK;
}
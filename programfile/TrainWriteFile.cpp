#include"HeadFile.h"
//该函数为火车信息写入文件的函数，此函数会将原来的同名文件删除，再新建一个（若没有直接新建）进行写入
//该函数参数1为火车表，第二个参数为文件名
//返回值，返回error就是你电脑没有内存了，输出失败，返回OK表示成功
Status TrainWriteFile(TrainTableType train_table, const char* file_name)
{
	FILE* fp;
	if(!(fp = fopen(file_name, "w")))return ERROR;
	for (int i = 0; i < train_table.num_of_train; i++) {
		fprintf(fp, "%s ", train_table.trains[i].train_name);
		fprintf(fp, "%s ", train_table.trains[i].start_station);
		fprintf(fp, "%s ", train_table.trains[i].end_station);
		fprintf(fp, "%.1f ", train_table.trains[i].total_distance);
		fprintf(fp, "%s ", train_table.trains[i].train_status);
		fprintf(fp, "%d:%d ", train_table.trains[i].start_time.hour, train_table.trains[i].start_time.minute);
		fprintf(fp, "%d:%d ", train_table.trains[i].arrival_time.hour,train_table.trains[i].arrival_time.minute);
		fprintf(fp, "%d ", train_table.trains[i].stop_station_number);
		fprintf(fp, "%d ", train_table.trains[i].seat.special);
		fprintf(fp, "%d ", train_table.trains[i].seat.first_class);
		fprintf(fp, "%d ", train_table.trains[i].seat.second_class);
		PStopStation Ptemp;
		Ptemp = train_table.trains[i].first_stop_station;
		for (int j = 0; j < train_table.trains[i].stop_station_number; j++) {//停靠站文件输出
			
			fprintf(fp, "%s ", Ptemp->stop_station);
			fprintf(fp, "%d:%d ", Ptemp->arrival_time.hour, Ptemp->arrival_time.minute);
			fprintf(fp, "%d:%d ", Ptemp->start_time.hour, Ptemp->start_time.minute);
			fprintf(fp, "%.1f ", Ptemp->total_distance);
			Ptemp = Ptemp->next_station;
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	return OK;
}
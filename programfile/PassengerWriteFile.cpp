#include"HeadFile.h"
//该函数为乘客表的文件写入函数
//第一个参数为乘客表，第二个参数为文件名
//返回值为当返回OK时成功，返回error失败
Status PassengerReadFile(PassengerTableType passenger_table, const char *file_name)
{
	FILE* fp;
	if(!(fp = fopen(file_name, "w")))return ERROR;
	for (int i = 0; i < passenger_table.num_of_passenger; i++) {
		fprintf(fp, "%s", passenger_table.passengers[i].id_number);
		fprintf(fp, "%s", passenger_table.passengers[i].id_name);
		fprintf(fp, "%s", passenger_table.passengers[i].id_type);
		fprintf(fp, "%s", passenger_table.passengers[i].tel_nunmber);
		fprintf(fp, "%s", passenger_table.passengers[i].emergency_contact);
		fprintf(fp, "%s", passenger_table.passengers[i].emergency_contact_tel);
		fprintf(fp, "\n");
	}
	fclose(fp);
	return OK;
}
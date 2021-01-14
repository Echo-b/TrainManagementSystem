#include"HeadFile.h"
//此函数用于从文件读取乘客信息，第一个函数为读取后所放的位置，第二个为文件名。返回值当返回OK时成功，当返回值为ERROR时读取失败
Status passenger_read_file(PassengerTableType &passenger_table, const char *file_name)
{
	FILE *fp;
	int i = 0;//第i个乘客
	if (!(fp = fopen(file_name, "r")))return ERROR;
	while (fscanf(fp, "%s", passenger_table.passengers[i].id_number)!=-1) {
		fscanf(fp, "%s", passenger_table.passengers[i].id_name);
		fscanf(fp, "%s", passenger_table.passengers[i].id_type);
		fscanf(fp, "%s", passenger_table.passengers[i].tel_nunmber);
		fscanf(fp, "%s", passenger_table.passengers[i].emergency_contact);
		fscanf(fp, "%s", passenger_table.passengers[i].emergency_contact_tel);
		i++;
		passenger_table.num_of_passenger++;
		//todu加入realloc函数，防止输入时超过最大容量
	}
	fclose(fp);
	return OK;
}
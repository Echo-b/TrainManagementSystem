#include"HeadFile.h"
//此函数用于从文件读取乘客信息，第一个函数为读取后所放的位置，第二个为文件名。返回值当返回OK时成功，当返回值为ERROR时读取失败
Status ticket_write_file(TicketTableType ticket_table, const char* file_name)
{
	FILE* fp;
	if (!(fp = fopen(file_name, "w")))return ERROR;
	for(int i=0;i<ticket_table.num_of_book;i++){
		fprintf(fp, "%s", ticket_table.trains_ticket[i].order_number);
		fprintf(fp, "%04d%02d%02d", ticket_table.trains_ticket[i].travel_date.year, ticket_table.trains_ticket[i].travel_date.month, ticket_table.trains_ticket[i].travel_date.day);
		fprintf(fp, "%s", ticket_table.trains_ticket[i].train_name);
		fprintf(fp, "%s", ticket_table.trains_ticket[i].start_station);
		fprintf(fp, "%s", ticket_table.trains_ticket[i].end_station);
		fprintf(fp, "%s", ticket_table.trains_ticket[i].id_type);
		fprintf(fp, "%s", ticket_table.trains_ticket[i].id_number);
		fprintf(fp, "%s", ticket_table.trains_ticket[i].id_name);
		fprintf(fp, "%d:%d", ticket_table.trains_ticket[i].start_time.hour, ticket_table.trains_ticket[i].start_time.minute);
		fprintf(fp, "%d:%d", ticket_table.trains_ticket[i].arrival_time.hour, ticket_table.trains_ticket[i].arrival_time.minute);
		fprintf(fp, "%s", ticket_table.trains_ticket[i].seat_level);
		fprintf(fp, "%d", ticket_table.trains_ticket[i].seat_number);
		fprintf(fp, "%.1f", ticket_table.trains_ticket[i].cost);
		fprintf(fp, "\n");
	}
	fclose(fp);
	return OK;
}
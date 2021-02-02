#include"HeadFile.h"
//�˺������ڴ��ļ���ȡ�˿���Ϣ����һ������Ϊ��ȡ�����ŵ�λ�ã��ڶ���Ϊ�ļ���������ֵ������OKʱ�ɹ���������ֵΪERRORʱ��ȡʧ��
Status ticket_read_file(TicketTableType& ticket_table, const char* file_name)
{
	FILE* fp;
	int i = 0;//��i���˿�
	if (!(fp = fopen(file_name, "r")))return ERROR;
	while (fscanf(fp, "%s", ticket_table.trains_ticket[i].order_number) != -1) {
		fscanf(fp,"%4d%2d%2d", &ticket_table.trains_ticket[i].travel_date.year, &ticket_table.trains_ticket[i].travel_date.month, &ticket_table.trains_ticket[i].travel_date.day);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].train_name);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].start_station);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].end_station);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].id_type);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].id_number);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].id_name);
		fscanf(fp, "%d:%d", &ticket_table.trains_ticket[i].start_time.hour, &ticket_table.trains_ticket[i].start_time.minute);
		fscanf(fp, "%d:%d", &ticket_table.trains_ticket[i].arrival_time.hour, &ticket_table.trains_ticket[i].arrival_time.minute);
		fscanf(fp, "%s", ticket_table.trains_ticket[i].seat_level);
		fscanf(fp, "%d", &ticket_table.trains_ticket[i].seat_number);
		fscanf(fp, "%f", &ticket_table.trains_ticket[i].cost);
		i++;
		ticket_table.num_of_book++;
		//todu����realloc��������ֹ����ʱ�����������
	}
	fclose(fp);
	return OK;
}
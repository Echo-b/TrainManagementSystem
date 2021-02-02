#include "HeadFile.h"
Status search_rest_ticket(train_information train_input, TrainTableType& train_table, train_information *rest_ticket_point) {
	//����������һ���ǻ𳵽ṹ�壬�ṩ�û������룬һ�������Ż𳵵���Ϣ��
	int is_final_number = 0;
	for (int i = 0; i < train_table.size; i++) {
		if (((train_table.trains[i].start_time.hour == train_input.start_time.hour) && (train_table.trains[i].start_time.minute == train_input.start_time.minute)) &&
			((strcmp(train_input.train_name, train_table.trains[i].train_name) == 0) ||
				(strcmp(train_table.trains[i].start_station, train_input.start_station) == 0) ||
				(strcmp(train_table.trains[i].end_station, train_input.end_station) == 0))) {
			rest_ticket_point[is_final_number++] = train_table.trains[i];
		}
	}
	if (is_final_number == 0) {
		outtextxy(0, 0, _T("����Ʊ"));
		return ERROR;
	}
	return OK;
}
#include "HeadFile.h"
Status search_realated_Pasinf(PassengerTableType& passenger_table,char * input_realated_info,Ppassenger &passenger_point[10]) {
	//参数为乘客数据表和一个输入的参数，可以是紧急联系人或者证件号，姓名等，查找成功返回一个结构体指针数组首地址
	int is_final_number=0;//用于统计匹配人数 
	for (int i = 0; i < passenger_table.size; i++) {
		if (strcmp(passenger_table.passengers->emergency_contact, input_realated_info) == 0 || strcmp(passenger_table.passengers->id_name, input_realated_info) == 0
			|| strcmp(passenger_table.passengers->id_number, input_realated_info) == 0 || strcmp(passenger_table.passengers->id_number, input_realated_info) == 0) {
			passenger_point[is_final_number++] = passenger_table.passengers;
		}
	}
	if (is_final_number == 0) {
		outtextxy(0, 0, _T("未找到匹配数据"));//输出位置后期确定
		return ERROR;
	}
	return OK;
}

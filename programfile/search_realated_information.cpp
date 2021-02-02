#include "HeadFile.h"
//此函数为根据信息查找用户的函数
//参数为乘客数据表和一个输入的参数，可以是紧急联系人或者证件号，姓名等，查找成功返回一个结构体指针数组首地址
//返回值，当返回OK时查找成功，返回ERROR时查找失败
Status search_realated_Pasinf(PassengerTableType& passenger_table, PassengerInf input_realated_info, Ppassenger * passenger_point,int &is_final_number) 
{
	
	for (int i = 0; i < passenger_table.size; i++) {
		if ((strcmp(passenger_table.passengers[i].emergency_contact, input_realated_info.emergency_contact) == 0 || strcmp(input_realated_info.emergency_contact,"\0"))&&
			(strcmp(passenger_table.passengers[i].id_name, input_realated_info.id_name) == 0||strcmp(input_realated_info.id_name,"\0"))&&			
			(strcmp(passenger_table.passengers[i].tel_nunmber, input_realated_info.tel_nunmber) == 0 ||strcmp(input_realated_info.tel_nunmber,"\0") )&&
			(strcmp(passenger_table.passengers[i].id_number, input_realated_info.id_number) == 0||strcmp(input_realated_info.id_number,"\0"))) {
			passenger_point[is_final_number++] = &passenger_table.passengers[i];
		}
	}
	if (is_final_number == 0) {
		//outtextxy(0, 0, _T("未找到匹配数据"));//输出位置后期确定
		return ERROR;
	}
	return OK;
}
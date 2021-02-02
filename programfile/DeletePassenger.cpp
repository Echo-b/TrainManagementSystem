#include "HeadFile.h"
//此函数用于管理员删除乘客的函数
//参数为乘客表
//返回值：一直返回OK
Status DeletePassenger(PassengerTableType &passenger_table)
{
	PassengerInf search_passenger;			//乘客用于查找的结构体
	init_searchtable(search_passenger);		//初始化乘客用于查找的结构体
	Ppassenger result_passenger[MAXLENGTH]; //乘客查找结果存放处
	int is_final_number = 0;
	wchar_t tempwchar[50];
	if (InputBox(tempwchar, 50, L"请输入想要删除的乘客姓名", L"姓名", NULL, 0, 0, false))
	{
		strcpy(search_passenger.id_name, WcharToChar(tempwchar));
		if (search_realated_Pasinf(passenger_table, search_passenger, result_passenger,is_final_number))
		{
			*result_passenger[0] = passenger_table.passengers[passenger_table.num_of_passenger];
			passenger_table.num_of_passenger--;
			//todo(不那么紧要）显示删除成功
			MessageBox(NULL, _T("删除成功"), _T("最终结果"), MB_OKCANCEL);
		}
		else
		{
			//todo(不那么紧要）显示无此人
			MessageBox(NULL, _T("无此人"), _T("最终结果"), MB_OKCANCEL);
		}
	}
	return 0;
}
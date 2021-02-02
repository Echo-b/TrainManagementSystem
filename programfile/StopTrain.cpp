#include "HeadFile.h"
//该函数用于停开一列火车
//唯一参数为火车表
//返回值：返回OK代表更改成功，返回ERROR代表更改失败
Status StopTrain(TrainTableType &train_table)
{
	int flag = 0;
	char input_train_info[20];
	wchar_t tempwchar[20];
	InputBox(tempwchar, 20, L"请输入要改变状态的车次", L"博奥高铁股份有限公司", NULL, 0, 0, false);
	strcpy(input_train_info, WcharToChar(tempwchar));
	for (int i = 0; i < train_table.num_of_train; i++)
	{
		if (strcmp(train_table.trains[i].train_name, input_train_info) == 0)
		{
			flag = 1;
			if (!strcmp(train_table.trains[i].train_status, "停运"))
			{
				strcpy(train_table.trains[i].train_status, "正常");
			}
			else
			{
				strcpy(train_table.trains[i].train_status, "停运");
			}
		}
	}
	if (flag == 1)
	{
		//todo增加一个更改成功的显示
		MessageBox(NULL, _T("更改成功"), _T("最终结果"), MB_OKCANCEL);
		return OK;
	}
	//todo增加一个更改失败的显示
	MessageBox(NULL, _T("更改失败"), _T("最终结果"), MB_OKCANCEL);
	return ERROR;
}
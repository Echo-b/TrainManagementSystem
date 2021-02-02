#include"HeadFile.h"
//该函数用于用户获取当前所坐的火车的信息
//参数为火车表
//返回值为OK
Status GetTrainInf(TrainTableType train_table)
{
	train_information search_train;//火车用于查找的结构体
	init_search_train(search_train);//初始化火车结构体
	PtrainInf result_train[MAXLENGTH] = {NULL};//火车查找结果存放处
	wchar_t tempwchar[50];
	int is_final_number = 0;
	/***************************************************/
	if (InputBox(tempwchar, 50, L"请输入您乘坐列车的车次")) {
		strcpy(search_train.train_name, WcharToChar(tempwchar));
		search_realated_TraInf(train_table, search_train, result_train,is_final_number);
		if (result_train[0]) {
			//显示结果
		}
		else {
			//查找失败，弹窗显示即可
		}
	}
	return OK;
}
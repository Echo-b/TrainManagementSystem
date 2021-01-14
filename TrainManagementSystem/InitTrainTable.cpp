#include"HeadFile.h"
//此函数是简单地初始化火车表，参数为火车表的结构体
//返回值：int类型，当为OK时初始化成功，当为OVERFLOW时初始化失败
Status init_train_table(TrainTableType &train_table)
{
	if(!(train_table.trains = (PtrainInf)malloc(sizeof(train_information) * MAXLENGTH)))return OVERFLOW;
	train_table.num_of_train = 0;
	train_table.size = MAXLENGTH;
	return OK;
}
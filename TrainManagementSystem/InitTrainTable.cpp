#include"HeadFile.h"
//�˺����Ǽ򵥵س�ʼ���𳵱�����Ϊ�𳵱�Ľṹ��
//����ֵ��int���ͣ���ΪOKʱ��ʼ���ɹ�����ΪOVERFLOWʱ��ʼ��ʧ��
Status init_train_table(TrainTableType &train_table)
{
	if(!(train_table.trains = (PtrainInf)malloc(sizeof(train_information) * MAXLENGTH)))return OVERFLOW;
	train_table.num_of_train = 0;
	train_table.size = MAXLENGTH;
	return OK;
}
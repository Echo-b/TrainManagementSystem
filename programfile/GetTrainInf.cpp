#include"HeadFile.h"
//�ú��������û���ȡ��ǰ�����Ļ𳵵���Ϣ
//����Ϊ�𳵱�
//����ֵΪOK
Status GetTrainInf(TrainTableType train_table)
{
	train_information search_train;//�����ڲ��ҵĽṹ��
	init_search_train(search_train);//��ʼ���𳵽ṹ��
	PtrainInf result_train[MAXLENGTH] = {NULL};//�𳵲��ҽ����Ŵ�
	wchar_t tempwchar[50];
	int is_final_number = 0;
	/***************************************************/
	if (InputBox(tempwchar, 50, L"�������������г��ĳ���")) {
		strcpy(search_train.train_name, WcharToChar(tempwchar));
		search_realated_TraInf(train_table, search_train, result_train,is_final_number);
		if (result_train[0]) {
			//��ʾ���
		}
		else {
			//����ʧ�ܣ�������ʾ����
		}
	}
	return OK;
}
#include "HeadFile.h"
//�˺������ڹ���Աɾ���˿͵ĺ���
//����Ϊ�˿ͱ�
//����ֵ��һֱ����OK
Status DeletePassenger(PassengerTableType &passenger_table)
{
	PassengerInf search_passenger;			//�˿����ڲ��ҵĽṹ��
	init_searchtable(search_passenger);		//��ʼ���˿����ڲ��ҵĽṹ��
	Ppassenger result_passenger[MAXLENGTH]; //�˿Ͳ��ҽ����Ŵ�
	int is_final_number = 0;
	wchar_t tempwchar[50];
	if (InputBox(tempwchar, 50, L"��������Ҫɾ���ĳ˿�����", L"����", NULL, 0, 0, false))
	{
		strcpy(search_passenger.id_name, WcharToChar(tempwchar));
		if (search_realated_Pasinf(passenger_table, search_passenger, result_passenger,is_final_number))
		{
			*result_passenger[0] = passenger_table.passengers[passenger_table.num_of_passenger];
			passenger_table.num_of_passenger--;
			//todo(����ô��Ҫ����ʾɾ���ɹ�
			MessageBox(NULL, _T("ɾ���ɹ�"), _T("���ս��"), MB_OKCANCEL);
		}
		else
		{
			//todo(����ô��Ҫ����ʾ�޴���
			MessageBox(NULL, _T("�޴���"), _T("���ս��"), MB_OKCANCEL);
		}
	}
	return 0;
}
#include"HeadFile.h"
//�˺��������Ƚ����ڽṹ���Ƿ���ͬ
//����������Ϊ���ڽṹ��
//����ֵ��������1ʱ��ͬ������0ʱ��ͬ
int IsDateSame(DateType date1, DateType date2)
{
	if (date1.year == date2.year)
		if (date1.month == date2.month)
			if (date1.day == date2.day)return 1;
	return 0;
}
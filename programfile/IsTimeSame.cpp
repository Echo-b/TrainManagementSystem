#include"HeadFile.h"
//�˺������ڱȽ�ʱ��ṹ��Ĳ����Ƿ���ͬ
//����������Ϊʱ��ṹ�����
//����0��ͬ������1����ͬ
int IsTimeSame(TimeType start_time, TimeType end_time)
{
	TimeType temp_time_difference;
	if (start_time.hour == end_time.hour)
		if (end_time.minute == start_time.minute)return 1;
	return 0;
}
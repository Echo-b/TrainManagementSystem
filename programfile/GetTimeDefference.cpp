#include"HeadFile.h"
//�˺������ڷ��ص�ǰϵͳʱ��
//�޲���
//����ֵ����Ϊϵͳʱ��DateType����
DateType Get_Sys_Time()       //���ص�ǰϵͳʱ��
{
    struct tm today;       //���ʱ��Ľṹ��
    time_t one;            //���ʱ�������
    DateType now;
    one = time(&one);              //���ϵͳʱ��
    today = *(gmtime(&one));       //��time_t��ʽϵͳʱ��תΪstruct tm��ʽ
    now.year = today.tm_year - 100 + 2000;     //2011�귵��111
    now.month = today.tm_mon + 1;           //9�·���8;
    now.day = today.tm_mday;
    return now;
}

#include"HeadFile.h"
//�˺���Ϊwchar����ת��Ϊchar���͵ĺ���
//����Ϊchar���ַ������ͣ������Ԫ���ݽ��и���
//����ֵΪwchar*������
char* WcharToChar(const wchar_t* wchar)
{
    char* m_char;
    int len = WideCharToMultiByte(CP_ACP, 0, wchar, wcslen(wchar), NULL, 0, NULL, NULL);
    m_char = new char[len + 1];
    WideCharToMultiByte(CP_ACP, 0,wchar, wcslen(wchar), m_char, len, NULL, NULL);
    m_char[len] = '\0';
    return m_char;
}
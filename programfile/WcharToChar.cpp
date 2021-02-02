#include"HeadFile.h"
//此函数为wchar类型转换为char类型的函数
//参数为char的字符串类型，不会对元数据进行更改
//返回值为wchar*的类型
char* WcharToChar(const wchar_t* wchar)
{
    char* m_char;
    int len = WideCharToMultiByte(CP_ACP, 0, wchar, wcslen(wchar), NULL, 0, NULL, NULL);
    m_char = new char[len + 1];
    WideCharToMultiByte(CP_ACP, 0,wchar, wcslen(wchar), m_char, len, NULL, NULL);
    m_char[len] = '\0';
    return m_char;
}
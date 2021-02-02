#include"HeadFile.h"
//此函数为获取一个char类型的变量，返回其真值相同的一个wchar类型的变量
//参数为char类型
//返回值为wchar_t类型
wchar_t* CharToWchar(const char* cchar)
{
	wchar_t* m_wchar;
	int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), m_wchar, len);
	m_wchar[len] = '\0';
	return m_wchar;
}
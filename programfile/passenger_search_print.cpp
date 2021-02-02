#include "HeadFile.h"
void passenger_search_print(Ppassenger *result_passenger, int total_num)
{
    IMAGE passenger_print;
    loadimage(&passenger_print, L"Image\\passengeroutput1.jpg", WIDTH, HEIGHT); //加载输出的背景图片
    putimage(0, 0, &passenger_print);
    //char total_num[10] = { 0 };
    char page_num[10] = { 0 };
    char page_now[10] = { 0 };
    for (int j = 0; j < total_num; j++)
    {
        setbkmode(TRANSPARENT);          //设置字体背景为透明
        settextcolor(COLORREF(BLACK));   //设置字体颜色为黑色
        settextstyle(18, 0, _T("楷体")); //设置字体大小20，格式楷体
        outtextxy(63, 30 * (j + 1) + 53, CharToWchar(result_passenger[j]->id_number));
        outtextxy(320, 30 * (j + 1) + 53, CharToWchar(result_passenger[j]->id_name));
        outtextxy(482, 30 * (j + 1) + 53, CharToWchar(result_passenger[j]->tel_nunmber));
        outtextxy(720, 30 * (j + 1) + 53, CharToWchar(result_passenger[j]->emergency_contact));
        outtextxy(900, 30 * (j + 1) + 53, CharToWchar(result_passenger[j]->emergency_contact_tel));
    }
}
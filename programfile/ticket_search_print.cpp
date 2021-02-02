#include "HeadFile.h"
void ticket_search_print(Pbook* result_ticket,int total_num)
{
    IMAGE train_print;
    loadimage(&train_print, L"Image\\tickeoutput1.jpg", WIDTH, HEIGHT); //加载输出的背景图片
    putimage(0, 0, &train_print);
    //char total_num[10] = { 0 };
    char page_num[10] = { 0 };
    char page_now[10] = { 0 };
    char starttimehour[10] = { 0 };
    char starttimeminute[10] = { 0 };
    char endtimehour[10] = { 0 };
    char endtimeminute[10] = { 0 };
    char year[10] = { 0 };
    char month[10] = { 0 };
    char day[10] = { 0 };
    for (int j = 0; j < total_num; j++)
    {
        sprintf(starttimehour, "%d", result_ticket[j]->start_time.hour);
        sprintf(starttimeminute, "%d", result_ticket[j]->start_time.minute);
        sprintf(endtimehour, "%d", result_ticket[j]->arrival_time.hour);
        sprintf(endtimeminute, "%d", result_ticket[j]->arrival_time.minute);
        sprintf(year, "%d", result_ticket[j]->travel_date.year);
        sprintf(month, "%d", result_ticket[j]->travel_date.month);
        sprintf(day, "%d", result_ticket[j]->travel_date.day);
        setbkmode(TRANSPARENT);          //设置字体背景为透明
        settextcolor(COLORREF(BLACK));   //设置字体颜色为黑色
        settextstyle(18, 0, _T("楷体")); //设置字体大小20，格式楷体
        outtextxy(50, 30 * (j + 1) + 55, CharToWchar(result_ticket[j]->order_number));
        outtextxy(220, 30 * (j + 1) + 55, CharToWchar(year));
        outtextxy(255, 30 * (j + 1) + 55, _T("-"));
        outtextxy(260, 30 * (j + 1) + 55, CharToWchar(month));
        outtextxy(270, 30 * (j + 1) + 55, _T("-"));
        outtextxy(280, 30 * (j + 1) + 55, CharToWchar(day));
        outtextxy(380, 30 * (j + 1) + 55, CharToWchar(result_ticket[j]->start_station));
        outtextxy(540, 30 * (j + 1) + 55, CharToWchar(result_ticket[j]->end_station));
        outtextxy(670, 30 * (j + 1) + 55, CharToWchar(result_ticket[j]->id_name));
        outtextxy(800, 30 * (j + 1) + 55, CharToWchar(starttimehour));
        outtextxy(820, 30 * (j + 1) + 55, _T(":"));
        outtextxy(840, 30 * (j + 1) + 55, CharToWchar(starttimeminute));
        outtextxy(920, 30 * (j + 1) + 55, CharToWchar(endtimehour));
        outtextxy(940, 30 * (j + 1) + 55, _T(":"));
        outtextxy(960, 30 * (j + 1) + 55, CharToWchar(endtimeminute));
    }
}

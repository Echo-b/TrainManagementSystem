#include "HeadFile.h"
void train_search_print(PtrainInf* result_train,int total_num)
{
    IMAGE train_print;
    loadimage(&train_print, L"Image\\trainoutput1.jpg", WIDTH, HEIGHT); //加载输出的背景图片
    putimage(0, 0, &train_print);
    char total_number[10] = { 0 };
    char page_num[10] = { 0 };
    char page_now[10] = { 0 };
    char total_distance[10] = { 0 };
    char starttimehour[10] = { 0 };
    char starttimeminute[10] = { 0 };
    char endtimehour[10] = { 0 };
    char endtimeminute[10] = { 0 };
    for (int j = 0; j < total_num; j++)
    {
        sprintf(total_distance, "%.1f", result_train[j]->total_distance);
        sprintf(starttimehour, "%d", result_train[j]->start_time.hour);
        sprintf(starttimeminute, "%d", result_train[j]->start_time.minute);
        sprintf(endtimehour, "%d", result_train[j]->arrival_time.hour);
        sprintf(endtimeminute, "%d", result_train[j]->arrival_time.minute);
        setbkmode(TRANSPARENT);          //设置字体背景为透明
        settextcolor(COLORREF(BLACK));   //设置字体颜色为黑色
        settextstyle(18, 0, _T("楷体")); //设置字体大小20，格式楷体
        outtextxy(64, 30 * (j + 1) + 55, CharToWchar(result_train[j]->train_name));
        outtextxy(220, 30 * (j + 1) + 55, CharToWchar(result_train[j]->train_status));
        outtextxy(350, 30 * (j + 1) + 55, CharToWchar(result_train[j]->start_station));
        outtextxy(470, 30 * (j + 1) + 55, CharToWchar(result_train[j]->end_station));
        outtextxy(650, 30 * (j + 1) + 55, CharToWchar(total_distance));
        outtextxy(800, 30 * (j + 1) + 55, CharToWchar(starttimehour));
        outtextxy(820, 30 * (j + 1) + 55, _T(":"));
        outtextxy(840, 30 * (j + 1) + 55, CharToWchar(starttimeminute));
        outtextxy(900, 30 * (j + 1) + 55, CharToWchar(endtimehour));
        outtextxy(920, 30 * (j + 1) + 55, _T(":"));
        outtextxy(940, 30 * (j + 1) + 55, CharToWchar(endtimeminute));
    }
}
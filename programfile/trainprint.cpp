#include "HeadFile.h"
void train_print(TrainTableType train_table, int flag)
{
	IMAGE train_print;
	loadimage(&train_print, L"Image\\trainoutput.png", WIDTH, HEIGHT);//加载输出的背景图片
	putimage(0, 0, &train_print);
	char total_num[10] = { 0 };
	char page_num[10] = { 0 };
	char page_now[10] = { 0 };
	char total_distance[10] = { 0 };
	char starttimehour[10] = { 0 };
	char starttimeminute[10] = { 0 };
	char endtimehour[10] = { 0 };
	char endtimeminute[10] = { 0 };
	sprintf(total_num, "%d", train_table.num_of_train);
	if(train_table.num_of_train%10!=0)
		sprintf(page_num, "%d", train_table.num_of_train / 10+1);
	else
		sprintf(page_num, "%d", train_table.num_of_train / 10);
	sprintf(page_now, "%d", flag);
	int temp_output_num = 10;
	for (int i = (flag - 1) * 10, j = 0; i < 10 * flag, j < temp_output_num; i++, j++)
	{
		if (flag == _wtoi(CharToWchar(page_num)));
			temp_output_num = train_table.num_of_train % 10;
		sprintf(total_distance, "%.1f", train_table.trains[i].total_distance);
		sprintf(starttimehour, "%d", train_table.trains[i].start_time.hour);
		sprintf(starttimeminute, "%d", train_table.trains[i].start_time.minute);
		sprintf(endtimehour, "%d", train_table.trains[i].arrival_time.hour);
		sprintf(endtimeminute, "%d", train_table.trains[i].arrival_time.minute);
		setbkmode(TRANSPARENT);			 //设置字体背景为透明
		settextcolor(COLORREF(BLACK));	 //设置字体颜色为黑色
		settextstyle(18, 0, _T("楷体")); //设置字体大小20，格式楷体
		outtextxy(64, 30 * (j + 1) + 55, CharToWchar(train_table.trains[i].train_name));
		outtextxy(220, 30 * (j + 1) + 55, CharToWchar(train_table.trains[i].train_status));
		outtextxy(350, 30 * (j + 1) + 55, CharToWchar(train_table.trains[i].start_station));
		outtextxy(470, 30 * (j + 1) + 55, CharToWchar(train_table.trains[i].end_station));
		outtextxy(650, 30 * (j + 1) + 55, CharToWchar(total_distance));
		outtextxy(800, 30 * (j + 1) + 55, CharToWchar(starttimehour));
		outtextxy(820, 30 * (j + 1) + 55, _T(":"));
		outtextxy(840, 30 * (j + 1) + 55,CharToWchar(starttimeminute));
		outtextxy(900, 30 * (j + 1) + 55, CharToWchar(endtimehour));
		outtextxy(920, 30 * (j + 1) + 55, _T(":"));
		outtextxy(940, 30 * (j + 1) + 55, CharToWchar(endtimeminute));
		outtextxy(110, 33, CharToWchar(total_num));
		outtextxy(830, 33, CharToWchar(page_num));
		outtextxy(900, 33, CharToWchar(page_now));
	}
}
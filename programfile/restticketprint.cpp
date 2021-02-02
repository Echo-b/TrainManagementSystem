#include "HeadFile.h"
void rest_ticket_print(TrainTableType train_table, int flag)
{
	IMAGE train_print;
	loadimage(&train_print, L"Image\\restticket.png", WIDTH, HEIGHT);//加载输出的背景图片
	putimage(0, 0, &train_print);
	char total_num[10] = { 0 };
	char page_num[10] = { 0 };
	char page_now[10] = { 0 };
	char special[10] = { 0 };
	char firstclass[10] = { 0 };
	char secondclass[10] = { 0 };
	sprintf(total_num, "%d", train_table.num_of_train);
	if (train_table.num_of_train % 18 != 0)
		sprintf(page_num, "%d", train_table.num_of_train / 18 + 1);
	else
		sprintf(page_num, "%d", train_table.num_of_train / 18);
	sprintf(page_now, "%d", flag);
	int temp_output_num = 18;
	for (int i = (flag - 1) * 18, j = 0; i < 18 * flag, j < temp_output_num; i++, j++)
	{
		if (i == _wtoi(CharToWchar(page_num)));
			temp_output_num = train_table.num_of_train % 18;
		sprintf(special, "%d", train_table.trains[i].seat.special);
		sprintf(firstclass, "%d", train_table.trains[i].seat.first_class);
		sprintf(secondclass, "%d", train_table.trains[i].seat.second_class);
		setbkmode(TRANSPARENT);			 //设置字体背景为透明
		settextcolor(COLORREF(BLACK));	 //设置字体颜色为黑色
		settextstyle(18, 0, _T("楷体")); //设置字体大小20，格式楷体
		outtextxy(64, 30 * (j + 1) + 55, CharToWchar(train_table.trains[i].train_name));
		outtextxy(200, 30 * (j + 1) + 55, CharToWchar(train_table.trains[i].start_station));
		outtextxy(370, 30 * (j + 1) + 55, CharToWchar(train_table.trains[i].end_station));
		outtextxy(550, 30 * (j + 1) + 55, CharToWchar(special));
		outtextxy(750, 30 * (j + 1) + 55, CharToWchar(firstclass));
		outtextxy(940, 30 * (j + 1) + 55, CharToWchar(secondclass));
		outtextxy(110, 28, CharToWchar(total_num));
		outtextxy(870, 28, CharToWchar(page_num));
		outtextxy(960, 28, CharToWchar(page_now));
	}
}
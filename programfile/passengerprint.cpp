#include "HeadFile.h"
void passenger_print(PassengerTableType passenger_table, int flag)
{
	IMAGE passenger_print;
	loadimage(&passenger_print, L"Image\\passengeroutput.png", WIDTH, HEIGHT);//加载输出的背景图片
	putimage(0, 0, &passenger_print);
	char total_num[10] = { 0 };
	char page_num[10] = { 0 };
	char page_now[10] = { 0 };
	sprintf(total_num, "%d", passenger_table.num_of_passenger);
	if(passenger_table.num_of_passenger%18!=0)
		sprintf(page_num, "%d", passenger_table.num_of_passenger / 18+1);
	else
		sprintf(page_num, "%d", passenger_table.num_of_passenger / 18);
	sprintf(page_now, "%d", flag);
	int temp_output_num = 18;
	for (int i = (flag - 1) * 18, j = 0; i < 18 * flag, j < temp_output_num ; i++, j++)
	{
		if (flag == _wtoi(CharToWchar(page_num)));
			temp_output_num = passenger_table.num_of_passenger % 18;
		setbkmode(TRANSPARENT);			 //设置字体背景为透明
		settextcolor(COLORREF(BLACK));	 //设置字体颜色为黑色
		settextstyle(18, 0, _T("楷体")); //设置字体大小20，格式楷体
		outtextxy(63, 30 * (j + 1) + 53, CharToWchar(passenger_table.passengers[i].id_number));
		outtextxy(320, 30 * (j + 1) +53, CharToWchar(passenger_table.passengers[i].id_name));
		outtextxy(482, 30 * (j + 1) +53,CharToWchar(passenger_table.passengers[i].tel_nunmber));
		outtextxy(720, 30 * (j + 1) + 53, CharToWchar(passenger_table.passengers[i].emergency_contact));
		outtextxy(900, 30 * (j + 1) + 53, CharToWchar(passenger_table.passengers[i].emergency_contact_tel));
		outtextxy(130, 33, CharToWchar(total_num));
		outtextxy(900, 33, CharToWchar(page_num));
		outtextxy(970, 33, CharToWchar(page_now));
	}
}
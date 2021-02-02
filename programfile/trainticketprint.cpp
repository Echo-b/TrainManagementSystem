#include "HeadFile.h"
void ticket_print(TicketTableType ticket_table, int flag)
{
	IMAGE train_print;
	loadimage(&train_print, L"Image\\tickeoutput.png", WIDTH, HEIGHT);//加载输出的背景图片
	putimage(0, 0, &train_print);
	char total_num[10] = { 0 };
	char page_num[10] = { 0 };
	char page_now[10] = { 0 };
	char starttimehour[10] = { 0 };
	char starttimeminute[10] = { 0 };
	char endtimehour[10] = { 0 };
	char endtimeminute[10] = { 0 };
	char year[10] = { 0 };
	char month[10] = { 0 };
	char day[10] = { 0 };
	sprintf(total_num, "%d", ticket_table.num_of_book);
	if (ticket_table.num_of_book % 18 != 0)
		sprintf(page_num, "%d", ticket_table.num_of_book / 18+1);
	else
		sprintf(page_num, "%d", ticket_table.num_of_book / 18 );
	sprintf(page_now, "%d", flag);
	int temp_output_num = 18;
	for (int i = (flag - 1) * 18, j = 0; i < 18 * flag, j < temp_output_num; i++, j++)
	{
		if (flag == _wtoi(CharToWchar(page_num)));
		temp_output_num = ticket_table.num_of_book % 18;
		sprintf(starttimehour, "%d", ticket_table.trains_ticket[i].start_time.hour);
		sprintf(starttimeminute, "%d", ticket_table.trains_ticket[i].start_time.minute);
		sprintf(endtimehour, "%d", ticket_table.trains_ticket[i].arrival_time.hour);
		sprintf(endtimeminute, "%d", ticket_table.trains_ticket[i].arrival_time.minute);
		sprintf(year, "%d", ticket_table.trains_ticket[i].travel_date.year);
		sprintf(month, "%d", ticket_table.trains_ticket[i].travel_date.month);
		sprintf(day, "%d", ticket_table.trains_ticket[i].travel_date.day);
		setbkmode(TRANSPARENT);			 //设置字体背景为透明
		settextcolor(COLORREF(BLACK));	 //设置字体颜色为黑色
		settextstyle(18, 0, _T("楷体")); //设置字体大小20，格式楷体
		outtextxy(50, 30 * (j + 1) + 55, CharToWchar(ticket_table.trains_ticket[i].order_number));
		outtextxy(220, 30 * (j + 1) + 55, CharToWchar(year));
		outtextxy(255, 30 * (j + 1) + 55, _T("-"));
		outtextxy(260, 30 * (j + 1) + 55, CharToWchar(month));
		outtextxy(270, 30 * (j + 1) + 55, _T("-"));
		outtextxy(280, 30 * (j + 1) + 55,CharToWchar(day));
		outtextxy(380, 30 * (j + 1) + 55, CharToWchar(ticket_table.trains_ticket[i].start_station));
		outtextxy(540, 30 * (j + 1) + 55, CharToWchar(ticket_table.trains_ticket[i].end_station));
		outtextxy(670, 30 * (j + 1) + 55, CharToWchar(ticket_table.trains_ticket[i].id_name));
		outtextxy(800, 30 * (j + 1) + 55, CharToWchar(starttimehour));
		outtextxy(820, 30 * (j + 1) + 55, _T(":"));
		outtextxy(840, 30 * (j + 1) + 55, CharToWchar(starttimeminute));
		outtextxy(920, 30 * (j + 1) + 55, CharToWchar(endtimehour));
		outtextxy(940, 30 * (j + 1) + 55, _T(":"));
		outtextxy(960, 30 * (j + 1) + 55, CharToWchar(endtimeminute));
		outtextxy(130, 35, CharToWchar(total_num));
		outtextxy(850, 35, CharToWchar(page_num));
		outtextxy(920, 35, CharToWchar(page_now));
	}
}

#include "HeadFile.h"
void print_ticket(TicketTableType ticket_table,int i)
{
	IMAGE stu_loading;
	loadimage(&stu_loading, L"Image\\ticketmod.jpg"); //加载背景图片
	putimage(0, 0, &stu_loading);
	int total_time = giventime(ticket_table,i);
	char starttime[10] = { 0 };
	char endtime[10] = { 0 };
	char totalmintue[10] = { 0 };
	char price[10] = { 0 };
	char seatnumber[10] = { 0 };
	char month[10] = { 0 };
	char year[10] = { 0 };
	char day[10] = { 0 };
	char totalhour[10] = { 0 };
	sprintf(seatnumber, "%d", ticket_table.trains_ticket[i].seat_number);
	sprintf(starttime, "%d", ticket_table.trains_ticket[i].start_time.hour);
	sprintf(endtime, "%d", ticket_table.trains_ticket[i].start_time.minute);
	sprintf(year, "%d", ticket_table.trains_ticket[i].travel_date.year);
	sprintf(month, "%d", ticket_table.trains_ticket[i].travel_date.month);
	sprintf(day, "%d", ticket_table.trains_ticket[i].travel_date.day);
	sprintf(price, "%.1f", ticket_table.trains_ticket[i].cost);
	sprintf(totalhour, "%d",total_time/60);
	sprintf(totalmintue, "%d", total_time%60);
	setbkmode(TRANSPARENT);//设置字体背景为透明
	settextcolor(COLORREF(RGB(0, 0, 0)));//设置字体颜色为黑色
	settextstyle(20, 0, _T("楷体"));//设置字体大小20，格式楷体
	outtextxy(87, 75, CharToWchar(ticket_table.trains_ticket[i].start_station));
	outtextxy(250, 84, CharToWchar(totalhour));//总耗时
	outtextxy(260, 84, _T("小时"));
	outtextxy(300, 84, CharToWchar(totalmintue));
	outtextxy(320, 84, _T("分钟"));
	outtextxy(475, 75, CharToWchar(ticket_table.trains_ticket[i].end_station));
	outtextxy(40, 145, CharToWchar(year));
	outtextxy(126,145, CharToWchar(month));
	outtextxy(184, 145, CharToWchar(day));
	outtextxy(230, 145, CharToWchar(starttime));//出发时间
	outtextxy(250, 145, _T(":"));
	outtextxy(260, 145, CharToWchar(endtime));
	outtextxy(65, 184, CharToWchar(price));
	outtextxy(383, 145, CharToWchar(ticket_table.trains_ticket[i].train_name));
	outtextxy(452, 145, CharToWchar(seatnumber));

}
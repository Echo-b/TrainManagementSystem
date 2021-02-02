#include "HeadFile.h"
void output_rest_ticket(train_information* rest_ticket_array,int rest_ticket_arrlen) {
	char total_ticketarr[10] = { 0 };
	char rest_ticketarr[10] = { 0 };
	char starttime[10] = { 0 };
	char endtime[10] = { 0 };
	for (int i = 0; i < rest_ticket_arrlen; i++) {
		outtextxy(0, 20 * i, CharToWchar(rest_ticket_array[i].train_name));
		outtextxy(0, 20 * i, CharToWchar(rest_ticket_array[i].start_station));
		outtextxy(0, 20 * i, CharToWchar(rest_ticket_array[i].end_station));
		sprintf(total_ticketarr, "%d", rest_ticket_array[i].total_ticket);
		sprintf(rest_ticketarr, "%d", rest_ticket_array[i].rest_ticket);
		sprintf(starttime, "%d", rest_ticket_array[i].start_time.hour);
		sprintf(endtime, "%d", rest_ticket_array[i].start_time.minute);
		outtextxy(0, 20 * i, CharToWchar(rest_ticketarr));
		outtextxy(0, 20 * i, CharToWchar(total_ticketarr));
		outtextxy(0, 20 * i, CharToWchar(starttime));
		outtextxy(0, 20 * i, CharToWchar(endtime));
	}
}
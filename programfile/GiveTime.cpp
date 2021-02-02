#include "HeadFile.h"
int giventime(TicketTableType ticket_table,int i) {
	int endhour = ticket_table.trains_ticket[i].arrival_time.hour;
	int endmintue = ticket_table.trains_ticket[i].arrival_time.minute;
	int starthour = ticket_table.trains_ticket[i].start_time.hour;
	int startmintue = ticket_table.trains_ticket[i].start_time.minute;
	return ((endhour - 12) * 60 + endmintue) - ((starthour - 12) * 60 + startmintue);
}
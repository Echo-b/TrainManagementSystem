#include"HeadFile.h"
Status init_passenge_table(PassengerTableType &passenger_table)
{
	if (!(passenger_table.passengers = (Ppassenger)malloc(sizeof(PassengerInf) * MAXLENGTH)))return OVERFLOW;
	passenger_table.num_of_passenger = 0;
	return OK;
}
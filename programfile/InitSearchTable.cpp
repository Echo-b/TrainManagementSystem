#include "HeadFile.h"
Status init_searchtable(PassengerInf& passenger_info)
{
	strcpy(passenger_info.emergency_contact, 0);
	strcpy(passenger_info.emergency_contact_tel, 0);
	strcpy(passenger_info.id_name, 0);
	strcpy(passenger_info.id_number, 0);
	strcpy(passenger_info.id_type, 0);
	passenger_info.is_book = 0;
	strcpy(passenger_info.order_number, 0);
	strcpy(passenger_info.tel_nunmber, 0);
	return OK;
}
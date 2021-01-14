#include"HeadFile.h"
int main()
{
	
	PassengerTableType passenger_table;
	init_passenge_table(passenger_table);
	passenger_read_file(passenger_table, "DataAndExample\\passenger.txt");
	for (int i = 0; i < passenger_table.num_of_passenger; i++) {
		printf("%s\t\t%s\n", passenger_table.passengers[i].id_number,passenger_table.passengers[i].id_name);
	}
	
	return 0;
}
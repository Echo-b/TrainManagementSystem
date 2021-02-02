#include "HeadFile.h"
int givenday(DateType time1, DateType time2) {
	int distanceday = 0;
	if (time1.month == time2.month)
		distanceday = time2.day - time1.day;
	else if (time1.month == 1 && time2.month == 2)
		distanceday = 31 + time2.day - time1.day;
	return distanceday;
}
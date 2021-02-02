#include "HeadFile.h"
Status delet_train(TrainTableType &train_table, const char *input_train_info)
{
	for (int i = 0; i < train_table.num_of_train; i++)
	{
		if (strcmp(train_table.trains[i].train_name, input_train_info) == 0)
		{
			strcpy(train_table.trains[i].train_status, "停运");
		}
	}
	return OK;
}


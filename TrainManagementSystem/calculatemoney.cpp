#include "HeadFile.h"
float calculate_money(TrainTableType &train_table ,Place_Name_Type buy_startsta, Place_Name_Type buy_endsta,const char * buy_seat,Train_Name_Type choose_train)
{
    PStopStation stop_point;
    float total_distance=0;//总里程
    float total_price=0.0;//总价
    int i;
    for (i = 0; i < train_table.size;i++) {
            if (strcmp(train_table.trains[i].train_name,choose_train)&&strcmp(train_table.trains[i].start_station, buy_startsta) == 0) 
             //车次和起始站是否相同，相同开始往停靠站找终到站
                break;
    }
    stop_point = train_table.trains[i].first_stop_station;
    while (strcmp(stop_point->stop_station, buy_endsta) != 0) {
        stop_point = stop_point->next_station;
    }
    total_distance = stop_point->total_distance;//总里程
    if (strcmp(buy_seat, "special") == 0)
        total_price = total_distance * 1.2;//商务座价格
    else if (strcmp(buy_seat, "first_class") == 0)
        total_price = total_distance * 0.6;//一等座价格
    else
        total_price = total_distance * 0.46;//二等座价格
    return total_price;
}

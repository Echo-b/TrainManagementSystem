#include "HeadFile.h"
float calculate_money(Place_Name_Type buy_startsta, Place_Name_Type buy_endsta, wchar_t *buy_seat,Train_Name_Type choose_train)
{
    TrainLink train_point;
    PStopStation stop_point;
    int total_distance=0;//总里程
    float total_price=0.0;//总价
    while (train_point) {
            if (wcscmp(train_point->Data.train_name,choose_train)&&wcscmp(train_point->Data.start_station, buy_startsta) == 0) {//车次和起始站是否相同，相同开始往停靠站找终到站
                stop_point = train_point->Data.first_stop_station;
                break;
            }
        train_point = train_point->next;
    }
    while (stop_point) {
        if (wcscmp(stop_point->stop_station, buy_endsta) != 0) //没找到就一直往后，找到退出
            stop_point = stop_point->next_station;
    }
    total_distance = stop_point->total_distance;//总里程
    if (wcscmp(buy_seat, _T("special")) == 0)
        total_price = total_distance * 1.2;//商务座价格
    else if (wcscmp(buy_seat, _T("first_class")) == 0)
        total_price = total_distance * 0.6;//一等座价格
    else
        total_price = total_distance * 0.46;//二等座价格
    return total_price;
}
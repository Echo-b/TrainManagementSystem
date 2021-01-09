//此头文件包含所有将要用到的头文件、全局变量、结构体、函数声明等

//此处声明头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>

//此处给typedef的定义
typedef char Train_Name_Type[20];
typedef char Name_Type[20];
typedef char Place_Name_Type[20];
typedef char Phone_Number_Type[20];
typedef char ID[30];
typedef char Order_Number_Type[30];

//此处定义结构体（注意结构体的顺序）（不要前面定义的用到后面才定义的）
/*******************************************************************/
//时间结构体，存储时间用于计算进出站总时间
typedef struct time
{
    int hour;
    int minute;
} TimeType;

typedef struct data
{
    int year;
    int month;
    int day;
} DataType;

//座位数量结构体
typedef struct
{
    int special;
    int first_class;
    int second_class;
} SeatNumberType;
//停靠站的节点类型
typedef struct stop_stations
{
    Place_Name_Type stop_station; //停靠站
    TimeType arrival_time;        //到达时间
    TimeType start_time;          //发车时间
    int total_distance;           //里程
    struct stop_stations *next_station;
} * PStopStation, StopStationType;

/*****************************************************************/
//乘客信息
typedef struct passenger_information
{
    ID id_number;                            //证件号
    ID id_name;                              //姓名
    ID id_type;                              //证件类型
    Phone_Number_Type tel_nunmber;           //电话号码
    Name_Type emergency_contact;             //紧急联系人
    Phone_Number_Type emergency_contact_tel; //紧急联系人电话
    int is_book;                             //是否订票0为未定，1为订票
    Order_Number_Type order_number;          //订单号
    struct passenger_information *next;
} PassengerInf, *Ppassenger;
/*****************************************************************/
//火车信息
typedef struct train_information
{
    Train_Name_Type train_name;      //火车的车次
    Place_Name_Type start_station;   //起始站
    Place_Name_Type end_station;     //终到站
    int total_distance;              //总里程
    int train_status;                //高铁状态，是否停运,1正常，0停运
    TimeType start_time;             //发车时间
    TimeType arrival_time;           //到达时间
    int stop_station_number;         //停靠站数量
    SeatNumberType seat;             //不同等级的座位号的数量
    PStopStation first_stop_station; //链接停靠站
    PStopStation frist_passenger;
};
/*******************************************************************/

//车票
typedef struct ticket_information
{
    Order_Number_Type order_number;
    DataType travel_data;          //出发日期
    Train_Name_Type train_name;    //乘坐车次
    Place_Name_Type start_station; //起始站
    Place_Name_Type end_station;   //终到站
    ID id_type;
    ID id_number;
    ID id_name;
    TimeType start_time;
    TimeType arrival_time;
    int seat_level;  //0是特等座，1是一等座，2是二等座
    int seat_number; //座位号
    float cost;      //票价
} Book;
/********************************************************************/
//此处再次给typedef定义（写明每个结构体的变量作用）

//此处给函数声明(注意说明函数功能，每个参数的作用，还有是否对参数动了手脚，返回值类型）（在函数下方写）（不写打死你）

//
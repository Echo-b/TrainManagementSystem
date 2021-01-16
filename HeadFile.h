//此头文件包含所有将要用到的头文件、全局变量、结构体、函数声明等

//此处声明头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include<locale>
#include<fstream>
#include<iostream>
using namespace std;

//此处给出define定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXLENGTH 100 //乘客与火车数组最大长度

//此处给typedef的定义
typedef char Train_Name_Type[20];
typedef char Name_Type[20];
typedef char Place_Name_Type[20];
typedef char Phone_Number_Type[20];
typedef char ID[30];
typedef char Order_Number_Type[30];
typedef char Status;
typedef char StatusType[20];
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
    float total_distance;           //里程
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
    float total_distance;              //总里程
    StatusType train_status;         //高铁状态，是否停运,正常，停运
    TimeType start_time;             //发车时间
    TimeType arrival_time;           //到达时间
    int stop_station_number;         //停靠站数量
    SeatNumberType seat;             //不同等级的座位号的数量
    PStopStation first_stop_station; //链接停靠站
    PStopStation frist_passenger;
} train_information, *PtrainInf;
typedef struct train_node
{
    train_information Data;
    struct train_node *next;
} * TrainLink;
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
//乘客表数据类型
typedef struct {
    Ppassenger passengers;//此处放所有乘客的数据
    int num_of_passenger;//乘客人数
    int size;//当前表大小
}PassengerTableType;
/*******************************************************************/
//火车表结构体
typedef struct {
    PtrainInf trains;//火车数据
    int num_of_train;//火车数量
    int size;//当前表大小
}TrainTableType;
//此处再次给typedef定义（写明每个结构体的变量作用）


//此处给函数声明(注意说明函数功能，每个参数的作用，还有是否对参数动了手脚，返回值类型）（在函数上方写）（不写打死你）
/*****************************************************/
//函数返回输入的两个时间差，前者为开始时间，后者为结束时间，
//返回类型为我们定义的时间类型，未对参数进行改变
TimeType get_time_difference(TimeType start_time, TimeType end_time);
/*****************************************************/
//此函数用于从文件读取乘客信息，第一个函数为读取后所放的位置，第二个为文件名。
//返回值当返回OK时成功，当返回值为ERROR时读取失败
Status passenger_read_file(PassengerTableType& passenger_table, const char *file_name);
/*****************************************************/
//这个看起来超级简单的函数是用来初始化乘客表的函数
//返回值：int类型，OK为成功，OVERFLOW为内存不足
Status init_passenge_table(PassengerTableType& passenger_table);
/*****************************************************/
//此函数为火车文件的读取函数，第一个参数为火车表，第二个为文件名
//当返回OK时表示读取成功，返回ERROR时读取失败
Status train_read_file(TrainTableType& train_table, const char* file_name);
/*****************************************************/
//此函数是简单地初始化火车表，参数为火车表的结构体
//返回值：int类型，当为OK时初始化成功，当为OVERFLOW时初始化失败
Status init_train_table(TrainTableType &train_table);
//此文件是用于计算高铁的票价，参数是乘客的四个输入，起始站，终到站，座位类型以及车次
//返回一个浮点数，对传入的参数不做改动
float calculate_money(Place_Name_Type buy_startsta, Place_Name_Type buy_endsta, wchar_t* buy_seat, Train_Name_Type choose_train);

//此函数用于显示初始界面，暂无返回值和参数
void LoadingFunction();
void RegisterFunction();
void welcoming();
//此函数为获取一个char类型的变量，返回其真值相同的一个wchar类型的变量
//参数为char类型
//返回值为wchar_t类型
wchar_t* CharToWchar(const char* cchar);
//该函数为火车信息写入文件的函数，此函数会将原来的同名文件删除，再新建一个（若没有直接新建）进行写入
//该函数参数1为火车表，第二个参数为文件名
//返回值，返回error就是你电脑没有内存了，输出失败，返回OK表示成功
Status TrainWriteFile(TrainTableType train_table, const char* file_name);
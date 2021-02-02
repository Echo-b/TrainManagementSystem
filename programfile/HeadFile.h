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
#define WIDTH 1080
#define HEIGHT 720

//此处给typedef的定义
typedef char Train_Name_Type[20];
typedef char Name_Type[20];
typedef char Place_Name_Type[20];
typedef char Phone_Number_Type[20];
typedef char ID[30];
typedef char Order_Number_Type[30];
typedef char Status;
typedef char StatusType[20];
typedef char SeatType[20];
//此处定义结构体（注意结构体的顺序）（不要前面定义的用到后面才定义的）
/*******************************************************************/
//时间结构体，存储时间用于计算进出站总时间
typedef struct time
{
    int hour;
    int minute;
} TimeType;
//日期结构体
typedef struct {
    int day, month, year;
}DateType;

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
    Ppassenger frist_passenger;
    int total_ticket;
    int rest_ticket;
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
    DateType travel_date;          //出发日期
    Train_Name_Type train_name;    //乘坐车次
    Place_Name_Type start_station; //起始站
    Place_Name_Type end_station;   //终到站
    ID id_type;
    ID id_number;
    ID id_name;
    TimeType start_time;
    TimeType arrival_time;
    SeatType seat_level;  //0是特等座，1是一等座，2是二等座
    int seat_number; //座位号
    float cost;      //票价
} Book,* Pbook;
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
/*******************************************************************/
typedef struct {
    char account[MAXLENGTH]; 
    char password[MAXLENGTH];
}AccountPassword;
typedef struct {
    Pbook trains_ticket;//车票数据
    int num_of_book;//预定总人数
    int size;//当前表大小
}TicketTableType;
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
float calculate_money(TrainTableType& train_table, Place_Name_Type buy_startsta, Place_Name_Type buy_endsta, const char* buy_seat, Train_Name_Type choose_train);
//此函数用于显示初始界面，暂无返回值和参数
void welcoming();
//此函数为获取一个char类型的变量，返回其真值相同的一个wchar类型的变量
//参数为char类型
//返回值为wchar_t类型
wchar_t* CharToWchar(const char* cchar);
//该函数为火车信息写入文件的函数，此函数会将原来的同名文件删除，再新建一个（若没有直接新建）进行写入
//该函数参数1为火车表，第二个参数为文件名
//返回值，返回error就是你电脑没有内存了，输出失败，返回OK表示成功
Status TrainWriteFile(TrainTableType train_table, const char* file_name);
//此函数为wchar类型转换为char类型的函数
//参数为char的字符串类型，不会对元数据进行更改
//返回值为wchar*的类型
char* WcharToChar(const wchar_t* wchar);
//此函数用于创建账户
//无参数
//返回值始终为0
Status CreatAccount(void);
//此函数用于账号创建的最后一步，输入账号和确认密码
//参数为int类型的creat_flag当为1的时候是创建管理员,当为2时是创建乘客账户
//返回值为1时创建成功，返回0时创建失败
Status AccountToFile(int creat_flag);
//此函数用于选择身份的函数，同时也包含了登录函数
//此函数莫得参数
//返回值未int类型返回 为0时为创建账户，1时为管理员，2为乘客，3为退出,4为忘记密码,-1为选择失败
Status ChooseUser(void);
//此函数用于管理员登录
//参数为标志，1为管理员，2为乘客
//返回1时登录成功，返回0时登录失败
Status Login(int login_flag);
//此函数为管理员主页面的函数
//暂无参数
//返回0退出程序，返回其他都是重新进入选择函数
Status ManagerUser();
//此函数是忘记密码函数
//有空会写的
//我尽量
Status Forgetpassword();
//此函数用于读取票的数据，将数据读入ticket
//此函数有两个参数，第一个为票的表，第二个为文件名
//返回值，返回0时为输入失败，1时为成功
Status TicketReadFile(TicketTableType &ticket_table, const char* file_name, TrainTableType &train_table, PassengerTableType &passenger_table);
//此函数为用户主界面函数
//无参数
//返回0时退出函数，返回1时返回上一级
Status PassengerUser();
//此函数用于从文件读取乘客信息，第一个函数为读取后所放的位置，第二个为文件名。返回值当返回OK时成功，当返回值为ERROR时读取失败
Status ticket_write_file(TicketTableType ticket_table, const char* file_name);
//此函数用于初始化查找的乘客结构体
//参数为乘客信息的结构体
//只返回int类型的1
Status init_searchtable(PassengerInf& passenger_info);
//此函数用于初始化查找火车的结构体
//参数为火车信息的结构体
//返回值为OK只许成功
Status init_search_train(train_information& search_train);
//此函数是简单地初始化火车表，参数为火车表的结构体
//返回值：int类型，当为OK时初始化成功，当为OVERFLOW时初始化失败
Status init_ticket_table(TicketTableType& ticket_table);
//此函数用于返回当前系统时间
//无参数
//返回值类型为系统时间DateType类型
DateType Get_Sys_Time();
//该函数为增加车次的函数
//参数为火车表
//返回值为1
Status AddTrain(TrainTableType& train_table);
//此函数用于比较时间结构体的参数是否相同
//两个参数都为时间结构体变量
//返回0则不同，返回1则相同
int IsTimeSame(TimeType start_time, TimeType end_time);
//此函数用来比较日期结构体是否相同
//两个参数都为日期结构体
//返回值，当返回1时相同，返回0时不同
int IsDateSame(DateType date1, DateType date2);
//该函数为根据信息查找火车函数
//参数第一个为火车表，第二个为带有查找信息的结构体，第三个为存储查找结果的数组
//返回值：当返回OK时表示查找成功，返回ERROR时查找失败
Status search_realated_TraInf(TrainTableType& train_table, train_information input_train_inf, PtrainInf* train_point, int& is_final_number);
//该函数用于根据信息查找票的函数
//参数为乘客数据表和一个输入的参数，可以是出发时间或者证件号，姓名等，查找成功返回一个结构体指针数组首地址
//返回值为OK查找成功，ERROR查找失败
Status search_realated_TickInf(TicketTableType& ticket_table, Book input_ticket_inf, Pbook* ticket_point, int& is_final_number);
//此函数为根据信息查找用户的函数
//参数为乘客数据表和一个输入的参数，可以是紧急联系人或者证件号，姓名等，查找成功返回一个结构体指针数组首地址
//返回值，当返回OK时查找成功，返回ERROR时查找失败
Status search_realated_Pasinf(PassengerTableType& passenger_table, PassengerInf input_realated_info, Ppassenger* passenger_point, int& is_final_number);
//该函数用于停开一列火车
//唯一参数为火车表
//返回值：返回OK代表更改成功，返回ERROR代表更改失败 
Status StopTrain(TrainTableType& train_table);
//此函数用来初始化票的结构体
//传入参数为票的结构体，会对该参数进行修改
//暂定返回值为OK
Status InitTicketSearch(ticket_information& ticket);
//该函数是选择查找的函数
//参数为火车表，乘客表和票的表,和身份信息(1代表管理员，2代表乘客，若需要修改则修改输入参数和下面标注身份的变量
//返回值：暂时只许成功返回OK
Status SearchInf(TrainTableType train_table, PassengerTableType passenger_table, TicketTableType ticket_table, int User);
//该函数为退票函数
//参数为乘客表，火车表，票的表
//返回值默认为OK
Status ReturnTicket(PassengerTableType& passenger_table, TrainTableType& train_table, TicketTableType& ticket_table);
//该函数用于用户获取当前所坐的火车的信息
//参数为火车表
//返回值为OK
Status GetTrainInf(TrainTableType train_table);
//该函数为增加乘客的函数
//参数为火车表
//返回值为1
Status AddPassenger(PassengerTableType& passenger_table);
//此函数用于管理员删除乘客的函数
//参数为乘客表
//返回值：一直返回OK
Status DeletePassenger(PassengerTableType& passenger_table);
//此函数用于计算票价
//返回值为票价
float calculate_money(TrainTableType& train_table, Place_Name_Type buy_startsta, Place_Name_Type buy_endsta, const char* buy_seat, Train_Name_Type choose_train);
//此函数用于订票
//参数暂定
//返回值
int BookTicket();
//该函数为增加车次的函数
//参数为火车表
//返回值为1
Status ModifyPasInf(PassengerTableType& passenger_table);
Status init_searchtable(PassengerInf& passenger_info);
//计算总耗时
int giventime(TicketTableType ticket_table, int i);
//乘客输出，调用passenger_output即可
void passenger_output(PassengerTableType passenger_table);
void passenger_print(PassengerTableType passenger_table, int flag);
//火车输出,调用train_output
void train_print(TrainTableType train_table, int flag);
void train_output(TrainTableType train_table);
//票输出,调用ticket_output即可
void ticket_output(TicketTableType ticket_table);
void ticket_print(TicketTableType ticket_table, int flag);
//余票输出,调用rest_ticket_output
void rest_ticket_output(TrainTableType train_table);
void rest_ticket_print(TrainTableType train_table, int flag);
//打印一张车票，即平常购票的车票样式，i表示要打印的乘客
void print_ticket(TicketTableType ticket_table, int i);
//乘客查找
void passenger_search_print(Ppassenger* result_passenger,int total_num);
//车票查找
void ticket_search_print(Pbook* result_ticket, int total_num);
//火车查找
void train_search_print(PtrainInf* result_train, int total_num);
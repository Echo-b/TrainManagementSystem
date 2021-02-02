#include"HeadFile.h"
//此函数用于测试函数功能
int man()
{
	setlocale(LC_CTYPE, "chs");
	PassengerTableType passenger_table;//乘客文件信息录取测试
	init_passenge_table(passenger_table);
	passenger_read_file(passenger_table, "DataAndExample\\passenger.txt");
	for (int i = 0; i < passenger_table.num_of_passenger; i++) {
		printf("%s\t\t%s\n", passenger_table.passengers[i].id_number,passenger_table.passengers[i].id_name);
	}
	/**************************************************************************************************
	char test_char[80];//控制台中文输入控制
	scanf("%s", test_char);
	printf("%s", test_char);
	/*************************************************************************************************/
	TrainTableType train_table;
	init_train_table(train_table);
	train_read_file(train_table, "DataAndExample\\train.txt");
	for (int i = 0; i < train_table.num_of_train; i++) {
		printf("%s\t%s\n", train_table.trains[i].train_name, train_table.trains[i].start_station);
	}

	
	wchar_t test_wchar2[20];
	wcscpy(test_wchar2, CharToWchar(train_table.trains[2].end_station));
	initgraph(1280, 720); // 1.创建一个宽 640 x高 480 像素的窗口
	IMAGE stu_loading;
	loadimage(&stu_loading, L"Image\\专业的团队.jpg",1280,720); //加载背景图片
	putimage(0, 0, &stu_loading);
	wchar_t test_wchar[] = L"博士傻逼";
	outtextxy(200, 90, test_wchar);
	//initgraph(640, 480, SHOWCONSOLE); // 2.创建一个宽 640 x高 480 像素的窗口,同时显示控制台窗口
	//initgraph(640, 480, SHOWCONSOLE | NOCLOSE); // 3.创建一个宽640 x高480像素的窗口,同时显示控制台窗口,并禁用关闭按钮：
	//outtextxy(0, 10, CharToWchar(train_table.trains[1].end_station)); // 在坐标(0,10)处输出 Hello World! getchar();
	for (int i = 0; i < train_table.num_of_train; i++) {
		outtextxy(50, 10 + 20 * i, CharToWchar(train_table.trains[i].end_station));
		outtextxy(0, 10 + 20 * i, CharToWchar(train_table.trains[i].train_name));
	}
	_getch();

	TrainWriteFile(train_table, "DataAndExample\\test_train_table.txt");
	train_information SearchTrain;
	char test_char[20];
	strcpy(test_char, WcharToChar(test_wchar2));

	

	//outtextxy(0, 10 + 20,);
	return 0;
}
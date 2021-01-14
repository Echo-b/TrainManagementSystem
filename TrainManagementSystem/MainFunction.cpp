//此为主函数
#include "HeadFile.h"
void welcoming()
{
	IMAGE welcome, loading;
	loadimage(&welcome, _T("picture path"));
	putimage(0, 0, &welcome); //显示欢迎界面
	//下面开始是获取用户的鼠标点击并进行相应的跳转
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			if (msg.uMsg == WM_LBUTTONUP)
			{
				Sleep(100); //增加延时，显示点击效果，然后加载另外的界面的图片
				loadimage(&loading, _T("picutre path"));
				putimage(0, 0, &loading);
			}
		}
	}
}
void search_time()
{
	DataType temp_information[20];
}

void search_train()
{
	int position_x, position_y;
	TrainLink point_to_train;
	Train_Name_Type input_train; //临时变量用于获取用户的输入
	InputBox(input_train, 20, _T("请输入你要查询的高铁车次"));
	while (point_to_train)
	{
		if (wcscmp(point_to_train.Data.train_name, input_train) == 0)
		{
			printf("本次查询结果为：\n");
			setbkmode(TRANSPARENT);				  //设置字体背景为透明
			settextcolor(COLORREF(RGB(0, 0, 0))); //设置字体颜色为黑色
			settextstyle(20, 0, _T("楷体"));	  //设置字体大小20，格式楷体
			outtextxy(position_x, position_y, _T("show search result"));
		}
	}
}

void search_station()
{
}

void SearchFunction()
{
	//基本的思路是，首先根据用户鼠标的点击位置，确定函数要查找的是哪一项的内容，比如说按车次，按停靠站之类的，之后获取输入开始检索匹配
	MessageBox(NULL, _T("请点击鼠标相应位置"), _T("功能选择"), MB_ICONSTOP | MB_SETFOREGROUND);
	MOUSEMSG temp_msg;
	IMAGE search_button;
	FlushMouseMsgBuffer();
	while (true)
	{
		while (MouseHit())
		{
			temp_msg = GetMouseMsg();
			if (temp_msg.x)
			{ //具体的坐标在建立图片之后确定
				loadimage(&search_button, _T("picture path"));
				putimage(0, 0, &search_button);
				Sleep(100);
				//接下来实现的是具体的功能
				if ()
					search_train(); //根据车次
				else if ()
					search_station(); //根据车站,起始站，终到站
				else				  //根据发车时间
					search_time();
			}
		}
	}
}
int main()
{
	printf("Hello World!");
}
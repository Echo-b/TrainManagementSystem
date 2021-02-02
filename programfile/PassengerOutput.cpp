#include "HeadFile.h"
void passenger_output(PassengerTableType passenger_table) {
	IMAGE passenger_output_image;
	int temp_flag = 1;//用于显示当前输出的页数,默认输出第一页
	//加载背景输出图片
	loadimage(&passenger_output_image, L"Image\\passengeroutput.png", WIDTH, HEIGHT);
	putimage(0, 0, &passenger_output_image);
	passenger_print(passenger_table, temp_flag);
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if ((msg.x > 0 && msg.x < 120) && (msg.y > 650)&& msg.y < 720) {//点击上一页输出
					//todo调用输出函数
					temp_flag--;
					cleardevice();//清空所有东西
					passenger_print(passenger_table, temp_flag);

				}
				else if ((msg.x > 1000 && msg.x < 1280) && (msg.y > 650 && msg.y < 720)) {
					//点击下一页输出
					//todo调用输出函数
					temp_flag++;
					cleardevice();
					passenger_print(passenger_table, temp_flag);
				}
				else
					return;
			}
		}
	}
}
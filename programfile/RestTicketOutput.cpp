#include "HeadFile.h"
void rest_ticket_output(TrainTableType train_table) {
	IMAGE ticket_output_image;
	int temp_flag = 1;//用于显示当前输出的页数,默认输出第一页
	//加载背景输出图片
	loadimage(&ticket_output_image, L"Image\\restticket.png", WIDTH, HEIGHT);
	putimage(0, 0, &ticket_output_image);
	rest_ticket_print(train_table, temp_flag);
	MOUSEMSG msg;
	FlushMouseMsgBuffer();
	while (true) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				if ((msg.x > 0 && msg.x < 120) && (msg.y > 600) && msg.y < 720) {//点击上一页输出
					//todo调用输出函数
					temp_flag--;
					cleardevice();//清空所有东西
					rest_ticket_print(train_table, temp_flag);

				}
				else if ((msg.x > 900 && msg.x < 1280) && (msg.y > 600 && msg.y < 720)) {
					//点击下一页输出
					//todo调用输出函数
					temp_flag++;
					cleardevice();
					rest_ticket_print(train_table, temp_flag);
				}
				else
					return;
			}
		}
	}
}
#include "HeadFile.h"
void ticket_output(TicketTableType ticket_table) {
	IMAGE ticket_output_image;
	int temp_flag = 1;//用于显示当前输出的页数,默认输出第一页
	//加载背景输出图片
	loadimage(&ticket_output_image, L"Image\\tickeoutput.png", WIDTH, HEIGHT);
	putimage(0, 0, &ticket_output_image);
	ticket_print(ticket_table, temp_flag);
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
					ticket_print(ticket_table, temp_flag);

				}
				else if ((msg.x > 900 && msg.x < 1280) && (msg.y > 600 && msg.y < 720)) {
					//点击下一页输出
					//todo调用输出函数
					temp_flag++;
					cleardevice();
					ticket_print(ticket_table, temp_flag);
				}
				else
					return;
			}
		}
	}
}
#include "HeadFile.h"
//此函数用于选择身份的函数，同时也包含了登录函数
//此函数莫得参数
//返回值未int类型返回 为0时为创建账户，1时为管理员，2为乘客，3为退出,4为忘记密码,-1为选择失败
Status ChooseUser(void)
{
	IMAGE img;
	loadimage(&img, L"Image\\chooseuser.jpg", WIDTH, HEIGHT);
	
	MOUSEMSG mouse;
	FlushMouseMsgBuffer();
	while (true)
	{
		putimage(0, 0, &img);
		while (MouseHit())
		{	
			mouse = GetMouseMsg();
			printf("ChooseUser: x=%d,y=%d,%d\n", mouse.x, mouse.y, mouse.uMsg);
			if (WM_LBUTTONDOWN == mouse.uMsg)
			{ //todo加上位置
				if (mouse.x > 156 /*position*/ && mouse.x < 437 /*position*/ && mouse.y > 267 /*position*/ && mouse.y < 362 /*position*/)
				{
					if (Login(1))
					{ //进入管理员登录函数
						return 1;
					}
					else
					{
						return -1;
					}
				}
				else if (mouse.x > 839 /*position*/ && mouse.x < 1140 /*position*/ && mouse.y > 267 /*position*/ && mouse.y < 362 /*position*/)
				{
					if (Login(2))
					{ //进入乘客登录函数
						return 2;
					}
					else
						return -1;
				}
				else if (mouse.x > 1131 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 629 /*position*/ && mouse.y < 720 /*position*/)
				{
					return 0; //创建账户
				}
				else if (mouse.x > 0 /*position*/ && mouse.x < 147 /*position*/ && mouse.y > 629 /*position*/ && mouse.y < 720 /*position*/)
				{
					return 3; //退出
				}
				else if (mouse.x > 0 /*position*/ && mouse.x < 0 /*position*/ && mouse.y > 0 /*position*/ && mouse.y < 0 /*position*/)
				{
					return 4; //忘记密码（哦，我知道了）
				}
			}
		}
	}
}
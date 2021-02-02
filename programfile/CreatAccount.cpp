#include "HeadFile.h"
//此函数用于创建账户
//无参数
//返回值始终为0
Status CreatAccount(void)
{
	FILE *fp_account;
	FILE *fp_password;
	int creat_flag = -1;					   //当为1时注册管理员，当为2时乘客注册
	wchar_t manager_creat_password[MAXLENGTH]; //管理员创建暗号
	char tempchar[MAXLENGTH];				   //用来暂存管理员暗号
	char tempwchar[20];
	char account[MAXLENGTH];
	char password[MAXLENGTH];
	fp_account = fopen("DataAndExample\\Acount.txt", "r");
	fscanf(fp_account, "%s", tempchar); //管理员暗号输入
	fclose(fp_account);					//关闭管理员文件
	MOUSEMSG mouse;
	FlushMouseMsgBuffer(); //清空鼠标缓存
	IMAGE choose_face;	   //需要加载的选择页面（选择注册管理员还是乘客）
	loadimage(&choose_face, L"Image\\chooseregister.jpg", WIDTH, HEIGHT);
	while (true)
	{
		putimage(0, 0, &choose_face);
		while (true)
		{
			while (MouseHit())
			{						   //检测鼠标运动
				mouse = GetMouseMsg(); //获得鼠标信息
				if (WM_LBUTTONDOWN == mouse.uMsg)
				{ //当鼠标点击后
					if (mouse.x > 258 /*position*/ && mouse.x < 519 /*position*/ && mouse.y > 376 /*position*/ && mouse.y < 485 /*position*/)
					{					//当选择管理员注册时
						creat_flag = 1; //进入注册管理员账号的页面
						if (InputBox(manager_creat_password, MAXLENGTH, L"请输入管理员注册暗号", 0, 0, false))
						{
							while (wcscmp(manager_creat_password, CharToWchar(tempchar)))
								if (AccountToFile(creat_flag))
								{
									//todo输出注册成功（并停留一小会或者摁键继续（摁键继续可以_getch)
									MessageBox(NULL, _T("注册成功"), _T("最终结果"), MB_OKCANCEL);
									Sleep(300);
									return 0; //这个return不要删，不然死循环
								}
								else
								{
									//todo输出注册失败（并停留一小会或者摁键继续（摁键继续可以_getch)
									MessageBox(NULL, _T("注册失败"), _T("最终结果"), MB_OKCANCEL);
									Sleep(300);
									return 0; //这个return不要删，不然死循环
								}
						}
					}
					else if (mouse.x > 853 /*position*/ && mouse.x < 1102 /*position*/ && mouse.y > 376 /*position*/ && mouse.y < 485 /*position*/)
					{ //当选取乘客创建的时候
						creat_flag = 2;
						if (AccountToFile(creat_flag))
						{
							//todo输出注册成功（并停留一小会或摁键继续）
							MessageBox(NULL, _T("注册成功"), _T("最终结果"), MB_OKCANCEL);
							Sleep(300);
							return 0;
						}
						else
						{
							//todo输出注册失败（并停留一小会或摁键继续）
							MessageBox(NULL, _T("注册成功"), _T("最终结果"), MB_OKCANCEL);
							Sleep(300);
							return 0;
						}
					}
					else if (mouse.x > 1138 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 631 /*position*/ && mouse.y < 720 /*position*/)
					{ //当摁到退出的时候
						return 0;
					}
				}
			}
		}
	}
}
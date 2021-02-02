#include "HeadFile.h"
//此函数用于管理员登录
//参数为标志，1为管理员，2为乘客
//返回1时登录成功，返回0时登录失败
Status Login(int login_flag)
{
	IMAGE login;
	loadimage(&login, L"Image\\login.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &login);
	MOUSEMSG mouse; //鼠标信息
	
	wchar_t tempwchar[MAXLENGTH];  //暂存wchar类型
	wchar_t tempwchar2[MAXLENGTH]; //暂存wchar类型
	char tempchar[MAXLENGTH];
	int account_flag=0;			   //判断是否输入账号
	int password_flag=0;			//判断是否输入密码
	char account[MAXLENGTH];	   //用户输入的账号
	char password[MAXLENGTH];	   //用户输入的密码
	char file_account[MAXLENGTH];  //已注册的账号
	char file_password[MAXLENGTH]; //已注册的密码
	int account_exist;			   //用来判断账号是否存在的
	FlushMouseMsgBuffer();
	while (true)
	{
			mouse = GetMouseMsg();
			printf("login:x=%d,y=%d,%d\n", mouse.x, mouse.y, mouse.uMsg);
			if (WM_LBUTTONDOWN == mouse.uMsg)
			{
				if (mouse.x > 586 /*position*/ && mouse.x < 771 /*position*/ && mouse.y > 310 /*position*/ && mouse.y < 348 /*position*/)
				{ //当点击输入账号的时候
					if (InputBox(tempwchar, MAXLENGTH, L"请输入您要登录的账号", 0, 0, false))
					{
						account_flag = 1;
						strcpy(account, WcharToChar(tempwchar));
						//todo增加一个输入成功的显示
						//MessageBox(NULL, _T("输入成功"), _T("最终结果"), MB_OKCANCEL);
					}
				}
				else if (mouse.x > 586 /*position*/ && mouse.x < 771 /*position*/ && mouse.y > 382 /*position*/ && mouse.y < 424 /*position*/)
				{ //当点击到输入密码时
					if (InputBox(tempwchar, MAXLENGTH, L"请输入你的密码", 0, 0, false))
					{
						strcpy(password, WcharToChar(tempwchar));
						password_flag = 1;
					}
				}
				else if (mouse.x > 764 /*position*/ && mouse.x < 852 /*position*/ && mouse.y > 611 /*position*/ && mouse.y < 660 /*position*/)
				{					   //当点击确认时
					account_exist = 0; //将账号存在的标志初始化为0（0代表没有该账号）
					if (account_flag == 0 && password_flag == 0)
					{ //账号密码都未输入的情况
						//todo显示账号和密码未输入（弹窗显示即可）
						MessageBox(NULL, _T("账号密码未输入"), _T("最终结果"), MB_OKCANCEL);
					}
					else if (account_flag == 0)
					{ //当未输入账号时
						//显示账号未输入
						MessageBox(NULL, _T("账号未输入"), _T("最终结果"), MB_OKCANCEL);
					}
					else if (password_flag == 0)
					{ //当未输入密码时
						//显示密码未输入
						MessageBox(NULL, _T("密码未输入"), _T("最终结果"), MB_OKCANCEL);
					}
					else
					{
						FILE *fp; //用于打开管理员账号和密码文件的东西
						if (login_flag == 1)
						{
							fp = fopen("DataAndExample\\manager.txt", "r");
							fscanf(fp, "%s", tempchar); //把暗号读掉
						}
						else
						{
							fp = fopen("DataAndExample\\passengeruser.txt", "r");
						}
						while (fscanf(fp, "%s", file_account) != -1)
						{
							fscanf(fp, "%s", file_password);
							if (!strcmp(file_account, account))
							{
								if (!strcmp(file_password, password))
								{
									fclose(fp);
									//todo显示一个登录成功
									MessageBox(NULL, _T("登录成功"), _T("最终结果"), MB_OKCANCEL);
									return OK;
								}
								else
								{
									//显示一个密码错误
									MessageBox(NULL, _T("密码错误"), _T("最终结果"), MB_OKCANCEL);
									account_exist = 1;
									break;
								}
							}
						}
						if (account_exist == 0)
						{
							//显示账号不存在
							MessageBox(NULL, _T("账号不存在"), _T("最终结果"), MB_OKCANCEL);
						}
					}
				}
				else if (mouse.x > 447 /*position*/ && mouse.x < 541 /*position*/ && mouse.y > 610 /*position*/ && mouse.y < 655 /*position*/)
				{
					return ERROR; //退出登录的情况
				}
			}
		
	}
}
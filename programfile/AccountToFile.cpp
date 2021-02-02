#include"HeadFile.h"
//此函数用于账号创建的最后一步，输入账号和确认密码
//参数为int类型的creat_flag当为1的时候是创建管理员,当为2时是创建乘客账户
//返回值为1时创建成功，返回0时创建失败
Status AccountToFile(int creat_flag)
{
	MOUSEMSG mouse;
	FlushMouseMsgBuffer();
	IMAGE account_password_choose;
	loadimage(&account_password_choose, L"Image\\signup.jpg", WIDTH, HEIGHT);
	int account_flag = 0;
	int password_flag = 0;
	char account[MAXLENGTH];
	char password[MAXLENGTH];
	wchar_t tempwchar[MAXLENGTH];
	wchar_t tempwchar2[MAXLENGTH];
	FILE* fp;
	if (creat_flag == 1) {//根据creat_flag判断打开文件
		fp = fopen("DataAndExample\\manager", "a+");
	}
	else {
		fp = fopen("DataAndExample\\passenger", "a+");
	}
	fprintf(fp, "\n");
	while (true) {
		while (MouseHit()) {
			mouse = GetMouseMsg();
			if (WM_LBUTTONDOWN == mouse.uMsg) {
				if (mouse.x > 577/*position*/ && mouse.x < 760/*position*/ && mouse.y>298/*position*/ && mouse.y < 341/*position*/) {//当点击输入账号的时候
					if (InputBox(tempwchar, MAXLENGTH, L"请输入您要注册的账号", 0, 0, false)) {
						account_flag = 1;
						strcpy(account, WcharToChar(tempwchar));
						//todo增加一个输入成功的显示
						MessageBox(NULL, _T("输入成功"), _T("最终结果"), MB_OKCANCEL);
					}
				}
				else if (mouse.x > 577/*position*/ && mouse.x < 760/*position*/ && mouse.y>370/*position*/ && mouse.y < 412/*position*/) {//当点击到输入密码时
					if (InputBox(tempwchar, MAXLENGTH, L"请输入你的密码", 0, 0, false)) {
						if (InputBox(tempwchar2, MAXLENGTH, L"请确认你的密码", 0, 0, false)) {
							if (wcscmp(tempwchar, tempwchar2)) {
								password_flag = 1;
								strcpy(password, WcharToChar(tempwchar));
								//todo增加一个密码创建成功的显示（弹窗显示即可
								MessageBox(NULL, _T("密码创建成功成功"), _T("最终结果"), MB_OKCANCEL);
							}
							else {
								//todo增加一个两次密码不一致的显示（弹窗显示即可
								MessageBox(NULL, _T("密码不一致"), _T("最终结果"), MB_OKCANCEL);
							}
						}
					}
				}
				else if (mouse.x > 440/*position*/ && mouse.x < 527/*position*/ && mouse.y>595/*position*/ && mouse.y < 644/*position*/) {//当点击确认时
					if (account_flag == 0 && password_flag == 0) {//账号密码都未输入的情况
						//todo显示账号和密码未输入（弹窗显示即可）
						MessageBox(NULL, _T("账号密码未输入"), _T("最终结果"), MB_OKCANCEL);
					}
					else if (account_flag == 0) {//当未输入账号时
						//显示账号未输入
						MessageBox(NULL, _T("账号未输入"), _T("最终结果"), MB_OKCANCEL);
					}
					else if (password_flag == 0) {//当未输入密码时
						//显示密码未输入
						MessageBox(NULL, _T("密码未输入"), _T("最终结果"), MB_OKCANCEL);
					}
					else {
						fprintf(fp, "%s %s", account, password);
						fclose(fp);
						return OK;
					}
				}
				else if (mouse.x > 757/*position*/ && mouse.x < 840/*position*/ && mouse.y>595/*position*/ && mouse.y < 644/*position*/) {
					return ERROR;//没有注册成功的情况下
				}
			}
		}
	}	
}

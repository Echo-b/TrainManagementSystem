//此为主函数
#include "HeadFile.h"
int main()
{
	initgraph(WIDTH, HEIGHT, EW_SHOWCONSOLE);

	int user_flag = -1;//用户身份标志
	while (1) {//账号密码的输入
		user_flag = ChooseUser();//选择自己的身份(返回值为0时为创建账户，1时为管理员，2为乘客，3为退出,4为忘记密码）
		if (user_flag == 0) {
			CreatAccount();//此处放一个创建账户的函数，无论创建成功与否，返回后都会到选择自己身份的界面
		}
		else if (user_flag == 1) {//进入管理员页面
			if (!ManagerUser())break;
		}
		else if(user_flag==2){//进入乘客页面（返回0直接退出程序）（返回其他重新进入选择身份页面）
			if (!PassengerUser())break;
		}
		else if (user_flag == 3) {//退出
			break;
		}
		else if (user_flag == 4) {//忘记密码
			Forgetpassword();
		}
	}
	IMAGE quit;
	loadimage(&quit, L"Image\\quit.jpg",WIDTH,HEIGHT);
	putimage(0, 0, &quit);
	_getch();
	return 0; 
}
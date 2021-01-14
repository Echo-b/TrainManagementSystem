#include "HeadFile.h"
void LoadingFunction()
{
    Name_Type user_name, user_password;
    IMAGE stu_loading;
    loadimage(&stu_loading, _T("stu_loading.jpg")); //加载背景图片
    putimage(0, 0, &stu_loading);
    InputBox(user_name, 20, _T("请输入用户名"));
    //Todo 检索文件，查看是否存在此用户，对应输出
    if (true)
    {
        InputBox(user_password, 20, _T("请输入密码"));
        //Todo 检索文件，查看此用户对应的密码是否正确，对应给出提示
        if (true)
        {
            //Todo 进入系统，即调用相应的函数
        }
    }
}
void RegisterFunction()
{
    IMAGE stu_register;
    loadimage(&stu_register, _T("stu_register.jpg")); //加载背景图片
    putimage(0, 0, &stu_register);
    Name_Type register_name; //声明一个临时变量用于接收用户输入，进行注册
    Name_Type register_password;
    FILE* fp; //用于储存注册的用户信息
    InputBox(register_name, 20, _T("请输入用户名"));
    InputBox(register_password, 20, _T("请输入密码")); //之后可以增加一个密码强弱性判断，并提示用户是否需要进行更改
    fopen_s(&fp, "registerinformation.txt", "wt");     //写入文件中
    fwrite(&register_name, sizeof(register_name), 1, fp);
    fwrite(&register_password, sizeof(register_password), 1, fp);
}
void welcoming()
{
    IMAGE welcome_images;
    IMAGE loading_button, register_button; //登录和注册按钮
    loadimage(&welcome_images, _T("welcome_images"));
    putimage(0, 0, &welcome_images); //显示欢迎界面
    //下面开始是获取用户的鼠标点击并进行相应的跳转
    MOUSEMSG msg;
    FlushMouseMsgBuffer(); //清空之前的鼠标消息
    while (true)
    {
        while (MouseHit())
        {
            msg = GetMouseMsg();          //获取鼠标消息
            if (msg.uMsg == WM_LBUTTONUP) //左键按下
            {
                //Todo 判断鼠标的点击范围，登录则跳转登录界面，否则进入注册界面
                if (true)
                {
                    //或者注册按钮和登录按钮也可以直接用easyx直接画在图片上
                    loadimage(&loading_button, _T("picutre path"));
                    putimage(0, 0, &loading_button);
                    Sleep(100);        //增加延时，显示点击效果，然后加载另外的界面的图片
                    LoadingFunction(); //进入登录界面
                }
                else
                {
                    loadimage(&register_button, _T("picutre path"));
                    putimage(0, 0, &register_button);
                    Sleep(100);         //增加延时，显示点击效果，然后加载另外的界面的图片
                    RegisterFunction(); //进入注册界面
                }
            }
        }
    }
}
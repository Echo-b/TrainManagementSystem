#include "HeadFile.h"
//此函数用于显示初始界面，暂无返回值和参数
void welcoming()
{
    initgraph(626,417);
    IMAGE welcome_images;
    loadimage(&welcome_images, L"Image\\background.jpg");
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
                if (msg.x > 538 && msg.x < 607 && msg.y>366 && msg.y < 410)
                {
                    ;
                }
            }
        }
    }
}

#include "HeadFile.h"
void LoadingFunction()
{
    Name_Type user_name, user_password;
    IMAGE stu_loading;
    loadimage(&stu_loading, _T("stu_loading.jpg")); //���ر���ͼƬ
    putimage(0, 0, &stu_loading);
    InputBox(user_name, 20, _T("�������û���"));
    //Todo �����ļ����鿴�Ƿ���ڴ��û�����Ӧ���
    if (true)
    {
        InputBox(user_password, 20, _T("����������"));
        //Todo �����ļ����鿴���û���Ӧ�������Ƿ���ȷ����Ӧ������ʾ
        if (true)
        {
            //Todo ����ϵͳ����������Ӧ�ĺ���
        }
    }
}
void RegisterFunction()
{
    IMAGE stu_register;
    loadimage(&stu_register, _T("stu_register.jpg")); //���ر���ͼƬ
    putimage(0, 0, &stu_register);
    Name_Type register_name; //����һ����ʱ�������ڽ����û����룬����ע��
    Name_Type register_password;
    FILE* fp; //���ڴ���ע����û���Ϣ
    InputBox(register_name, 20, _T("�������û���"));
    InputBox(register_password, 20, _T("����������")); //֮���������һ������ǿ�����жϣ�����ʾ�û��Ƿ���Ҫ���и���
    fopen_s(&fp, "registerinformation.txt", "wt");     //д���ļ���
    fwrite(&register_name, sizeof(register_name), 1, fp);
    fwrite(&register_password, sizeof(register_password), 1, fp);
}
void welcoming()
{
    IMAGE welcome_images;
    IMAGE loading_button, register_button; //��¼��ע�ᰴť
    loadimage(&welcome_images, _T("welcome_images"));
    putimage(0, 0, &welcome_images); //��ʾ��ӭ����
    //���濪ʼ�ǻ�ȡ�û����������������Ӧ����ת
    MOUSEMSG msg;
    FlushMouseMsgBuffer(); //���֮ǰ�������Ϣ
    while (true)
    {
        while (MouseHit())
        {
            msg = GetMouseMsg();          //��ȡ�����Ϣ
            if (msg.uMsg == WM_LBUTTONUP) //�������
            {
                //Todo �ж����ĵ����Χ����¼����ת��¼���棬�������ע�����
                if (true)
                {
                    //����ע�ᰴť�͵�¼��ťҲ����ֱ����easyxֱ�ӻ���ͼƬ��
                    loadimage(&loading_button, _T("picutre path"));
                    putimage(0, 0, &loading_button);
                    Sleep(100);        //������ʱ����ʾ���Ч����Ȼ���������Ľ����ͼƬ
                    LoadingFunction(); //�����¼����
                }
                else
                {
                    loadimage(&register_button, _T("picutre path"));
                    putimage(0, 0, &register_button);
                    Sleep(100);         //������ʱ����ʾ���Ч����Ȼ���������Ľ����ͼƬ
                    RegisterFunction(); //����ע�����
                }
            }
        }
    }
}
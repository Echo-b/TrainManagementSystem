#include "HeadFile.h"
//该函数为增加乘客的函数
//参数为火车表
//返回值为1
Status AddPassenger(PassengerTableType &passenger_table)
{
    PassengerInf passenger_temp;
    init_searchtable(passenger_temp);
    wchar_t tempwchar1[MAXLENGTH];
    wchar_t tempwchar2[MAXLENGTH];
    MOUSEMSG mouse;
    FlushMouseMsgBuffer();
    IMAGE img;
    loadimage(&img, L"Image\\addpassenger.jpg", WIDTH, HEIGHT);
    
    while (true)
    {
        putimage(0, 0, &img);
        while (MouseHit())
        {
            mouse = GetMouseMsg();
            if (WM_LBUTTONDOWN == mouse.uMsg)
            {
                if (mouse.x > 249 /*position*/ && mouse.x < 402 /*position*/ && mouse.y > 173 /*position*/ && mouse.y < 249 /*position*/)
                { //点击输入车次时
                    if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要增加证件号", L"证件", NULL, 0, 0, false))
                    {
                        strcpy(passenger_temp.id_number, WcharToChar(tempwchar1));
                    }
                }
                else if (mouse.x > 249 /*position*/ && mouse.x < 402 /*position*/ && mouse.y > 359 /*position*/ && mouse.y < 429 /*position*/)
                {
                    if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要增加的姓名", L"姓名", NULL, 0, 0, false))
                    {
                        strcpy(passenger_temp.id_name, WcharToChar(tempwchar1));
                    }
                }
                else if (mouse.x > 249 /*position*/ && mouse.x < 402 /*position*/ && mouse.y > 525 /*position*/ && mouse.y < 595 /*position*/)
                {
                    if (InputBox(tempwchar1, MAXLENGTH, L"请输入新增的证件类型", L"证件类型", NULL, 0, 0, false))
                    {
                        strcpy(passenger_temp.id_type, WcharToChar(tempwchar1));
                    }
                }
                else if (mouse.x > 834 /*position*/ && mouse.x < 991 /*position*/ && mouse.y > 175 /*position*/ && mouse.y < 244 /*position*/)
                {
                    if (InputBox(tempwchar1, MAXLENGTH, L"请输入新增的电话号码",L"电话号码", NULL, 0, 0, false))
                    {
                        strcpy(passenger_temp.tel_nunmber, WcharToChar(tempwchar1));
                    }
                }
                else if (mouse.x > 834 /*position*/ && mouse.x < 991 /*position*/ && mouse.y > 357 /*position*/ && mouse.y < 430 /*position*/)
                {
                    if (InputBox(tempwchar1, MAXLENGTH, L"请输入新增的紧急联系人", L"紧急联系人", NULL, 0, 0, false))
                    {
                        strcpy(passenger_temp.emergency_contact, WcharToChar(tempwchar1));
                    }
                }
                else if (mouse.x > 838 /*position*/ && mouse.x < 992 /*position*/ && mouse.y > 525 /*position*/ && mouse.y < 596 /*position*/)
                {
                    if (InputBox(tempwchar1, MAXLENGTH, L"请输入新增的紧急联系人电话号码", _T("紧急联系人电话号码"), NULL, 0, 0, false))
                    {
                        strcpy(passenger_temp.emergency_contact_tel, WcharToChar(tempwchar1));
                    }
                }
                else if (mouse.x > 1171 /*position*/ && mouse.x < 1280/*position*/ && mouse.y > 650 /*position*/ && mouse.y < 720 /*position*/)
                {
                    passenger_table.passengers[passenger_table.num_of_passenger] = passenger_temp; //摁确定后
                    passenger_table.num_of_passenger++;
                    //todo显示添加成功
                    //MessageBox(NULL, L"更改成功", L"最终结果", MB_OKCANCEL);
                    return OK;
                }
                else if (mouse.x > 0 /*position*/ && mouse.x < 108 /*position*/ && mouse.y > 650 /*position*/ && mouse.y < 720 /*position*/)
                {
                    //点击退出添加
                    //todo显示添加失败
                    //MessageBox(NULL, _T("添加失败"), _T("最终结果"), MB_OKCANCEL);
                    return OK;
                }
            }
        }
    }
}
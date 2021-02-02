#include "HeadFile.h"
//该函数为增加车次的函数
//参数为火车表
//返回值为1
Status ModifyPasInf(PassengerTableType &passenger_table)
{
    return 0;
    //PassengerInf search_passenger;
    //init_searchtable(search_passenger);
    //Ppassenger result_passenger[MAXLENGTH]; //乘客查找结果存放处
    //wchar_t tempwchar1[MAXLENGTH];
    //wchar_t tempwchar2[MAXLENGTH];
    //MOUSEMSG mouse;
    //FlushMouseMsgBuffer();
    //while (true)
    //{
    //    while (MouseHit())
    //    {
    //        mouse = GetMouseMsg();
    //        if (WM_LBUTTONDOWN == mouse.uMsg)
    //        {
    //            if (mouse.x > 246 /*position*/ && mouse.x < 400 /*position*/ && mouse.y > 177 /*position*/ && mouse.y < 242 /*position*/)
    //            { //点击输入车次时
    //                if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要修改的证件号", L"证件", NULL, 0, 0, false))
    //                {
    //                    strcpy(search_passenger.id_number, WcharToChar(tempwchar1));
    //                    if (search_realated_Pasinf(passenger_table,search_passenger,result_passenger))
    //                    {
    //                        InputBox(tempwchar2, MAXLENGTH, L"请输入修改后的证件号", L"证件号", NULL, 0, 0, false);
    //                        strcpy(result_passenger[0]->id_number, WcharToChar(tempwchar2));
    //                    }
    //                }
    //            }
    //            else if (mouse.x > 246 /*position*/ && mouse.x < 400 /*position*/ && mouse.y > 356 /*position*/ && mouse.y < 430 /*position*/)
    //            {
    //                if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要修改的姓名", L"姓名", NULL, 0, 0, false))
    //                {
    //                    strcpy(search_passenger.id_name, WcharToChar(tempwchar1));
    //                    if (search_realated_Pasinf(passenger_table,search_passenger,result_passenger))
    //                    {
    //                        InputBox(tempwchar2, MAXLENGTH, L"请输入修改后的姓名", L"姓名", NULL, 0, 0, false);
    //                        strcpy(result_passenger[0]->id_name, WcharToChar(tempwchar2));
    //                    }
    //                }
    //            }
    //            else if (mouse.x > 246 /*position*/ && mouse.x < 400 /*position*/ && mouse.y > 528 /*position*/ && mouse.y < 600 /*position*/)
    //            {
    //                if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要修改的证件类型", L"证件类型", NULL, 0, 0, false))
    //                {
    //                    strcpy(search_passenger.id_type,WcharToChar(tempwchar1));
    //                    if (search_realated_Pasinf(passenger_table,search_passenger,result_passenger))
    //                    {
    //                        InputBox(tempwchar2, MAXLENGTH, L"请输入修改后的证件类型", L"证件类型", NULL, 0, 0, false);
    //                        strcpy(result_passenger[0]->id_type, WcharToChar(tempwchar2));
    //                    }
    //                }
    //            }
    //            else if (mouse.x > 825 /*position*/ && mouse.x < 987 /*position*/ && mouse.y > 177 /*position*/ && mouse.y < 242 /*position*/)
    //            {
    //                if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要修改的电话号码", L"电话号码", NULL, 0, 0, false))
    //                {
    //                    strcpy(search_passenger.tel_nunmber, WcharToChar(tempwchar1));
    //                    if (search_realated_Pasinf(passenger_table,search_passenger,result_passenger))
    //                    {
    //                        InputBox(tempwchar2, MAXLENGTH, L"请输入修改后的电话号码", L"电话号码", NULL, 0, 0, false);
    //                        strcpy(result_passenger[0]->tel_nunmber, WcharToChar(tempwchar2));
    //                    }
    //                }
    //            }
    //            else if (mouse.x > 825 /*position*/ && mouse.x < 987 /*position*/ && mouse.y > 356 /*position*/ && mouse.y < 430 /*position*/)
    //            {
    //                if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要修改的紧急联系人", L"紧急联系人", NULL, 0, 0, false))
    //                {
    //                    strcpy(search_passenger.emergency_contact, WcharToChar(tempwchar1));
    //                    if (search_realated_Pasinf(passenger_table,search_passenger,result_passenger))
    //                    {
    //                        InputBox(tempwchar2, MAXLENGTH, L"请输入修改后的紧急联系人", L"紧急联系人", NULL, 0, 0, false);
    //                        strcpy(result_passenger[0]->emergency_contact, WcharToChar(tempwchar2));
    //                    }
    //                }
    //            }
    //            else if (mouse.x > 825 /*position*/ && mouse.x < 987 /*position*/ && mouse.y > 528 /*position*/ && mouse.y < 600 /*position*/)
    //            {
    //                if (InputBox(tempwchar1, MAXLENGTH, L"请输入需要修改的紧急联系人电话号码", L"紧急联系人电话号码", NULL, 0, 0, false))
    //                {
    //                    strcpy(search_passenger.emergency_contact_tel, WcharToChar(tempwchar1));
    //                    if (search_realated_Pasinf(passenger_table,search_passenger, result_passenger))
    //                    {
    //                        InputBox(tempwchar2, MAXLENGTH, L"请输入修改后的紧急联系人电话", L"紧急联系人电话号码", NULL, 0, 0, false);
    //                        strcpy(result_passenger[0]->id_number, WcharToChar(tempwchar2));
    //                    }
    //                }
    //            }
    //            else if (mouse.x > 1175 /*position*/ && mouse.x < 1280 /*position*/ && mouse.y > 653 /*position*/ && mouse.y < 720 /*position*/)
    //            {
    //                //点击确定按钮
    //                //todo显示修改成功
    //                //MessageBox(NULL, _T("修改成功"), _T("最终结果"), MB_OKCANCEL);
    //                return OK;
    //            }
    //            else if (mouse.x > 0 /*position*/ && mouse.x < 105 /*position*/ && mouse.y > 653 /*position*/ && mouse.y < 720 /*position*/)
    //            {
    //                //点击退出修改
    //                //todo显示修改失败
    //                //MessageBox(NULL, _T("修改失败"), _T("最终结果"), MB_OKCANCEL);
    //                return OK;
    //            }
    //        }
    //    }
    //}
}
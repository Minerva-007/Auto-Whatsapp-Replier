#include"windows.h"
#include"windowsx.h"
#include"stdlib.h"
#include"stdio.h"
#include"string.h"
//371,529-381,539
//Size is 10,10
//Color is 04d759

void Lclick(int x, int y)
{
     PostMessage((HWND)0xffff, WM_LBUTTONDOWN, 1, (y<<16)+x);
     PostMessage((HWND)0xffff, WM_LBUTTONUP, 0, (y<<16)+x);
}
     
void typemessage(char* str)
{
     int i=0;
     int arr[]={1048577,1114113,1179649,1245185,1310721,1376257,1441793,1507329,1572865,1638401,1966081,2031617,2097153,2162689,2228225,2293761,2359297,2424833,2490369,2883585,2949121,3014657,3080193,3145729,3211265,3276801,3735553};
     char index[]="QWERTYUIOPASDFGHJKLZXCVBNM ";
     while(*(str+i)!=0)
     {
                       char ch[2];
                       ch[0]=*(str+i);ch[1]=0x00;
                       int scancode=arr[(strstr(index, ch)-index)];
                       PostMessage((HWND)0xffff, WM_KEYDOWN, *(str+i), scancode);
                       PostMessage((HWND)0xffff, WM_KEYUP, *(str+i), 0xc0000000+scancode);
                       i++;
     }
     PostMessage((HWND)0xffff, WM_KEYDOWN, VK_RETURN, 0x1c0001);
     PostMessage((HWND)0xffff, WM_KEYUP, VK_RETURN, 0xc01c0001);
}


void Reply()
{
     printf("lo g fer gori aaya");
     Lclick(270,530);
     Sleep(1000);
     char* messages[]={"YE TO HOGA", "MAIN NAHI BATAUN GA", "AB YE TO KISI KITAAB MAIN NAHI", "NEPAL JAUN GA TO MR JAUN GA", "MR GYA INTEQAAL", "NO TEXT THIS TIME", "JUST MONIKA", "MAAR GYI UDEEK MENU DE GYA TAREEK MERA TOLA", "TERE ISHQ NE NACHAYA THAIYAN THAIYAN", "RUL TE GYE AAN PR CHASS BRI AAYI AE"};
     typemessage(messages[rand()%10]);
     Lclick(270, 450);
}
 

int main()
{
             HDC hdc=GetDC(0);
             HDC hmemdc=CreateCompatibleDC(hdc);
             HBITMAP hbmp=CreateCompatibleBitmap(hdc, 10, 10);
             SelectObject(hmemdc, hbmp);
             BITMAPINFO bmi={0};
           	 bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
             GetDIBits(hmemdc, hbmp, 0, 0, 0, &bmi, DIB_RGB_COLORS);
             n:while(1)
             {
                     int arr[10][10];
                     BitBlt(hmemdc, 0, 0, 10, 10, hdc, 371, 529, SRCCOPY);
                     GetDIBits(hmemdc, hbmp, 0, 10, &arr, &bmi, DIB_RGB_COLORS);
                     for(int i=0;i<10;i++)
                     for(int j=0; j<10; j++)
                     /*printf("%x\t",arr[i][j]);*/if(arr[i][j]==0xff06d755){Reply();goto n;}
             }
}

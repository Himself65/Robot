#include "HardwareInfo.c"
#include "JMLib.c"
#include <SetWaitforLouder.h>
#include <GetData.h>
#include "go_bmp.c"
#include "line_bmp.c"
#include "catch_line.c"
#include "xuanzhuanZW.c"
#include <SetLCDClear.h>
#include "weizhuangZB.c"
#include "speed_control.c"
#include <SetWaitForTime.h>
u16 tempCS=0;
u16 G1,G2,G3,G4,G5;

// define global var
unsigned int S1 = 0;
unsigned int S2 = 0;
unsigned int S3 = 0;
unsigned int S4 = 0;
unsigned int g_temp = 5;
double line_proportion = 0.5;   //巡线抖动
long T14 = 0;   //光电15路口判断
long light_ws = 0;   //走圆弧参数，顺时针将变量设置成5，逆时针设置成1
unsigned long first = 0;
unsigned long second = 0;
unsigned int S5 = 0;
long T15 = 0;
long dowhat = 0;
long fuckwhat = 0;
long seewhat = 0;
long gogogo = 0;

int main(void)
{
    E3RCU_Init();
    SetWaitforLouder(3000);
    dowhat = GetData(1);
    fuckwhat = GetData(2);
    go_bmp(100, 400);
    line_bmp(75, 25000);
    line_bmp(70, 7000);
    catch_line(35, 14);
    xuanzhuanZW(5);
    line_bmp(60, 500);
    SetLCDClear(BLACK);
    catch_line(45, 14);
    weizhuangZB(1);
    go_bmp(55, 300);
    catch_line(55, 1);
    line_bmp(60, 5000);
    line_bmp(80, 10500);
    speed_control(0, 0);
    SetWaitForTime(0.5);
    go_bmp(90, 2000);
    line_bmp(75, 60000);
    while(1);
}


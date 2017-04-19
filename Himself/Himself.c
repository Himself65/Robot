#include "HardwareInfo.c"
#include "JMLib.c"
#include "line_pro.c"
#include "go_bmp.c"
#include "saoxian.c"
#include "catch_line.c"
#include "rurnleft.c"
#include "line_bmp.c"
u16 tempCS=0;
u16 G1,G2,G3,G4,G5;

// define global var
unsigned int S1 = 0;
unsigned int S2 = 0;
unsigned int S3 = 0;
unsigned int S4 = 0;
unsigned int g_0 = 0;
unsigned int g_temp = 0;
double line_proportion = 0.6;   //巡线抖动
long T14 = 0;   //光电15路口判断
long light_ws = 0;   //走圆弧参数，顺时针将变量设置成5，逆时针设置成1
unsigned int S5 = 0;
long T15 = 0;
unsigned int b2 = 866;
unsigned int b3 = 964;

int main(void)
{
    E3RCU_Init();
        b2=GetData(2);
        b3=GetData(3);
    line_pro(0.65);
    go_bmp(100, 1800);
    saoxian();
    catch_line(60, 1);
    rurnleft();
    line_bmp(60, 26000);
    go_bmp(100, 800);
    while(1);
}


#include "HardwareInfo.c"
#include "JMLib.c"
u16 tempCS=0;
u16 G1,G2,G3,G4,G5;

// define global var
unsigned int S1 = 0;
unsigned int S2 = 0;
unsigned int S3 = 0;
unsigned int S4 = 0;
unsigned int g_temp = 0;
double line_proportion = 0.55;   //巡线抖动
long T14 = 0;   //光电15路口判断
long light_ws = 0;   //走圆弧参数，顺时针将变量设置成5，逆时针设置成1
unsigned int S5 = 0;
unsigned int b2 = 0;
unsigned int b3 = 0;
long T15 = 0;
unsigned int first = 0;
long time2 = 0;
long time1 = 0;
long second = 0;

int main(void)
{
    E3RCU_Init();
    while(1);
}


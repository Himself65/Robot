#include "HardwareInfo.c"
#include "JMLib.c"
#include <GetData.h>
#include "line_bmp.c"
u16 tempCS=0;
u16 G1,G2,G3,G4,G5;

// define global var
unsigned int S1 = 0;
unsigned int S2 = 0;
unsigned int S3 = 0;
unsigned int S4 = 0;
unsigned int g_temp = 5;
double line_proportion = 0.55;   //Ѳ�߶���
long T14 = 0;   //���15·���ж�
long light_ws = 0;   //��Բ��������˳ʱ�뽫�������ó�5����ʱ�����ó�1
unsigned long first = 0;
unsigned long second = 0;
unsigned int S5 = 0;
long T15 = 0;
long dowhat = 0;
long fuckwhat = 0;
long seewhat = 0;

int main(void)
{
    E3RCU_Init();
    dowhat = GetData(1);
    fuckwhat = GetData(2);
    line_bmp(60, 60000);
    while(1);
}


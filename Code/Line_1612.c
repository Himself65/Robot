#include "HardwareInfo.c"
#include "JMLib.c"
#include "goline.c"
u16 tempCS=0;
u16 G1,G2,G3,G4,G5;

// define global var
unsigned int S1 = 0;
unsigned int S2 = 0;
unsigned int S3 = 0;
unsigned int S4 = 0;
unsigned int S5 = 0;
unsigned int g_0 = 0;
unsigned int g_temp = 0;
double line_proportion = 0.6;   //Ѳ�߶���
long T15 = 0;   //���15·���ж�
long light_ws = 0;   //��Բ��������˳ʱ�뽫�������ó�5����ʱ�����ó�1
unsigned int A1 = 0;
unsigned int A2 = 0;
unsigned int A3 = 0;
unsigned int A4 = 0;

int main(void)
{
    E3RCU_Init();
    goline(60);
    while(1);
}


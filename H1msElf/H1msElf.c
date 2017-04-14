#include "HardwareInfo.c"
#include "JMLib.c"
#include "speed_control.c"
#include <SetWaitForTime.h>
#include "goLine.c"
#include "TaoLu.c"
#include <GetData.h>
#include <SetWaitforDark.h>
#include"untilgetline.c"
#include"getline.c"
#include<SetDisplayVar.h>


#undef FAST
#undef SLOW
#undef TURN
#undef WAIT_LONG_TIME
#undef WAIT_TIME

#define FAST 60 //С������ʱһ����Ϊ 60
#define SLOW 55 //С������ʱһ����Ϊ 55
#define TURN -25 //С��ת��ʱ��һ���ٶ�Ϊ- 10
#define WAIT_LONG_TIME 0.1 //С���ȴ��ϳ�ʱ��
#define WAIT_TIME 0.02//С���ȴ�ʱ��

// define global var
unsigned int b1 = 0;
unsigned int b2 = 0;
unsigned int b3 = 0;
unsigned int b4 = 0;
unsigned int w1 = 0;
unsigned int w2 = 0;
unsigned int w3 = 0;
unsigned int w4 = 0;
unsigned int p3 = 0;
unsigned int p4 = 0;
unsigned int p1 = 0;
unsigned int p2 = 0;
long beTime = 0;
unsigned int temp = 0;
unsigned int count = 0;
long firstTime = 0;
unsigned int firstP = 0;
unsigned int secondP = 0;
unsigned int countP = 1;

int main(void)
{
    E3RCU_Init();
    
    //    unsigned int beTime = 0;	//��¼ʱ��
        
    //    unsigned int temp=5;//���һ������
        
    //    unsigned int count=1;//��������������·
    //��ȡ���ģ��
        b1=GetData(1);
        b2=GetData(2);
        b3=GetData(3);
        b4=GetData(4);
        //ɨ�����ɫ������ֵ
        w1=GetData(5);
        w2=GetData(6);
        w3=GetData(7);
        w4=GetData(8);
        //ɨ�����ɫ������ֵ
        
    speed_control(80, 80);
    SetWaitForTime(0.1);
    while (1)
    {
        goLine();
        TaoLu();
    }
    while(1);
}


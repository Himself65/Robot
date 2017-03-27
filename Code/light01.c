#ifndef _LIGHT01_
#define _LIGHT01_
#include "HardwareInfo.c"
#include <GetLightSensor.h>
#include <SetWaitForTime.h>
#include <GetData.h>
#include <GetLightSensor.h>

extern u16 G1,G2,G3,G4,G5;
extern u16 tempCS;


void light01()
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int A1;
    extern unsigned int A2;
    extern unsigned int A3;
    extern unsigned int A4;

    unsigned int PP1 = 0;
    unsigned int PP2 = 0;
    unsigned int PP3 = 0;
    unsigned int PP4 = 0;
    if(!tempCS)
    {
        A1=GetData(1);
        A2=GetData(2);
        A3=GetData(3);
        A4=GetData(4);
        //从系统中读取值
        SetWaitForTime(0.01);
        tempCS=1;
    }
    PP1 = GetLightSensor(_P1_);
    PP2 = GetLightSensor(_P2_);
    PP3 = GetLightSensor(_P3_);
    PP4 = GetLightSensor(_P4_);
    //判断
    //从系统中读取4个接口的颜色数值
    
    if(PP1>=A1)
    S1=0;
    else
    S1=1;
    if(PP2>=A2)
    S2=0;
    else
    S2=1;
    if(PP3>=A3)
    S3=0;
    else
    S3=1;
    if(PP4>=A4)
    S4=0;
    else
    S4=1;
    
    
}
#endif


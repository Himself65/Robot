#ifndef _LIGHT01_
#define _LIGHT01_
#include "HardwareInfo.c"
#include <GetLightSensorData.h>
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

    unsigned int PP1 = 0;
    unsigned int PP2 = 0;
    unsigned int PP3 = 0;
    unsigned int PP4 = 0;
    if(!tempCS)
    {
    	//首次启动光电延时
    	S1 = GetLightSensor(_P1_);
        S2 = GetLightSensor(_P2_);
        S3 = GetLightSensor(_P3_);
        S4 = GetLightSensor(_P4_);
    
        
        //首次启动写入光电判断阀值
        /*G1=GetData(1);
        G2=GetData(2);
        G3=GetData(3);
        G4=GetData(4);*/
        SetWaitForTime(0.01);
        tempCS=1;
    }
    S1 = GetLightSensorData(_P1_);
    S2 = GetLightSensorData(_P2_);
    S3 = GetLightSensorData(_P3_);
    S4 = GetLightSensorData(_P4_);
}
#endif


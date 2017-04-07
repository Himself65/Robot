#ifndef _UNTILGETLINE_
#define _UNTILGETLINE_
#include "HardwareInfo.c"
#include <GetLightSensor.h>
#include <GetLightSensor.h>
#include <GetSysTime.h>
#include <GetData.h>

int untilgetline()
{
    // extern global var
    extern unsigned int w1;
    extern unsigned int w2;
    extern unsigned int w3;
    extern unsigned int w4;
    extern unsigned int b1;
    extern unsigned int b2;
    extern unsigned int b3;
    extern unsigned int b4;

           unsigned int p1 = 0;
           unsigned int p2 = 0;
           unsigned int p3 = 0;
           unsigned int p4 = 0;
                                
    while (1)
    {
        p1 = GetLightSensor(_P1_);
        p2 = GetLightSensor(_P2_);
        p3 = GetLightSensor(_P3_);
        p4 = GetLightSensor(_P4_);
        if(p1<=b1)
        p1=1;
        else
        p1=0;
        
        if(p2<=b2)
        p2=1;
        else
        p2=0;
        
        if(p3<=b3)
        p3=1;
        else
        p3=0;
        
        if(p4<=b4)
        p4=1;
        else
        p4=0;
        unsigned int max=p1+p2+p3+p4;
        if(max)
        	break;
    }
}
#endif


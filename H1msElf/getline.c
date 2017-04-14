#ifndef _GETLINE_
#define _GETLINE_
#include "HardwareInfo.c"
#include <GetLightSensor.h>

void getline()
{
    // extern global var
    extern unsigned int p1;
    extern unsigned int p2;
    extern unsigned int p3;
    extern unsigned int p4;
    extern unsigned int w1;
    extern unsigned int w2;
    extern unsigned int w3;
    extern unsigned int w4;
    extern unsigned int b3;
    extern unsigned int b4;
    extern unsigned int b1;
    extern unsigned int b2;

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
}
#endif


#ifndef _TURN_W_
#define _TURN_W_
#include <SetWaitForTime.h>
#ifndef _TURN_W_
#define _TURN_W_
#include "HardwareInfo.c"
#include "speed_control.c"
#include <SetWaitForTime.h>
#include "light01.c"

void turn_w(int spl, int spr, int whi)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;

    speed_control(spl, spr);
    SetWaitForTime(0.15);
    while (1)
    {
        light01();
                switch whi
                case 1:if(S1)break;
                case 2:if(S2)break;
                case 3:if(S3)break;
                case 4:if(S4)break;
    }
    speed_control(0, 0);
}
#endif


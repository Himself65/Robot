#ifndef _TURN_ANGLE_
#define _TURN_ANGLE_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include "speed_control.c"
#include <GetMotorCode.h>

void turn_angle(int sp, unsigned int angle)
{
    int spl = 0;
    int spr = 0;
    long var0 = 0;
    long var1 = 0;
    spl=sp;
    spr=-sp;
    angle=abs(angle);
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    speed_control(spl, spr);
    while (1)
    {
        var0 = GetMotorCode(_M1_);
        var1 = GetMotorCode(_M2_);
        if ( abs(var0)>=angle||abs(var1)>=angle )
        {
            break;
        }
    }
    speed_control(0, 0);
}
#endif


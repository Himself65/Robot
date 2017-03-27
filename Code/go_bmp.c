#ifndef _GO_BMP_
#define _GO_BMP_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include <SetMotorServo.h>
#include <GetMotorCode.h>
#include <SetInBeep.h>
#include <SetWaitForTime.h>
#include "speed_control.c"
#include <GetLightSensor.h>

extern u16 tempCS;

void go_bmp(int sp, unsigned long bmp)
{
    long vl = 0;
    long vr = 0;
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    bmp=abs(bmp);
    SetMotorServo(_M1_, sp, bmp);
    SetMotorServo(_M2_, sp, bmp);
    while (1)
    {
        vl = GetMotorCode(_M1_);
        vr = GetMotorCode(_M2_);
        if ( abs(vl)>=bmp||abs(vr)>=bmp )
        {
            break;
        }
    }
    SetInBeep(ON);
    SetWaitForTime(0.05);
    SetInBeep(OFF);
    speed_control(0, 0);
}
#endif


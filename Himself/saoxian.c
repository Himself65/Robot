#ifndef _SAOXIAN_
#define _SAOXIAN_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include "light01.c"
#include "speed_control.c"
#include <GetMotorCode.h>
#include "turn_angle.c"

void saoxian()
{
    // extern global var
    extern unsigned int S3;

    int bmpr = 0;
    int bmpl = 0;
    unsigned int flag = 0;
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    flag=0;
    while ( fabs(bmpr)<150||fabs(bmpl)<150 )
    {
        light01();
        speed_control(25, -20);
        if ( S3 )
        {
            break;
            flag=1;
        }
        bmpl = GetMotorCode(_M1_);
        bmpr = GetMotorCode(_M2_);
    }
    if ( flag==0 )
    {
        SetMotorCode(_M1_);
        SetMotorCode(_M2_);
        while ( fabs(bmpr)<300||fabs(bmpl)<300 )
        {
            light01();
            speed_control(-20, 25);
            if ( S3 )
            {
                break;
            }
            bmpl = GetMotorCode(_M1_);
            bmpr = GetMotorCode(_M2_);
        }
    }
    speed_control(0, 0);
    turn_angle(-30, 80);
}
#endif


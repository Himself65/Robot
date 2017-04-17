#ifndef _SPEED_CONTROL_
#define _SPEED_CONTROL_
#include "HardwareInfo.c"
#include <SetMotor.h>

void speed_control(int spl, int spr)
{
    if ( spl>=100 )
    {
        spl=100;
    }
    if ( spl<=-100 )
    {
        spl=-100;
    }
    if ( spr>=100 )
    {
        spr=100;
    }
    if ( spr<=-100 )
    {
        spr=-100;
    }
    SetMotor(_M1_, spl);
    SetMotor(_M2_, spr);
}
#endif


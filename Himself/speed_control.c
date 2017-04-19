#ifndef _SPEED_CONTROL_
#define _SPEED_CONTROL_
#include "HardwareInfo.c"
#include <SetMotor.h>

void speed_control(int spl, int spr)
{
    SetMotor(_M1_, spl);
    SetMotor(_M2_, spr);
}
#endif


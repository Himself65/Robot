#ifndef _LINE_BMP_
#define _LINE_BMP_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include "goline.c"
#include <GetMotorCode.h>
#include "speed_control.c"
#include <SetDisplayVar.h>

void line_bmp(int sp, unsigned long bmp)
{
    long vbmp = 0;
    long vbmp1 = 0;
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    bmp=fabs(bmp);
    while (1)
    {
        goline(sp);
        vbmp = GetMotorCode(_M1_);
        vbmp1 = GetMotorCode(_M2_);
        if ( fabs(vbmp)>=bmp||fabs(vbmp1)>=bmp )
        {
            speed_control(0, 0);
            break;
        }
        SetDisplayVar(3, vbmp, YELLOW, BLACK);
        SetDisplayVar(4, vbmp1, YELLOW, BLACK);
    }
}
#endif


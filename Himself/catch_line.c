#ifndef _CATCH_LINE_
#define _CATCH_LINE_
#include "HardwareInfo.c"
#include "line_time.c"
#include "goline.c"
#include <SetDisplayVar.h>
#include <SetInBeep.h>
#include <SetWaitForTime.h>
#include "speed_control.c"

void catch_line(int sp, int light_w)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern long light_ws;

    line_time(sp, 200);
    if ( light_w==14 )
    {
        while (1)
        {
            goline(sp);
            if ( S1&&S4 )
            {
                break;
            }
        }
    }
    else
    {
        if ( light_w==1 )
        {
            while (1)
            {
                goline(sp);
                if ( S1 )
                {
                    break;
                }
            }
            SetDisplayVar(1, S1, YELLOW, BLACK);
        }
        else
        {
            if ( light_w==4 )
            {
                while (1)
                {
                    goline(sp);
                    if ( S4 )
                    {
                        break;
                    }
                }
            }
        }
    }
    SetInBeep(ON);
    SetWaitForTime(0.05);
    SetInBeep(OFF);
    speed_control(0, 0);
}
#endif


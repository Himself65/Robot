#ifndef _CATCH_LINE_
#define _CATCH_LINE_
#include "HardwareInfo.c"
#include "line_time.c"
#include "goline.c"
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
    extern unsigned int S5;
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
        if ( light_w==23 )
        {
            while (1)
            {
                goline(sp);
                if ( S2&&S3 )
                {
                    break;
                }
            }
        }
        else
        {
            if ( light_w==34 )
            {
                while (1)
                {
                    goline(sp);
                    if ( S3&&S4 )
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
                }
                else
                {
                    if ( light_w==5 )
                    {
                        while (1)
                        {
                            goline(sp);
                            if ( S5 )
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        if ( light_w==33 )
                        {
                            while (1)
                            {
                                goline(sp);
                                if ( S1+S2+S3+S4>1 )
                                {
                                    break;
                                }
                            }
                        }
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


#ifndef _XUANZHUANZW_
#define _XUANZHUANZW_
#include "HardwareInfo.c"
#include "go_bmp.c"
#include "turn_w.c"
#include "turn_angle.c"
#include <SetLCDClear.h>
#include <SetWaitForTime.h>

void xuanzhuanZW(int turnZW)
{
    go_bmp(50, 400);
    turn_w(-30, 45, 2);
    if ( turnZW==1 )
    {
        turn_angle(50, 3500);
        turn_w(50, -50, 2);
    }
    else
    {
        if ( turnZW==2 )
        {
            turn_angle(-50, 5100);
            turn_w(-50, 50, 3);
        }
        else
        {
            if ( turnZW==3 )
            {
                turn_angle(50, 2500);
                turn_w(50, -50, 3);
                turn_angle(-50, 2600);
                turn_w(-50, 50, 3);
            }
            else
            {
                if ( turnZW==4 )
                {
                    turn_angle(-50, 2350);
                    turn_w(-50, 50, 3);
                    turn_angle(50, 2500);
                    turn_w(50, -50, 3);
                }
                else
                {
                    if ( turnZW==5 )
                    {
                        SetLCDClear(GREEN);
                        SetWaitForTime(2);
                    }
                }
            }
        }
    }
    go_bmp(50, 600);
}
#endif


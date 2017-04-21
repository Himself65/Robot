#ifndef _XUANZHUANZW_
#define _XUANZHUANZW_
#include "HardwareInfo.c"
#include "go_bmp.c"
#include "turn_angle.c"
#include "turn_w.c"
#include "speed_control.c"
#include <SetMusicAddData.h>
#include <SetMusicPlay.h>
#include <SetWaitForTime.h>

void xuanzhuanZW(int turnZW)
{
    go_bmp(50, 400);
    if ( turnZW==1 )
    {
        turn_angle(50, 4500);
        turn_w(50, -50, 3);
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
                turn_angle(-50, 2350);
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
                        speed_control(0, 0);
                        SetMusicAddData(6, 4);
                        SetMusicAddData(8, 4);
                        SetMusicAddData(10, 4);
                        SetMusicAddData(8, 4);
                        SetMusicPlay();
                        SetWaitForTime(2);
                    }
                }
            }
        }
    }
    go_bmp(50, 500);
}
#endif


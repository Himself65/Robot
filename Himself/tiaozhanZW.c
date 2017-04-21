#ifndef _TIAOZHANZW_
#define _TIAOZHANZW_
#include "HardwareInfo.c"
#include "catch_line.c"
#include "go_bmp.c"
#include "turn_w.c"
#include <SetMotor.h>
#include <SetWaitForTime.h>
#include <SetMusicAddData.h>
#include <SetMusicPlay.h>

void tiaozhanZW(int tiaozhan)
{
    catch_line(50, 33);
    go_bmp(30, 300);
    turn_w(35, -35, 1);
    turn_w(35, -35, 3);
    catch_line(30, 14);
    go_bmp(20, 500);
    if ( tiaozhan==1 )
    {
        SetMotor(_M3_, 20);
        SetWaitForTime(2);
    }
    else
    {
        if ( tiaozhan==2 )
        {
            SetMusicAddData(6, 4);
            SetMusicAddData(8, 4);
            SetMusicAddData(10, 4);
            SetMusicAddData(8, 4);
            SetMusicAddData(6, 4);
            SetMusicAddData(8, 4);
            SetMusicAddData(10, 4);
            SetMusicAddData(8, 4);
            SetMusicPlay();
            SetWaitForTime(5);
        }
    }
}
#endif


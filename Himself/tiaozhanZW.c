#ifndef _TIAOZHANZW_
#define _TIAOZHANZW_
#include "HardwareInfo.c"
#include "catch_line.c"
#include "go_bmp.c"
#include "turn_w.c"
#include <SetMotorCode.h>
#include <SetMotor.h>
#include <GetMotorCode.h>
#include <SetMusicAddData.h>
#include <SetMusicPlay.h>
#include <SetWaitForTime.h>

void tiaozhanZW(int tiaozhan)
{
    // extern global var
    extern long gogogo;

    catch_line(50, 4);
    go_bmp(30, 300);
    turn_w(45, -30, 1);
    turn_w(45, -30, 3);
    catch_line(25, 14);
    go_bmp(20, 200);
    if ( tiaozhan==1 )
    {
        SetMotorCode(_M3_);
        while (1)
        {
            SetMotor(_M3_, -60);
            gogogo = GetMotorCode(_M3_);
            if ( gogogo>=400 )
            {
                break;
            }
        }
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
        else
        {
            if ( tiaozhan==3 )
            {
                SetMotor(_M1_, 70);
                SetMotor(_M2_, 70);
                SetWaitForTime(1);
                SetMotor(_M1_, 0);
                SetMotor(_M2_, 0);
            }
        }
    }
}
#endif


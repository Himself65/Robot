#ifndef _GOLINE_
#define _GOLINE_
#include "HardwareInfo.c"
#include <GetSysTime.h>
#include "light01.c"
#include <SetWaitForTime.h>
#include <SetMotor.h>

void goline(int sp)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int g_temp;
    extern double line_proportion;   //巡线抖动
    extern long T14;
    extern long light_ws;

    int spl = 0;
    int spr = 0;
    long var0 = 0;
    long vt = 200;
    var0 = GetSysTime();
    //读取光电状态
    light01();
    if ( S1 )
    {
        SetMotor(_M1_, -30);
        SetMotor(_M2_, 45);
        g_temp==1;
    }
    else
    {
        if ( S4 )
        {
            SetMotor(_M1_, 45);
            SetMotor(_M2_, -30);
            g_temp==4;
        }
        else
        {
            if ( S2&&S3 )
            {
                SetMotor(_M1_, sp);
                SetMotor(_M2_, sp);
                SetWaitForTime(0.02);
                g_temp==5;
            }
            else
            {
                if ( S2 )
                {
                    SetMotor(_M1_, sp*line_proportion);
                    SetMotor(_M2_, sp);//向左转弯
                    if ( var0-T14>=vt )
                    {
                    	g_temp=2;
                    }
                    SetWaitForTime(0.02);
                }
                else
                {
                    if ( S3 )
                    {
                        SetMotor(_M1_, sp);
                        SetMotor(_M2_, sp*line_proportion);//向左转弯
                        if ( var0-T14>=vt )
                        {
                        	g_temp=3;
                        }
                        SetWaitForTime(0.02);
                    }
                    else
                    {
                        if(g_temp==1)
                        {
                        	SetMotor(_M1_, -30);
                        	SetMotor(_M2_, 45);
                        }
                        else if(g_temp==4)
                        {
                        	SetMotor(_M1_, 45);
                        	SetMotor(_M2_, -30);
                        }
                         else if(g_temp==2)
                        {
                        	SetMotor(_M1_, sp*line_proportion);
                        	SetMotor(_M2_, sp);//向左转弯
                        }
                        else if(g_temp==3)
                        {
                            SetMotor(_M1_, sp);
                            SetMotor(_M2_, sp*line_proportion);
                        }
                        else if(g_temp==5)
                        {
                            SetMotor(_M1_, sp);
                            SetMotor(_M2_, sp);
                        }
                        else
                        {
                        	SetMotor(_M1_,45);
                        	SetMotor(_M2_,-30);
                        }
                        SetWaitForTime(0.02);
                    }
                }
            }
        }
    }
}
#endif


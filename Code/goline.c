#ifndef _GOLINE_
#define _GOLINE_
#include "HardwareInfo.c"
#include <GetSysTime.h>
#include "light01.c"
#include "speed_control.c"

void goline(int sp)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int S5;
    extern unsigned int g_temp;
    extern double line_proportion;   //巡线抖动
    extern long T15;
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
        spl=-20;
        spr=50;
        g_temp=1;
        T15 = GetSysTime();
    }
    else
    {
        if ( S5 )
        {
            spl=50;
            spr=-20;
            g_temp=5;
            T15 = GetSysTime();
        }
        else
        {
            if ( S3 )
            {
                spl=sp;
                spr=sp;
                if ( var0-T15>=vt )
                {
                    g_temp=3;
                }
                if ( light_ws==1 )
                {
                    spl=sp*line_proportion;
                    spr=sp;
                }
                if ( light_ws==5 )
                {
                    spl=sp;
                    spr=sp*line_proportion;
                }
            }
            else
            {
                if ( S2 )
                {
                    spl=sp*line_proportion;
                    spr=sp;
                    if ( var0-T15>=vt )
                    {
                        g_temp=2;
                    }
                }
                else
                {
                    if ( S4 )
                    {
                        spl=sp;
                        spr=sp*line_proportion;
                        if ( var0-T15>=vt )
                        {
                            g_temp=4;
                        }
                    }
                    else
                    {
                        if ( !S1&&!S2&&!S3&&!S4&&!S5 )
                        {
                            if ( g_temp==1 )
                            {
                                spl=-50;
                                spr=50;
                            }
                            else
                            {
                                if ( g_temp==5 )
                                {
                                    spl=50;
                                    spr=-50;
                                }
                                else
                                {
                                    if ( g_temp==2 )
                                    {
                                        spl=sp*line_proportion;
                                        spr=sp;
                                    }
                                    else
                                    {
                                        if ( g_temp==4 )
                                        {
                                            spl=sp;
                                            spr=sp*line_proportion;
                                        }
                                        else
                                        {
                                            if ( g_temp==3 )
                                            {
                                                spl=sp;
                                                spr=sp;
                                            }
                                            else
                                            {
                                                spl=sp;
                                                spr=sp;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    speed_control(spl, spr);
}
#endif


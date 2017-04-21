#ifndef _GOLINE_
#define _GOLINE_
#include "HardwareInfo.c"
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
    extern double line_proportion;   //Ñ²Ïß¶¶¶¯
    extern long T15;
    extern long light_ws;

    int spl = 0;
    int spr = 0;
    long var0 = 0;
    long vt = 200;
    light01();
        if ( S4 )
        {
            g_temp=4;
            spl=45;
            spr=-30;
            speed_control(45, -30);
        }
        else
        {
            if ( S1 )
            {
                g_temp=1;
                spl=-30;
                spr=45;
            }
            else
            {
                if ( S2 )
                {
                    if(!S1)
                    {
                    	spl=sp*line_proportion;
                    	spr=sp;
                    	g_temp=2;
                    }
                    else
                    {
                    	spl=-30;
                    	spr=45;
                    }
                }
                else
                {
                    if ( S3 )
                    {
                        if(!S4)
                        {
                        	spl=sp;
                        	spr=sp*line_proportion;
                        	g_temp=3;
                        }
                        else
                        {
                        	spl=-30;
                        	spr=45;
                        }
                    }
                    else
                    {
                        if(S2&&S3)
                        {
                        	spl=sp;
                        	spr=sp;
                        }
                        else if(g_temp==5)
                        {
                        	spl=sp;
                        	spr=sp;
                        }
                        else if(g_temp==1)
                        {
                        	spl=-30;
                        	spr=45;
                        }
                        else if(g_temp==4)
                        {
                        	spl=45;
                        	spr=-30;
                        }
                        else if(g_temp==2)
                        {
                        	spl=sp*line_proportion;
                        	spr=sp;
                        }
                        else if(g_temp==3)
                        {
                        	spl=sp;
                        	spr=sp*line_proportion;
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
    speed_control(spl, spr);
}
#endif


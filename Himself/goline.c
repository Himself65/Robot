#ifndef _GOLINE_
#define _GOLINE_
#include "HardwareInfo.c"
#include "light01.c"
#include "speed_control.c"
#include <SetDisplayVar.h>
#include <GetRandom.h>
#include <Set3CLed.h>


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
    extern long T14;
    extern long light_ws;
    extern unsigned long second;
    extern unsigned long first;
    extern long seewhat;

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
        if ( first>50 )
        {
            if ( second>50 )
            {
                second=0;
                first=0;
                seewhat = GetRandom(1, 7);
            }
            else
            {
                if ( seewhat==1 )
                {
                    Set3CLed(_P8_, GREEN);
                    Set3CLed(_P7_, CYAN);
                }
                else
                {
                    if ( seewhat==2 )
                    {
                        Set3CLed(_P8_, BLUE);
                        Set3CLed(_P7_, RED);
                    }
                    else
                    {
                        if ( seewhat==3 )
                        {
                            Set3CLed(_P8_, BLUE);
                            Set3CLed(_P7_, PURPLE);
                        }
                        else
                        {
                            if ( seewhat==4 )
                            {
                                Set3CLed(_P8_, CYAN);
                                Set3CLed(_P7_, PURPLE);
                            }
                            else
                            {
                                if ( seewhat==5 )
                                {
                                    Set3CLed(_P8_, GREEN);
                                    Set3CLed(_P7_, YELLOW);
                                }
                                else
                                {
                                    if ( seewhat==6 )
                                    {
                                        Set3CLed(_P8_, RED);
                                        Set3CLed(_P7_, BLUE);
                                    }
                                    else
                                    {
                                        Set3CLed(_P8_, CYAN);
                                        Set3CLed(_P7_, PURPLE);
                                    }
                                }
                            }
                        }
                    }
                }
                second++;
            }
        }
        else
        {
            if ( seewhat==1 )
            {
                Set3CLed(_P7_, BLUE);
                Set3CLed(_P8_, PURPLE);
            }
            else
            {
                if ( seewhat==2 )
                {
                    Set3CLed(_P7_, PURPLE);
                    Set3CLed(_P8_, RED);
                }
                else
                {
                    if ( seewhat==3 )
                    {
                        Set3CLed(_P7_, YELLOW);
                        Set3CLed(_P8_, PURPLE);
                    }
                    else
                    {
                        if ( seewhat==4 )
                        {
                            Set3CLed(_P7_, CYAN);
                            Set3CLed(_P8_, PURPLE);
                        }
                        else
                        {
                            if ( seewhat==5 )
                            {
                                Set3CLed(_P7_, GREEN);
                                Set3CLed(_P8_, YELLOW);
                            }
                            else
                            {
                                if ( seewhat==6 )
                                {
                                    Set3CLed(_P7_, RED);
                                    Set3CLed(_P8_, PURPLE);
                                }
                                else
                                {
                                    Set3CLed(_P7_, CYAN);
                                    Set3CLed(_P8_, BLUE);
                                }
                            }
                        }
                    }
                }
            }
            first++;
        }
    
    SetDisplayVar(2, first, YELLOW, BLACK);
    SetDisplayVar(3, second, YELLOW, BLACK);
}
#endif


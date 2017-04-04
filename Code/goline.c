#ifndef _GOLINE_
#define _GOLINE_
#include <GetSysTime.h>
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
    //适用于光电左2右2在后，左1右1并排中间，相隔黑线
    
    	if(S1 )//感应左2有线
    	{
    		if(S1 && !(S2||S3||S4) )//光左2有黑线，推测是直角转弯
    		{
    			spl=-sp;
    			spr=sp;
    			g_temp=1;
    			T15 = GetSysTime();
            }
            else if(S1 &&! (S2||S3) && S4 ) //左右有线但是中间没有线，推测是一条十字路口
            {
    			spl = sp;
    			spr = sp;
    			g_temp=5;
    		}
    	}
    	else if (S4) //感应右2有线
    	{
    		if(S4 && !(S2||S3||S4) )//光右二有黑线，推测是直角转弯
    		{
    			spl=sp;
    			spr=-sp;
    			g_temp=4;
    			T15 = GetSysTime();
    		}
    		else if(S4 &&! (S2||S3) S1)//左右有线但是中间没有线，推测是一条十字路口
    		{
    			spl = sp;
    			spr = sp;
    			g_temp=5;
    		}
    	}
    	else if(S2)//感应左1有线
    	{
    		if(S2 && g_temp == 1)//判断是否是大转弯的一半进程
    		{
    
               spl = -sp;
               spr = sp;
    		}
    		if (S2 &&  var0-T15>=vt)//左2的转动时间大于200单位时间，说明最后一次碰线是S2
    		{
    			g_temp=2;
    		}
    		else if (S2 && g_temp != 1 )//判断是不是小幅度转弯呢？
    		{
    			spl=sp*line_proportion;
                spr=sp;
    		}
    	}
    	
    	
    	else if (S3)//感应右1有线
    	{
    			if(S3 && g_temp == 4)//判断是否是大转弯的一半进程
    			{
    				spl = -sp;
    				spr = sp;
    			}
    			if (S3 &&  var0-T15>=vt)//左2的转动时间大于200单位时间，说明最后一次碰线是S2
    			{
    				g_temp=2;
    			}
    			else if (S3 && g_temp != 4 )//判断是不是小幅度转弯呢？
    			{
    				spl=sp*line_proportion;
    				spr=sp;
    			}
    	}
    	else if( !(S1||S2||S3||S4) )//如果都没有感应到线
    	{
    	 if( !(S1||S2||S3||S4)&& t_temp ==1)//最后一次碰线是1
    		{
    			spl =-sp;
    			spr =sp;
    		}
    	 if( !(S1||S2||S3||S4)&& t_temp ==2)//最后一次碰线是2
    		{
    			spl=sp*line_proportion;
    			spr=sp;
    		}	 
    	 if( !(S1||S2||S3||S4)&& t_temp ==3)//最后一次碰线是3
    		{
    			spl=sp;
    			spr=sp*line_proportion;
    		}	
    	 if( !(S1||S2||S3||S4)&& t_temp ==4)//最后一次碰线是4
    		{
    			spl =sp;
    			spr =-sp;
    		}
    	 if( !(S1||S2||S3||S4)&& t_temp ==5)//最后一次碰线是5
    		{
    			spl = sp;
    			spr = sp;
    		}
    	}
    			
    speed_control(spl, spr);
}
#endif


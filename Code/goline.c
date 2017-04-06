#ifndef _GOLINE_
#define _GOLINE_
#include "HardwareInfo.c"
#include <GetSysTime.h>
#include "light01.c"
#include "speed_control.c"
#include <SetDisplayVar.h>

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
    extern long T14;
    extern long light_ws;
    extern unsigned int g_templ;
    extern unsigned int g_tempr;

    int spl = 0;
    int spr = 0;
    long var0 = 0;
    long vt = 200;
    var0 = GetSysTime();
    //读取光电状态
    light01();
    	//读取系统时间的函数
    	//读取光电的函数
    	//g_temp为5时候为直线
    	//g_templ为左侧最后检测到的光电号
    	//g_tempr为右侧最后检测到的光电号
    	//S1、S2、S3、S4分别为左二、左一、右一、右二
    	//g_temp保存最后一次碰线光电
    	//g_templ和g_tempr保存的是左右最后一次碰线光电
    	//givetemp函数赋值顺序为g_tempr、g_temp、g_templ
    	//0的时候不赋值
    	
    	
    	//需求，保证每次的巡线都要保证temp变量刷新
    	//四光电判断 alpha0.2
    	
    	if (S1) //S1上有光电
    	{//S1基本结束
    		if (S1 && !(S2 || S3 || S4))//只有左二检测到光电
    		{
    			//计时
    			//向左大转
    			spl=-sp;
    			spr=sp;
    			givetemp(0,1,1);
    			T14 = GetSysTime();
    		}
    		else if (S1 && S4)//之后设置更多的判断
    		{
    			//直走
    			spl = sp;
    			spr = sp;
    			givetemp(4,5,1);
    		}
    	}
    	else
    	{
    		if (S4)//S4上面有光电
    		{//S4基本结束
    			if (S4 && !(S1 || S2 || S3))//只有右二检测到光电
    			{
    				//计时
    				//向右大转
    				spl=sp;
    				spr=-sp;
    				givetemp(4,4,0);
    				T14 = GetSysTime();
    			}
    			else if (S4 && S1)//左右都检测到光电
    			{
    				//直走
    				spl = sp;
    				spr = sp;
    				givetemp(4,5,1);
    			}
    		}
    		else
    		{//改了一下，||防止g_temp不是5，以后修改
    			if (!(S1||S2||S3||S4) || g_temp==5)//都没有检测到光电，而且5为在直线中间
    			{
    				//可以再加点判断，更加准确
    				//直走
    				spl = sp;
    				spr = sp;
    				if (g_templ==2 && g_temp==2)//刚刚转过圆圈 
    					spl=spl-5;//刚转完，左面速度可能太大，进行略微减小
    				if(g_tempr==3 &&g_temp==3)
    					spr=spl-5;//同理
    			}
    			else
    			{
    			/*S2的基本结束*/
    				if (S2)//S2检测到光电
    				{
    					if (S2 && !(S1||S3||S4))
    					{
    						if (g_templ == 1 && g_temp==1)//上一次碰线是不是左二？
    						{
    							//如果是的话，说明在大幅度转弯的时候
    							//判断时间
    							//小左转
    							if (var0-T14>=vt)//左2的转动时间大于200单位时间，说明最后一次碰线是S1
    								{
    									//大转弯进行时
    									spl=-sp;
    									spr=sp;
    									givetemp(0,2,2);
    								}
    							else
    								{
    									spl=sp*line_proportion;
    									spr=sp;
    									givetemp(0,5,2);
    								}
    						}
    						else if(g_templ == 2 && g_temp== 2)//上一次碰线是不是左一？
    						{
    							//说明你在走弧线！
    							
    							//调用走弧线代码
    							spl=sp*line_proportion;
    							spr=sp;
    							
    							//赋值，最后一次碰线和左面最后一次碰线是左2
    							givetemp(0,2,2);
    						}
    					}
    				}
    				else
    				{
    					if (S3)//S3检测到光电
    					{
    						if (S3 && !(S1||S2||S4))
    						{
    							if (g_tempr == 3 && g_temp==3 )
    							{
    								//赋值的是S2的情况，可能出错
    								//判断时间
    								//小右转
    								    if (var0-T14>=vt)//左2的转动时间大于200单位时间，说明最后一次碰线是S1
        								{
        									//大转弯进行时
        									spl=-sp;
        									spr=sp;
        									givetemp(3,3,0);
        								}
        							else
        								{
    										//小幅度转弯
        									spl=sp*line_proportion;
        									spr=sp;
        									givetemp(3,5,0);
        								}
    							}
    						}
    					}
    					else//都没有检测到光电，也就是现在无法判断小车在哪里
    					{
    						if (g_templ == 1 || g_temp==1 )//上一次在判断在左手
    						{
    							spl=-sp;
    							spr=sp;
    							//遇到线停止
    						}
    						else if(g_templ == 2 || g_temp == 2)
    						{
    							//小幅度转弯
    							spl=sp*line_proportion;
    							spr=sp;
    						}
    						else if(g_tempr == 4||g_temp==4)
    						{
    							//大幅度转弯
    							spl=sp;
    							spr=-sp;
    						}
    						else if(g_tempr == 3|| g_temp==3)
    						{
    							//小幅度转弯
    							spl=sp;
    							spr=sp*line_proportion;
    						}
    						else if(g_temp == 5 || (g_templ==2&&g_tempr==3) )
    						{
    							//走直线
    							spl=sp;
    							spr=sp;
    						}
    					}
    				}
    			}
    		}
    	}
    speed_control(spl, spr);
    SetDisplayVar(10, var0, YELLOW, BLACK);
    SetDisplayVar(11, T14, YELLOW, BLACK);
    SetDisplayVar(12, vt, YELLOW, BLACK);
    SetDisplayVar(9, g_templ, YELLOW, BLACK);
    SetDisplayVar(10, g_temp, YELLOW, BLACK);
    SetDisplayVar(11, g_tempr, YELLOW, BLACK);
}
#endif


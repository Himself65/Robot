#ifndef _GOLINE_
#define _GOLINE_
#include "HardwareInfo.c"
#include <GetSysTime.h>
#include <SetWaitForTime.h>
#include "goLine.c"
#include <GetData.h>
#include <SetWaitforDark.h>
#include"untilgetline.c"
#include"getline.c"
#include<SetDisplayVar.h>


#undef FAST
#undef SLOW
#undef TURN
#undef WAIT_LONG_TIME
#undef WAIT_TIME

#define FAST 60 //С������ʱһ����Ϊ 60
#define TURN 30 //С������ʱһ����Ϊ 55
#define BACK -25 //С��ת��ʱ��һ���ٶ�Ϊ- 10
#define WAIT_LONG_TIME 0.1 //С���ȴ��ϳ�ʱ��
#define WAIT_TIME 0.02//С���ȴ�ʱ��

void goLine()
{
    // extern global var
    extern unsigned int p1;
    extern unsigned int p2;
    extern unsigned int p3;
    extern unsigned int p4;
    extern long beTime;
    extern unsigned int temp;
    extern unsigned int count;
    extern long firstTime;

    getline();
    unsigned int maxp = p1+p2+p3+p4;
    beTime = GetSysTime();
    	if(p4)
    	{	
    		if(p4&&p3)
    		{
    			SetMotor(_M1_, FAST);
    			SetMotor(_M2_, BACK);
    			temp=4;
    			SetWaitForTime(WAIT_LONG_TIME);
    		}
    		else//
    		{
    			SetMotor(_M1_, FAST);
    			SetMotor(_M2_, BACK);
    			temp=4;
    			beTime = GetSysTime();
    		}
    	}
    	else if(p1)
    	{
    		if(p1&&p2)
    		{
    			SetMotor(_M1_, FAST);
    			SetMotor(_M2_, BACK);
    			temp=4;
    			SetWaitForTime(WAIT_LONG_TIME);
    		}
    		else//
    		{
    			SetMotor(_M1_, BACK);
    			SetMotor(_M2_, FAST);
    			temp=1;
    			
    			beTime = GetSysTime();
    		}
    	}
    	else if(p3)
    	{
    		SetMotor(_M1_, TURN);
    		SetMotor(_M2_, FAST);
    		temp=3; 
    	}
    	else if(p2)
    	{
    		SetMotor(_M1_, FAST);
    		SetMotor(_M2_, TURN);
    		temp=2;
    	}
    	else
    	{
    			if(temp==1)
    			{
    				SetMotor(_M1_, BACK);
    				SetMotor(_M2_, FAST);
    			}
    			else if(temp==4)
    			{
    				SetMotor(_M1_, FAST);
    				SetMotor(_M2_, BACK);
    			}
    			else if(temp==2)
    			{
    				SetMotor(_M1_, FAST);
    				SetMotor(_M2_, TURN);
    			}
    			else if(temp==3)
    			{
    				SetMotor(_M1_, TURN);
    				SetMotor(_M2_, FAST);
    			}
    	}
    	
    	
    	
    	
    SetDisplayVar(10, p1, YELLOW, BLACK);
    
    SetDisplayVar(11, p2, YELLOW, BLACK);
    
    SetDisplayVar(12, p3, YELLOW, BLACK);
    
    SetDisplayVar(13, p4, YELLOW, BLACK);
}
#endif


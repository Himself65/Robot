#include "HardwareInfo.c"
#include "JMLib.c"
#include <SetMotor.h>
#include <SetWaitForTime.h>
#include <GetLightSensor.h>
#include <GetSysTime.h>
#include <GetData.h>
#include <SetWaitforDark.h>
#include"untilgetline.c"
#include<SetDisplayVar.h>

// define global var
unsigned int b1 = 0;
unsigned int b2 = 0;
unsigned int b3 = 0;
unsigned int b4 = 0;
unsigned int w1 = 0;
unsigned int w2 = 0;
unsigned int w3 = 0;
unsigned int w4 = 0;

int main(void)
{
    E3RCU_Init();
        unsigned int p1 = 0;
        unsigned int p2 = 0;
        unsigned int p3 = 0;
        unsigned int p4 = 0;
        //
        unsigned int beTime = 0;	//记录时间
        
        unsigned int temp=0;//最后一次碰线
        
        unsigned int count=1;//计数器，走死套路
    //读取光电模块
        b1=GetData(1);
        b2=GetData(2);
        b3=GetData(3);
        b4=GetData(4);
        //扫描出黑色的数据值
        w1=GetData(5);
        w2=GetData(6);
        w3=GetData(7);
        w4=GetData(8);
        //扫描出白色的数据值
        
    SetMotor(_M1_, 65);
    SetMotor(_M2_, 60);
    SetWaitForTime(0.5);
    while (1)
    {
        p1 = GetLightSensor(_P1_);
        p2 = GetLightSensor(_P2_);
        p3 = GetLightSensor(_P3_);
        p4 = GetLightSensor(_P4_);
        if(p1<=b1)
        p1=1;
        else
        p1=0;
        
        if(p2<=b2)
        p2=1;
        else
        p2=0;
        
        if(p3<=b3)
        p3=1;
        else
        p3=0;
        
        if(p4<=b4)
        p4=1;
        else
        p4=0;
        unsigned int maxp = p1+p2+p3+p4;
        beTime = GetSysTime();
        //基础判断代码块	
        	if(maxp>1)//如果同时两个线碰到黑色
        	{
        		if(p2)
        		{
        			SetMotor(_M1_, 30);
        			SetMotor(_M2_, 40);
        			SetWaitforDark(_P4_,b4);
        		}
        		else if(p3)
        		{
        			SetMotor(_M1_, 40);
        			SetMotor(_M2_, 30);
        			SetWaitforDark(_P1_, b1);
        		}
        	}
        	else if(p4)
        	{	
        		SetMotor(_M1_, 40);
        		SetMotor(_M2_, 0);
        		temp=4;
        		SetWaitForTime(0.02);
        
        	}
        	else if(p1)
        	{
        		SetMotor(_M1_, 0);
        		SetMotor(_M2_, 40);
        		temp=1;
        		SetWaitForTime(0.02);
        	}
        	else if(p3)
        	{
        		SetMotor(_M1_, 45);
        		SetMotor(_M2_, 40);
        		temp=3; 
        		SetWaitForTime(0.02);
        	}
        	else if(p2)
        	{
        		SetMotor(_M1_, 40);
        		SetMotor(_M2_, 45);
        		temp=2;
        		SetWaitForTime(0.02);
        	}else{
        				if(temp==1)
        				{
        					SetMotor(_M1_, 0);
        					SetMotor(_M2_, 40);
        					SetWaitForTime(0.02);
        				}
        				if(temp==2)
        				{
        					SetMotor(_M1_, 40);
        					SetMotor(_M2_, 45);
        					SetWaitForTime(0.02);
        				}
        				if(temp==3)
        				{
        					SetMotor(_M1_, 45);
        					SetMotor(_M2_, 40);
        					SetWaitForTime(0.02);
        				}
        				if(temp==4)
        				{
        					SetMotor(_M1_, 40);
        					SetMotor(_M2_, 0);
        					SetWaitForTime(0.02);
        				}
        				else
        				{
        					SetMotor(_M1_, -40);
        					SetMotor(_M2_, -40);
        					untilgetline();//如果没什么都没有检测，则一直倒退，只到有检测
        				}
        			}
        //SetMotor(_M1_, 40);
        //SetMotor(_M2_, 0);
        //SetWaitforDark(_P1_, pp1);
        
        SetDisplayVar(10, p1, YELLOW, BLACK);
        
        SetDisplayVar(11, p2, YELLOW, BLACK);
        
        SetDisplayVar(12, p3, YELLOW, BLACK);
        
        SetDisplayVar(13, p4, YELLOW, BLACK);
    }
    while(1);
}


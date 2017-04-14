#ifndef _TAOLU_
#define _TAOLU_
#include "HardwareInfo.c"
#include "getline.c"

void TaoLu()
{
    // extern global var
    extern unsigned int p1;
    extern unsigned int p2;
    extern unsigned int p3;
    extern unsigned int p4;
    extern unsigned int firstP;
    extern unsigned int secondP;
    extern unsigned int countP;

    getline();
    unsigned int maxp = p1+p2+p3+p4;
    //赋值语句，判断一个光电检测到时候的情况
    //两个值 firstP 和 secondP
    if(maxp==1 && countP==1)
    {
    	if(p1)
    	{
    		firstP=1;
    	}
    	else if(p2)
    	{
    		firstP=2;
    	}
    	else if(p3)
    	{
    		firstP=3;
    	}
    	else if(p4)
    	{
    		firstP=4;
    	}
    	countP--;
    }
    else if(maxp==1 && countP == 0)
    {
    	if(p1)
    	{
    		secondP=1;
    	}
    	else if(p2)
    	{
    		secondP=2;
    	}
    	else if(p3)
    	{
    		secondP=3;
    	}
    	else if(p4)
    	{
    		secondP=4;
    	}
    	countP++;
    }
    if(maxp >= 2)
    {
    	if(p2 && p4)
    	{
    		SetMotor(_M1_, 60);
    		SetMotor(_M2_, 20);
    	}
    	else if(p3 && p1)
    	{
    		SetMotor(_M1_, 20);
    		SetMotor(_M2_, 60);
    	}
    	else if(p2 && p3)
    	{
    	  	SetMotor(_M1_, 40);
    		SetMotor(_M2_, 20);
    	}
    	else if(p1 && p2)
    	{
    	  	SetMotor(_M1_, 50);
    		SetMotor(_M2_, -20);
    	}
    	else if(p4 && p3)
    	{
    		SetMotor(_M1_, -20);
    		SetMotor(_M2_, 50);
    	}
    }
}
#endif


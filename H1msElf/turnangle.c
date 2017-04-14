#ifndef _TURNANGLE_
#define _TURNANGLE_
#include <SetWaitForTime.h>
#include "getline.c"
#include "HardwareInfo.c"
#include <SetWaitForTime.h>


void turnangle(unsigned int whi)
{
    if(whi==2)
    {
    		SetMotor(_M1_, FAST);
    		SetMotor(_M2_, TURN);
    }
    else if(whi==3)
    {
    		SetMotor(_M1_, TURN);
    		SetMotor(_M2_, FAST);
    }
    SetWaitForTime(0.15);
    while (1)
    {
        getline();
                switch (whi){
                case 1: if(p1)break;
                
                case 2: if(p2)break;
                
                case 3: if(p3)break;
                
                case 4: if(p4)break;
                }
    }
    		SetMotor(_M1_, 0);
    		SetMotor(_M2_, 0);
}
#endif


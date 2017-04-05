//引用代码区
#ifndef _GIVETEMP_
#define _GIVETEMP_
#include "HardwareInfo.c"
#include <GetSysTime.h>
#include "light01.c"
#include "speed_control.c"



    // extern global var
    extern unsigned int g_temp;
    extern unsigned int g_tempr;
    extern unsigned int g_templ;

void givetemp(int f_tempr, int f_temp, int f_templ)

//编程区
{
	if(!f_temp){
		g_temp = f_temp;
	}
	if(!f_tempr){
		g_tempr = f_tempr;
	}
	if(!f_templ){
		g_templ = f_templ;
	}
}
#endif


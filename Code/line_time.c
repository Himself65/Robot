#ifndef _LINE_TIME_
#define _LINE_TIME_
#include "HardwareInfo.c"
#include <GetSysTime.h>
#include "goline.c"
#include "speed_control.c"

void line_time(int sp, unsigned int time0)
{
    unsigned long vT = 0;
    unsigned int vTbegin = 0;
    vTbegin = GetSysTime();
    while (1)
    {
        goline(sp);
        vT = GetSysTime();
        if ( vT-vTbegin>=time0 )
        {
            speed_control(0, 0);
            break;
        }
    }
}
#endif


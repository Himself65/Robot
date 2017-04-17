#ifndef _LINE_PRO_
#define _LINE_PRO_
#include "HardwareInfo.c"

void line_pro(double propor)
{
    // extern global var
    extern double line_proportion;

    line_proportion=propor;
}
#endif


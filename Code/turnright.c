#ifndef _TURNRIGHT_
#define _TURNRIGHT_
#include "HardwareInfo.c"
#include "turn_w.c"

void turnright()
{
    turn_w(50, -50, 3);
}
#endif


#ifndef _RURNLEFT_
#define _RURNLEFT_
#include "HardwareInfo.c"
#include "turn_w.c"

void rurnleft()
{
    turn_w(-50, 50, 3);
}
#endif


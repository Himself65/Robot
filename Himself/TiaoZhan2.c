#ifndef _TIAOZHAN2_
#define _TIAOZHAN2_
#include "HardwareInfo.c"
#include "go_bmp.c"
#include "turn_w.c"

void TiaoZhan2()
{
    go_bmp(-30, 600);
    turn_w(-30, 30, 1);
    turn_w(-30, 30, 3);
}
#endif


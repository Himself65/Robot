#ifndef _TIAOZHANZW_
#define _TIAOZHANZW_
#include "HardwareInfo.c"
#include "catch_line.c"
#include "go_bmp.c"
#include "turn_w.c"
#include <SetMotor.h>

void tiaozhanZW(int tiaozhan)
{
    catch_line(50, 34);
    go_bmp(30, 300);
    turn_w(35, -35, 1);
    turn_w(35, -35, 3);
    catch_line(30, 14);
    go_bmp(20, 300);
    SetMotor(_M3_, 20);
}
#endif


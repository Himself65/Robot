#ifndef _WEIZHUANGZB_
#define _WEIZHUANGZB_
#include "HardwareInfo.c"
#include "go_bmp.c"
#include <SetLCDClear.h>
#include <SetWaitForTime.h>

void weizhuangZB(int COLOR)
{
    go_bmp(50, 100);
    if ( COLOR==0 )
    {
        SetLCDClear(BLACK);
    }
    else
    {
        if ( COLOR==1 )
        {
            SetLCDClear(RED);
        }
        else
        {
            if ( COLOR==2 )
            {
                SetLCDClear(GREEN);
            }
            else
            {
                if ( COLOR==3 )
                {
                    SetLCDClear(BLUE);
                }
                else
                {
                    if ( COLOR==4 )
                    {
                        SetLCDClear(YELLOW);
                    }
                    else
                    {
                        if ( COLOR==5 )
                        {
                            SetLCDClear(PURPLE);
                        }
                        else
                        {
                            if ( COLOR==6 )
                            {
                                SetLCDClear(CYAN);
                            }
                            else
                            {
                                if ( COLOR==7 )
                                {
                                    SetLCDClear(WHITE);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    SetWaitForTime(1);
    SetLCDClear(BLACK);
}
#endif


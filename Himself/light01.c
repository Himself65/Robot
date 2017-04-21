#ifndef _LIGHT01_
#define _LIGHT01_
#include "HardwareInfo.c"
#include <GetLightSensorData.h>
#include <SetWaitForTime.h>
#include <GetData.h>
#include <GetLightSensor.h>

extern u16 G1,G2,G3,G4,G5;
extern u16 tempCS;


void light01()
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int S5;

    unsigned int PP1 = 0;
    unsigned int PP2 = 0;
    unsigned int PP3 = 0;
    unsigned int PP4 = 0;
    unsigned int PP5 = 0;
    S1 = GetLightSensorData(_P1_);
    S2 = GetLightSensorData(_P2_);
    S3 = GetLightSensorData(_P3_);
    S4 = GetLightSensorData(_P4_);
    S5 = GetLightSensorData(_P5_);
}
#endif


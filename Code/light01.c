#ifndef _LIGHT01_
#define _LIGHT01_
#include "HardwareInfo.c"
#include <GetLightSensor.h>
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
    extern double A1;
    extern double A2;
    extern double A3;
    extern double A4;

    unsigned int PP1 = 0;
    unsigned int PP2 = 0;
    unsigned int PP3 = 0;
    unsigned int PP4 = 0;
    long B3 = 0;
    long B4 = 0;
    long W1 = 0;
    long W2 = 0;
    long W3 = 0;
    long W4 = 0;
    long B1 = 0;
    long B2 = 0;
    //�˴����룬����ȡ���Ĺ��ֵ��ϵͳ����İ�ɫ����ɫֵ��ƽ��ֵ���бȽ�
    if(!tempCS)
    {
        B1=GetData(1);
        B2=GetData(2);
        B3=GetData(3);
        B4=GetData(4);
        //ɨ�����ɫ������ֵ
        
        W1=GetData(5);
        W2=GetData(6);
        W3=GetData(7);
        W4=GetData(8);
        //ɨ�����ɫ������ֵ
        
        A1 = (B1+W1)/2;
    	A2 = (B2+W2)/2;
    	A3 = (B3+W3)/2;
    	A4 = (B4+W4)/2;
        
        SetWaitForTime(0.01);
        //�ȴ�һ�������һ��
        
        tempCS=1;//ֻ����һ��
    }
    PP1 = GetLightSensor(_P1_);
    PP2 = GetLightSensor(_P2_);
    PP3 = GetLightSensor(_P3_);
    PP4 = GetLightSensor(_P4_);
    B1 = (B1+W1)/2;
    B2 = (B2+W2)/2;
    B3 = (B3+W3)/2;
    B4 = (B4+W4)/2;
    //�ж�
    //��ϵͳ�ж�ȡ4���ӿڵ���ɫ��ֵ
     
    S1= PP1 <= A1? 0 :1 ;
    
    S2= PP2 <= A2? 0 :1 ;
    
    S3= PP3 <= A3? 0 :1 ;
    
    S4= PP4 <= A4? 0 :1 ;
    
    
    
}
#endif


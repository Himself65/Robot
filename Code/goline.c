#ifndef _GOLINE_
#define _GOLINE_
#include "HardwareInfo.c"
#include <GetSysTime.h>
#include "light01.c"
#include "speed_control.c"
#include <SetDisplayVar.h>

void goline(int sp)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int S5;
    extern unsigned int g_temp;
    extern double line_proportion;   //Ѳ�߶���
    extern long T14;
    extern long light_ws;
    extern unsigned int g_templ;
    extern unsigned int g_tempr;

    int spl = 0;
    int spr = 0;
    long var0 = 0;
    long vt = 200;
    var0 = GetSysTime();
    //��ȡ���״̬
    light01();
    	//��ȡϵͳʱ��ĺ���
    	//��ȡ���ĺ���
    	//g_tempΪ5ʱ��Ϊֱ��
    	//g_templΪ�������⵽�Ĺ���
    	//g_temprΪ�Ҳ�����⵽�Ĺ���
    	//S1��S2��S3��S4�ֱ�Ϊ�������һ����һ���Ҷ�
    	//g_temp�������һ�����߹��
    	//g_templ��g_tempr��������������һ�����߹��
    	//givetemp������ֵ˳��Ϊg_tempr��g_temp��g_templ
    	//0��ʱ�򲻸�ֵ
    	
    	
    	//���󣬱�֤ÿ�ε�Ѳ�߶�Ҫ��֤temp����ˢ��
    	//�Ĺ���ж� alpha0.2
    	
    	if (S1) //S1���й��
    	{//S1��������
    		if (S1 && !(S2 || S3 || S4))//ֻ�������⵽���
    		{
    			//��ʱ
    			//�����ת
    			spl=-sp;
    			spr=sp;
    			givetemp(0,1,1);
    			T14 = GetSysTime();
    		}
    		else if (S1 && S4)//֮�����ø�����ж�
    		{
    			//ֱ��
    			spl = sp;
    			spr = sp;
    			givetemp(4,5,1);
    		}
    	}
    	else
    	{
    		if (S4)//S4�����й��
    		{//S4��������
    			if (S4 && !(S1 || S2 || S3))//ֻ���Ҷ���⵽���
    			{
    				//��ʱ
    				//���Ҵ�ת
    				spl=sp;
    				spr=-sp;
    				givetemp(4,4,0);
    				T14 = GetSysTime();
    			}
    			else if (S4 && S1)//���Ҷ���⵽���
    			{
    				//ֱ��
    				spl = sp;
    				spr = sp;
    				givetemp(4,5,1);
    			}
    		}
    		else
    		{//����һ�£�||��ֹg_temp����5���Ժ��޸�
    			if (!(S1||S2||S3||S4) || g_temp==5)//��û�м�⵽��磬����5Ϊ��ֱ���м�
    			{
    				//�����ټӵ��жϣ�����׼ȷ
    				//ֱ��
    				spl = sp;
    				spr = sp;
    				if (g_templ==2 && g_temp==2)//�ո�ת��ԲȦ 
    					spl=spl-5;//��ת�꣬�����ٶȿ���̫�󣬽�����΢��С
    				if(g_tempr==3 &&g_temp==3)
    					spr=spl-5;//ͬ��
    			}
    			else
    			{
    			/*S2�Ļ�������*/
    				if (S2)//S2��⵽���
    				{
    					if (S2 && !(S1||S3||S4))
    					{
    						if (g_templ == 1 && g_temp==1)//��һ�������ǲ��������
    						{
    							//����ǵĻ���˵���ڴ����ת���ʱ��
    							//�ж�ʱ��
    							//С��ת
    							if (var0-T14>=vt)//��2��ת��ʱ�����200��λʱ�䣬˵�����һ��������S1
    								{
    									//��ת�����ʱ
    									spl=-sp;
    									spr=sp;
    									givetemp(0,2,2);
    								}
    							else
    								{
    									spl=sp*line_proportion;
    									spr=sp;
    									givetemp(0,5,2);
    								}
    						}
    						else if(g_templ == 2 && g_temp== 2)//��һ�������ǲ�����һ��
    						{
    							//˵�������߻��ߣ�
    							
    							//�����߻��ߴ���
    							spl=sp*line_proportion;
    							spr=sp;
    							
    							//��ֵ�����һ�����ߺ��������һ����������2
    							givetemp(0,2,2);
    						}
    					}
    				}
    				else
    				{
    					if (S3)//S3��⵽���
    					{
    						if (S3 && !(S1||S2||S4))
    						{
    							if (g_tempr == 3 && g_temp==3 )
    							{
    								//��ֵ����S2����������ܳ���
    								//�ж�ʱ��
    								//С��ת
    								    if (var0-T14>=vt)//��2��ת��ʱ�����200��λʱ�䣬˵�����һ��������S1
        								{
        									//��ת�����ʱ
        									spl=-sp;
        									spr=sp;
        									givetemp(3,3,0);
        								}
        							else
        								{
    										//С����ת��
        									spl=sp*line_proportion;
        									spr=sp;
        									givetemp(3,5,0);
        								}
    							}
    						}
    					}
    					else//��û�м�⵽��磬Ҳ���������޷��ж�С��������
    					{
    						if (g_templ == 1 || g_temp==1 )//��һ�����ж�������
    						{
    							spl=-sp;
    							spr=sp;
    							//������ֹͣ
    						}
    						else if(g_templ == 2 || g_temp == 2)
    						{
    							//С����ת��
    							spl=sp*line_proportion;
    							spr=sp;
    						}
    						else if(g_tempr == 4||g_temp==4)
    						{
    							//�����ת��
    							spl=sp;
    							spr=-sp;
    						}
    						else if(g_tempr == 3|| g_temp==3)
    						{
    							//С����ת��
    							spl=sp;
    							spr=sp*line_proportion;
    						}
    						else if(g_temp == 5 || (g_templ==2&&g_tempr==3) )
    						{
    							//��ֱ��
    							spl=sp;
    							spr=sp;
    						}
    					}
    				}
    			}
    		}
    	}
    speed_control(spl, spr);
    SetDisplayVar(10, var0, YELLOW, BLACK);
    SetDisplayVar(11, T14, YELLOW, BLACK);
    SetDisplayVar(12, vt, YELLOW, BLACK);
    SetDisplayVar(9, g_templ, YELLOW, BLACK);
    SetDisplayVar(10, g_temp, YELLOW, BLACK);
    SetDisplayVar(11, g_tempr, YELLOW, BLACK);
}
#endif


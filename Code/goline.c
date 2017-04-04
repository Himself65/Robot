#ifndef _GOLINE_
#define _GOLINE_
#include <GetSysTime.h>
#define _GOLINE_
#include "HardwareInfo.c"
#include <GetSysTime.h>
#include "light01.c"
#include "speed_control.c"

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
    extern long T15;
    extern long light_ws;

    int spl = 0;
    int spr = 0;
    long var0 = 0;
    long vt = 200;
    var0 = GetSysTime();
    //��ȡ���״̬
    light01();
    //�����ڹ����2��2�ں���1��1�����м䣬�������
    
    	if(S1 )//��Ӧ��2����
    	{
    		if(S1 && !(S2||S3||S4) )//����2�к��ߣ��Ʋ���ֱ��ת��
    		{
    			spl=-sp;
    			spr=sp;
    			g_temp=1;
    			T15 = GetSysTime();
            }
            else if(S1 &&! (S2||S3) && S4 ) //�������ߵ����м�û���ߣ��Ʋ���һ��ʮ��·��
            {
    			spl = sp;
    			spr = sp;
    			g_temp=5;
    		}
    	}
    	else if (S4) //��Ӧ��2����
    	{
    		if(S4 && !(S2||S3||S4) )//���Ҷ��к��ߣ��Ʋ���ֱ��ת��
    		{
    			spl=sp;
    			spr=-sp;
    			g_temp=4;
    			T15 = GetSysTime();
    		}
    		else if(S4 &&! (S2||S3) S1)//�������ߵ����м�û���ߣ��Ʋ���һ��ʮ��·��
    		{
    			spl = sp;
    			spr = sp;
    			g_temp=5;
    		}
    	}
    	else if(S2)//��Ӧ��1����
    	{
    		if(S2 && g_temp == 1)//�ж��Ƿ��Ǵ�ת���һ�����
    		{
    
               spl = -sp;
               spr = sp;
    		}
    		if (S2 &&  var0-T15>=vt)//��2��ת��ʱ�����200��λʱ�䣬˵�����һ��������S2
    		{
    			g_temp=2;
    		}
    		else if (S2 && g_temp != 1 )//�ж��ǲ���С����ת���أ�
    		{
    			spl=sp*line_proportion;
                spr=sp;
    		}
    	}
    	
    	
    	else if (S3)//��Ӧ��1����
    	{
    			if(S3 && g_temp == 4)//�ж��Ƿ��Ǵ�ת���һ�����
    			{
    				spl = -sp;
    				spr = sp;
    			}
    			if (S3 &&  var0-T15>=vt)//��2��ת��ʱ�����200��λʱ�䣬˵�����һ��������S2
    			{
    				g_temp=2;
    			}
    			else if (S3 && g_temp != 4 )//�ж��ǲ���С����ת���أ�
    			{
    				spl=sp*line_proportion;
    				spr=sp;
    			}
    	}
    	else if( !(S1||S2||S3||S4) )//�����û�и�Ӧ����
    	{
    	 if( !(S1||S2||S3||S4)&& t_temp ==1)//���һ��������1
    		{
    			spl =-sp;
    			spr =sp;
    		}
    	 if( !(S1||S2||S3||S4)&& t_temp ==2)//���һ��������2
    		{
    			spl=sp*line_proportion;
    			spr=sp;
    		}	 
    	 if( !(S1||S2||S3||S4)&& t_temp ==3)//���һ��������3
    		{
    			spl=sp;
    			spr=sp*line_proportion;
    		}	
    	 if( !(S1||S2||S3||S4)&& t_temp ==4)//���һ��������4
    		{
    			spl =sp;
    			spr =-sp;
    		}
    	 if( !(S1||S2||S3||S4)&& t_temp ==5)//���һ��������5
    		{
    			spl = sp;
    			spr = sp;
    		}
    	}
    			
    speed_control(spl, spr);
}
#endif


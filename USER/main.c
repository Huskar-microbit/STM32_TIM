#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 

/************************************************
Huskar @TIMER 
************************************************/


 int main(void)
{		
 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	TIM3_Int_Init(4999,7199);//10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms     Ԥ��Ƶpcs:72M/7200=10KHz��  Ԥװ��ָarr:500ms:4999�ݼ���0 ������
	
	
   	while(1)
	{
		LED0=!LED0;
		delay_ms(200);		   
	}	 

}	 
 

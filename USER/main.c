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
 
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	TIM3_Int_Init(4999,7199);//10Khz的计数频率，计数到5000为500ms     预分频pcs:72M/7200=10KHz；  预装载指arr:500ms:4999递减到0 个节拍
	
	
   	while(1)
	{
		LED0=!LED0;
		delay_ms(200);		   
	}	 

}	 
 

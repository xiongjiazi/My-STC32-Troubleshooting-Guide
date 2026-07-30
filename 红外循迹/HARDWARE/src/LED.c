#include "LED.h" 

sbit LED_R=P0^5;		//重定义LED引脚功能
sbit LED_L=P3^4;		//重定义LED引脚功能 


void LED_Init_Port(void)
{	
 		P3M0 = 0x10;        
  	P3M1 = 0x00; 

		P0M0 = 0x20;        
		P0M1 = 0x00; 		
	
	  LED_OFF(); 
	
}

void LED_ON(void)
{ 
	
	LED_R=1;   //输出高电平
	LED_L=1; 
	
}

void LED_OFF(void)
{ 
	
	LED_R=0;   //输出低电平
	LED_L=0; 
	
}



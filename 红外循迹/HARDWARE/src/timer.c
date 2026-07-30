#include "timer.h"   
 #include "hw.h"  
#include "motor.h" 

uint16 Time_Count = 0; 
uint8 Time_Count_pwm = 0; 
uint8 PWM_Count = 40; //占空比


void Timer4Init(void)
{
	T4T3M &= 0xBF;                  //定时器4设置为定时方式
	T4T3M |= 0x20;                  //设置定时器4为1T模式
	T4L = 0x90;                     //1T模式下初始装载值 
	T4H = 0xE8;                     //1T模式下初始装载值 
	IE2  |=  (1<<6);	              //使能定时器4中断
	T4T3M |= 0x80;                  //打开定时器4
} 


void timer4_int (void) interrupt 20
{
	  if(++Time_Count>=4000) //最长计时间 1s
		{
       Time_Count=0;
		}	 
  	 if(++Time_Count_pwm>100)
	 {
		  Time_Count_pwm=0;
	 } 
	 if(Time_Count_pwm>=PWM_Count)//PWM调速
	 {
		  Car_Stop(); //置为低电平	 
		 
	 }else{		 
		 
      Adjust_Pwm_data();//调节PWM
	 } 
} 







































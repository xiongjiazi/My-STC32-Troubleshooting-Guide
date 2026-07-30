#include <STC32G.H>
#include "intrins.h"
#include "delay.h"  
#include "motor.h" 
#include "timer.h"    
#include "uart1.h" 
#include "hw.h"  
#include "LED.h" 

void main(void)
{
   WTST = 0;  //设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
   EAXFR = 1; //扩展寄存器(XFR)访问使能
   CKCON = 0; //提高访问XRAM速度
	 
	 Motor_Init_Port(); //电机初始化

	 Timer4Init(); //定时器初始化,计数时间使用
	
	 Uart1_Init(); //串口初始化 
  
	 HW_Init_Port(); //红外端口
	
	 LED_Init_Port(); //LED显示

  while (1)
	{ 	
		  if(Get_HW_MR==1&&Get_HW_ML==1&&Get_HW_R==1&&Get_HW_L==1)
			 {   
					 Car_State_number=7;  //停车
				 
					 LED_ON();         //灯闪
					 Delay100ms();
					 LED_OFF();
					 Delay100ms();

				 	 LED_ON();            //灯闪
					 Delay100ms();
					 LED_OFF();
					 Delay100ms();
				 
				 	 LED_ON();          //灯闪
					 Delay100ms();
					 LED_OFF();
					 Delay100ms();
				 
					 Car_State_number=1; 
				 
				   PWM_Count=15;  
				   Delay100ms(); //缓冲掉
				   Delay100ms(); 
			 }else{
		
										/******************状态一：直行状态****************************************/	
												//情况一：黑线在正中间，都没有识别到，直走
												if(Get_HW_L==0&&Get_HW_ML==0&&Get_HW_MR==0&&Get_HW_R==0)
												{
													Car_State_number=1; //慢速直走 
												}
												//情况二：中间两个识别到黑线，直走
												if(Get_HW_L==0&&Get_HW_ML==1&&Get_HW_MR==1&&Get_HW_R==0)
												{   				
													while(1) //防止由于拐弯过大，要纠正回来
													{  
														Car_State_number=1; //慢速直走 
														if(Get_HW_MR==0||Get_HW_ML==0)
														{  
															break; //跳出循环
														} 
													}	
												}
												//情况三：左中侧检测到，稍微左转后直走
												if(Get_HW_L==0&&Get_HW_ML==1&&Get_HW_MR==0&&Get_HW_R==0)// 慢左转
												{   							
													while(1) //防止由于拐弯过大，要纠正回来
													{  
														   Car_State_number=3; 					
														if(Get_HW_ML==0||Get_HW_MR==1||Get_HW_R==1)
														{  
															break; //跳出循环
														} 
													}	
												}
												
												//情况四：右中侧检测到，稍微右转后直走
												if(Get_HW_L==0&&Get_HW_ML==0&&Get_HW_MR==1&&Get_HW_R==0)//慢右转
												{   							
													while(1) //防止由于拐弯过大，要纠正回来
													{  
														   Car_State_number=5; //慢右转
														if(Get_HW_MR==0||Get_HW_ML==1||Get_HW_L==0)
														{  
															break; //跳出循环
														} 
													}	
												}	
												
										/******************状态二：左转状态****************************************/		
												//情况一：左外侧检测到，大拐弯
												if(Get_HW_L==1&&Get_HW_ML==0&&Get_HW_MR==0&&Get_HW_R==0)//
												{    										
													while(1) //防止由于拐弯过大，要纠正回来
													{  
														  Car_State_number=4; //快速左转				
														if(Get_HW_ML==1||Get_HW_MR==1||Get_HW_R==1)
														{  
															break; //跳出循环
														} 
													}	
												}
												//情况二：左外测和左中测检测到，大拐弯
												if(Get_HW_L==1&&Get_HW_ML==1&&Get_HW_MR==0&&Get_HW_R==0)
												{    										
													while(1) //防止由于拐弯过大，要纠正回来
													{  
														   Car_State_number=4; //快速左转
				
														if(Get_HW_MR==1||Get_HW_R==1)
														{  
															break; //跳出循环
														} 
													}	
												}
												
										/******************状态三：右转状态****************************************/						
												//右外侧检测到，大拐弯
												if(Get_HW_L==0&&Get_HW_ML==0&&Get_HW_MR==0&&Get_HW_R==1)
												{   						  										
													while(1) //防止由于拐弯过大，要纠正回来
													{  
														Car_State_number=6; //快速右转 

														if(Get_HW_MR==1||Get_HW_ML==1||Get_HW_L==1)
														{  
															break; //跳出循环
														} 
													}	
												}	
												//右侧和右外侧检测到，大拐弯
												if(Get_HW_L==0&&Get_HW_ML==0&&Get_HW_MR==1&&Get_HW_R==1)
												{   						  										
													while(1) //防止由于拐弯过大，要纠正回来
													{  
														Car_State_number=6; //快速右转 

														if(Get_HW_ML==1||Get_HW_L==1)
														{  
															break; //跳出循环
														} 
													}	
												}	
										/******************状态四：直角处理****************************************/						
												//右外侧检测到，大拐弯
												if(Get_HW_L==0&&Get_HW_ML==1&&Get_HW_MR==1&&Get_HW_R==1)
												{   						  																							 
													  while(1)
														{
														    Car_State_number=8; //快速右转 
																if(Get_HW_L==1)
																{  
																	break; //跳出循环
																} 																
														}
												}	

	   }
	}		
}

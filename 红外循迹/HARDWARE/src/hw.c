#include "hw.h"  
#include "motor.h" 

uint8 Car_State_number = 0; //小车状态值

void HW_Init_Port(void)
{
	
		P0M0 = 0x00;        
  	P0M0 = 0x00;	//0100 0000 P0.6高阻输入

	
		P4M0 = 0x00;        
  	P4M1 = 0x00;	//1000 0000 P4.7高阻输入
	
	
		P3M0 = 0x00;        
  	P3M0 = 0x00;	 //0000 1100 P3.2/3.3高阻输入

	Get_HW_MR=1;
	Get_HW_ML=1;
	Get_HW_R=1;
	Get_HW_L=1 ;
					
				
}

void Adjust_Pwm_data(void)
{
		switch(Car_State_number)
		{
			case 1:  Car_Forword(15);break;
			case 2:  Car_Forword(5);break;
			
			case 3:  Car_Turn_Left(50);break;
			case 4:  Car_Turn_Left(80);break;
			
			case 5:  Car_Turn_Right(50);break; 
			case 6:  Car_Turn_Right(80);break; 
		
			case 7:  Car_Stop();break;
			case 8:  Car_Turn_Right1(85);break; 
			
			default :Car_Stop(); break;
		}	
}




































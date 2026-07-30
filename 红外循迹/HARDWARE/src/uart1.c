#include "uart1.h" 
#include "delay.h" 


bit B_TX1_Busy; //发送忙标志


void Uart1_Init(void)
{	 
	P3M1 &= 0xFC;	P3M0 &= 0xFC;	                  //设置P3.0 ,P3.1为准双向口  
	
	PCON &= 0x3f;		//波特率不倍速，串行口工作方式由SM0、SM1决定
	SCON = 0x50;		//8位数据,可变波特率，启动串行接收器
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xfe;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0f;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xB2;		  //设定定时初值
	TH1 = 0xB2;		  //设定定时器重装值
	ET1 = 0;		    //禁止定时器1中断
	TR1 = 1;		    //启动定时器1
	ES = 1;         // 串口1中断打开 
 	
 	EA = 1;               //总中断打开 
	
	delay_ms(100);
}


{
	  ES = 0;  	                  // 串口1中断关闭
	  if (RI)                     //串行接收到停止位的中间时刻时，该位置1
   {
      RI = 0;                 //清除RI位 （该位必须软件清零）SBUF; 
		  program_automatic_update();	      
   }
   if (TI)                    //在停止位开始发送时，该位置1
   {
      TI = 0;                 //清除TI位（该位必须软件清零） 
		  B_TX1_Busy = 0;
   }
	 ES =  1;                   // 串口1中断打开
}

//void PrintString1(unsigned char *puts)
//{
//    for (; *puts != 0;  puts++)     //遇到停止符0结束
//    {
//        SBUF = *puts;
//        B_TX1_Busy = 1;
//        while(B_TX1_Busy);
//    }
//}


void program_automatic_update(void)
{
    static unsigned char recv_cnt = 0;
    if (SBUF == 0xAF)
    {
        if (++recv_cnt >= 5)
        {
            recv_cnt = 0;
            IAP_CONTR = 0x60;   //触发软件复位，从ISP开始执行
        }
    }
    else
    {
        recv_cnt = 0;
    }
}














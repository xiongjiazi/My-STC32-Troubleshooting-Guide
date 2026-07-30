#define MAIN_Fosc        24000000UL   //定义主时钟 

void delay_ms(unsigned int ms)
{
    unsigned int  i;
    do{
        i = MAIN_Fosc / 6000;
        while(--i);   //6T per loop
      }while(--ms);
}
void Delay100ms(void)		//@24.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 13;
	j = 45;
	k = 214;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}







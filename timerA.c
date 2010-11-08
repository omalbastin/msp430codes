#include<io.h>

void init()
{
	WDTCTL = WDTPW | WDTHOLD;
	TACTL = MC_2 | ID_0 | TASSEL_2 | TACLR;
	P1DIR = 0x41;
	P1OUT = 0x01;
}
void delay()
{
	while((TACTL & 1) == 0){
	}
	TACTL = TACTL & ~1;
	return;
}

main()
{
	init();
	while(1){
		P1OUT=0x40;
		delay();
		P1OUT=0x01;
		delay();
	}
}


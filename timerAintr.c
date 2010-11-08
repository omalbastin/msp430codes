#include<io.h>
#include<signal.h>

void init()
{
	WDTCTL = WDTPW | WDTHOLD;
	TACTL = MC_2 | ID_3 | TASSEL_2 | TAIE | TACLR;//TAIE for enabling timer interrupt
	_BIS_SR(GIE);// 
	P1DIR = 0x41;
	P1OUT = 0x01;
}

interrupt (TIMERA1_VECTOR) IntServiceRoutine(void)
{
	TACTL = (TACTL & ~1);
	P1OUT ^=0x040|0x01;
}
main()
{
	init();
	while(1){
	}
}


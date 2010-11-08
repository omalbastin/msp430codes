#include<io.h>
#include<signal.h>

int led1 = 0x01,led2 = 0x40;

void init()
{
	WDTCTL = WDTPW | WDTHOLD;
	TACTL = MC_2 | ID_3 | TASSEL_2 | TAIE | TACLR;
	_BIS_SR(GIE);
	P1DIR = 0x41;
	P1OUT = 0x01;
}

interrupt (TIMERA1_VECTOR) IntServiceRoutine(void)
{
	int n = 0, i = 1000, j = 0;
	led1 ^= 0x41;
	led2 ^= 0x41;
	while(i > 0){
		while(n < i){
			P1OUT = led1;
			n++;
		}
		n = 0;
		j = j + 10;
		i = i - 10;
		while(n < j){
			P1OUT = led2;
			n++;
		}
	}
	TACTL = TACTL & ~1;
	return;
}

main()
{
	

	init();
	while(1){	
	}
}

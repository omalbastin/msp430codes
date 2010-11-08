#include<io.h>
#include<signal.h>

int ledon = 0x1,ledoff = 0;

void init()
{
	WDTCTL = WDTPW | WDTHOLD;
	TACTL = MC_2 | ID_3 | TASSEL_2 | TAIE | TACLR;
	_BIS_SR(GIE);
	P1DIR = 0x41;
//	P1OUT = 0x01;
}

interrupt (TIMERA1_VECTOR) IntServiceRoutine(void)
{
	int n = 0, i = 1000, j = 0;
	ledon ^= 0x01;
	ledoff ^= 0x01;
	while(i > 0){
		while(n < i){
			P1OUT = ledon;
			n++;
		}
		n = 0;
		j = j + 10;
		i = i - 10;
		while(n < j){
			P1OUT = ledoff;
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

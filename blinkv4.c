#include<io.h>
#include<signal.h>
#define TOTAL_TIME 1000

int on_time = 0,up = 1;

void init()
{
	WDTCTL = WDTPW | WDTHOLD;
	TACTL = MC_2 | ID_0 | TASSEL_2 | TAIE | TACLR;
	_BIS_SR(GIE);
	P1DIR = 0x41;
}

void led_on()
{
	P1OUT = 1;
}

void led_off()
{
	P1OUT = 0;
}

void delay(int duration)
{
	int n=0;
	while(n < duration) {
		n++;
	}
}

interrupt (TIMERA1_VECTOR) IntServiceRoutine(void)
{
	TACTL =TACTL & ~1;
	if(on_time > TOTAL_TIME)
		up = 0;
	if(on_time < 0)
		up = 1;
	if(up)
		on_time +=10; 
	else
		on_time -=10;
	return;
}

main()
{
	

	init();
	while(1) {
		led_on();
		delay(on_time);
		led_off();
		delay(TOTAL_TIME-on_time);
	}
}

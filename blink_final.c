#include<io.h>
#include<signal.h>
#define TOTAL_TIME 1000
#define LED_ON P1OUT = 1
#define LED_OFF P1OUT = 0

int on_time = 0,up = 1;

void init()
{
	WDTCTL = WDTPW | WDTHOLD;
	TACTL = MC_2 | ID_0 | TASSEL_2 | TAIE | TACLR;
	_BIS_SR(GIE);
	P1DIR = 0x41;
}

void delay(int duration)
{
	int i;
	for(i = 0; i < duration; i++);
}

interrupt (TIMERA1_VECTOR) IntServiceRoutine(void)
{
	TACTL =TACTL & ~1;
	if(on_time >= TOTAL_TIME)
		up = 0;
	if(on_time <= 0)
		up = 1;
	if(up)
		on_time +=100; 
	else
		on_time -=100;
	return;
}

main()
{
	

	init();
	while(1) {
		LED_ON;
		delay(on_time);
		LED_OFF;
		delay(TOTAL_TIME-on_time);
	}
}

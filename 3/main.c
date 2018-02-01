#include "msp.h"

int is_press = 0;

int main(void) {
	P3->SEL1 &= 0x00;
	P3->SEL0 &= 0x00;
	P3->DIR &= ~0x40;
	P3->REN |= 0x40;
	P3->OUT |= 0x40;

	P5->SEL1 &= 0x00;
	P5->SEL0 &= 0x00;
	P5->DIR |= 0x06;
	P5->OUT = 0x02;

	while(1) {
		if (!(P3->IN & 0x40)) {
			is_press = 1;
		}
		if ((P3->IN & 0x40) && (is_press == 1)) {
			is_press = 0;
			P5->OUT ^= 0x06;
		}
	}
}

#include "msp.h"

int main(void) {
	P1->SEL1 &= 0x00;
	P1->SEL0 &= 0x00;
	P1->DIR &= ~0x12;
	P1->REN |= 0x12;
	P1->OUT |= 0x12;

	P2->SEL1 &= 0x00;
	P2->SEL0 &= 0x00;
	P2->DIR |= 0x04;

	while(1) {
		if (!(P1->IN & 0x02))
			P2->OUT = 0x04;
		else if (!(P1->IN & 0x10))
			P2->OUT = 0x00;
	}
}

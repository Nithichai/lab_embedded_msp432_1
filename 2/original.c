#include "msp.h"

int main(void) {
	P1->SEL1 &= 0x00;
	P1->SEL0 &= 0x00;
	P1->DIR &= ~2;
	P1->REN |= 2;
	P1->OUT |= 2;

	P2->SEL1 &= ~1;
	P2->SEL0 &= ~1;
	P2->DIR |= 1;

	while(1) {
		if (P1->IN & 2)
			P2->OUT &= ~1;
		else
			P2->OUT |= 1;
	}
}

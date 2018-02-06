#include "msp.h"

int main(void) {
	P1->SEL1 &= 0x00;
	P1->SEL0 &= 0x00;
	P1->DIR &= ~0x10;
	P1->REN |= 0x10;
	P1->OUT |= 0x10;

	P2->SEL1 &= ~1;
	P2->SEL0 &= ~1;
	// GREEN 0x02
	// BLUE 0x04
	P2->DIR |= 0x02;

	while(1) {
		if (P1->IN & 0x10)
			// GREEN 0x02
			// BLUE 0x04
			P2->OUT &= ~0x02;
		else
			// GREEN 0x02
			// BLUE 0x04
			P2->OUT |= 0x02;
	}
}

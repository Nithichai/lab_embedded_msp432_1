#include "msp.h"

void delay_ms(uint32_t delay);

int is_press = 0;
int state = 0;

int main(void) {
	P1->SEL1 &= 0x00;
	P1->SEL0 &= 0x00;
	P1->DIR &= ~0x12;
	P1->REN |= 0x12;
	P1->OUT |= 0x12;

	P2->SEL1 &= 0x00;
	P2->SEL0 &= 0x00;
	P2->DIR |= 0x07;

	while(1) {
		// change state
		if (!(P1->IN & 0x02)) {
			is_press = 1;
		}
		if (!(P1->IN & 0x10)) {
			state = 0;
			is_press = 0;
			P2->OUT = 0x00;
		}
		if ((P1->IN & 0x02) && is_press == 1) {
			is_press = 0;
			state++;
			if (state > 3) {
				state = 1;
			}
		}
		// state checking
		if (state == 0) {
			P2->OUT = 0x00;
		} else if (state == 1) {
			P2->OUT = 0x01;
			delay_ms(1000);
			P2->OUT = 0x00;
			delay_ms(1000);
		} else if (state == 2) {
			P2->OUT = 0x02;
			delay_ms(500);
			P2->OUT = 0x00;
			delay_ms(500);
		} else if (state == 3) {
			P2->OUT = 0x04;
			delay_ms(100);
			P2->OUT = 0x00;
			delay_ms(100);
		}
	}
}

void delay_ms(uint32_t delay) {
	uint32_t i;
	SysTick->LOAD = 3000 - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = 0x00000005;
	for (i = 0; i < delay; i++) {
		while((SysTick->CTRL & 0x00010000) == 0) {}
	}
	SysTick->CTRL = 0;
}

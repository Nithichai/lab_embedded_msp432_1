#include "msp.h"

void delay_ms(uint32_t delay);

int main(void) {
	P2->SEL1 &= ~0x02;
	P2->SEL0 &= ~0x02;
	P2->DIR = 0x07;
	P2->OUT = 0x04;
	while (1) {
		P2->OUT = P2->OUT << 1;
		if (P2->OUT == 0x08) {
			P2->OUT = 0x01;
		}
		delay_ms(2000);
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

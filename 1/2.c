#include "msp.h"

void delay_ms(uint32_t delay);
void delay_10ms(uint32_t delay);
void delay_10us(uint32_t delay);

int main(void) {
	P2->SEL1 &= ~0x02;
	P2->SEL0 &= ~0x02;
	P2->DIR |= 0x02;
	while (1) {
		// delay_10ms(100);
		delay_10us(100000);
		P2->OUT ^= 0x02;
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

void delay_10ms(uint32_t delay) {
	uint32_t i;
	SysTick->LOAD = 30000 - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = 0x00000005;
	for (i = 0; i < delay; i++) {
		while((SysTick->CTRL & 0x00010000) == 0) {}
	}
	SysTick->CTRL = 0;
}

void delay_10us(uint32_t delay) {
	uint32_t i;
	SysTick->LOAD = 30 - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = 0x00000005;
	for (i = 0; i < delay; i++) {
		while((SysTick->CTRL & 0x00010000) == 0) {}
	}
	SysTick->CTRL = 0;
}

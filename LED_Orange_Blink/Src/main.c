#include <stdint.h>

int main(void)
{
	volatile uint32_t *pRCC_AHB1ENR = (uint32_t*) 0x40023800 + 12;
	volatile uint32_t *pGPIOD_MODER = (uint32_t*) 0x40020C00 + 0;
	volatile uint32_t *pGPIOD_ODR   = (uint32_t*) 0x40020C00 + 5;

	*pRCC_AHB1ENR |= 1 << 3;

	*pGPIOD_MODER &= ~(3 << 28);
	*pGPIOD_MODER |= (1 << 28);

	while(1)
	{
		*pGPIOD_ODR ^= 0x00004000;

		for(int i = 0; i < 500000; i++);
	}
}

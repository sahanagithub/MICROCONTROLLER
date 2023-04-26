#include"caputer.h"


void tim2_pa5_output_compare(void)
{

	 //Enable clock access to GPIOA/
	RCC->AHB1ENR |=GPIOAEN;

	//Set PA5 mode to alternate function/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |=(1U<<11);

	//Set PA5 alternate function type to TIM2_CH1 (AF01)/
	GPIOA->AFR[0] |=AFR5_TIM;

	//Enable clock access to tim2/
	RCC->APB1ENR |=TIM2EN;

	//Set prescaler value/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000
	//Set auto-reload value/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1

	//Set output compare toggle mode ccmr1/
	TIM2->CCMR1 |= (1U<<4)|(1U<<5);

	TIM2->CCER |= (1U<<0);
	//Enable tim2 ch1 in compare mode ccer/


	//Clear counter/
	TIM2->CNT = 0;
	//Enable timer/
	TIM2->CR1 = CR1_CEN;
}


void tim3_pa6_input_capture(void)
{

	//Enable clock access to GPIOA/
	RCC->AHB1ENR |=GPIOAEN;

	//Set PA6 mode to alternate function/
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |=  (1U<<13);

	//Set PA6 alternate function type to TIM3_CH1 (AF02)/
	//GPIOA->AFR[0] |=AFR5_TIM;//
	GPIOA->AFR[0] |=AFR6_TIM;

    //Enable clock access to tim3/
	RCC->APB1ENR |=TIM3EN;

	//Set Prescaler/
	TIM3->PSC = 16000 -1; // 16 000 000 /16 000

	//Set CH1 to input capture ccmr1/
	TIM3->CCMR1 = CCER_CC1S;

	//Set CH1 to capture at rising edge ccer/
	TIM3->CCER |= CCER_CC1E;

	//Enable TIM3/
	TIM3->CR1 = CR1_CEN;

}

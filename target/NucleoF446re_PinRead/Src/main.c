/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*nButton is conected on PC13*/
#include<stdint.h>
#include<stdio.h>

int main(void)
{
	uint32_t *pClkCtrlReg=(uint32_t*)0x40023830;
	uint32_t *pPortAModeReg=(uint32_t*)0x40020000;
	uint32_t *pPortAOutReg=(uint32_t*)0x40020014;

	uint32_t *pPortCModeReg=(uint32_t*)0x40020800;	//0x4002 0800 - 0x4002 0BFF		//GPIOC base adres
	uint32_t *pPortCInReg=(uint32_t*)0x40020810;


	//Enable the Clock GPIOD, GPOIA
	*pClkCtrlReg |= (1<<0);//*pClkCtrlReg |= 0x01;	//Enable Clock on PortA
	*pClkCtrlReg |= (1<<2);							//Enable Clock on PortC //6.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)

	//Configure PA5 IO pin as output
	//a. clear 10 and 11 position
	*pPortAModeReg &=~(3<<10);//*pPortAModeReg &= 0xFFFFF3FF;
	//b make 10 position as 1 set
	*pPortAModeReg |= (1<<10);//*pPortAModeReg |= 0x00000400;

	//Configuring PC13 as input mode (GPIOC MODE Register)
	*pPortCModeReg &=~(3<<13);

	while(1){
	//read the pin status of the pin PC13 //7.4.5 GPIO port input data register (GPIOx_IDR) (x = A..H)
	//uint8_t pinStatus=(uint8_t)(*pPortCInReg & 0x2000); /////.......
		uint8_t pinStatus=0;

	if(pinStatus){
		//turn on LED
		*pPortAModeReg |= (1<<10);
		}else{
			//turn off the LED
			*pPortAModeReg &=~(3<<10);
			}

	//set 5 bit of the output data register....
	*pPortAOutReg |=(1<<5);//*pPortAOutReg |=0x00000020;
	}//end of while
}//endof main

/*Adres of the clock control register (AHB1ENR)
 * 0x4002 3800 - 0x4002 3BFF RCC
 * 0x40023800+0x30 ==>>0x40023830
 *
 * Adres of GPIOA
 * 0x4002 0000 - 0x4002 03FF
 * 0x4002 0000+0x00==>0x40020000
 *
 * Adres of GPIOA output data register (used to write)
 *  0x4002 0000+0x00==>0x4002 0000
 *  0x4002 0000+0x14==>0x40020014
 *
 * */


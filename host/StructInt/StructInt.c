/*
 * StructInt.c
 *
 *  Created on: 12 авг. 2020 г.
 *      Author: SimpalsGarage
 */


#include<stdio.h>
#include<stdint.h>

struct carModel{
	unsigned int carNumber;
	uint32_t carPrice;
	uint16_t carMaxSpeed;
	float	carWeight;
};

int main(void)
{

	struct carModel carBMW={2021,15000, 220, 1330};
//	struct carModel carFord={2021,15000, 220, 1330};
//	struct carModel carHonda={.carWeight =90.90, .carPrice = 15000};

	printf("Details of car BMW is as follows\n");

	printf("carPrice= %u\n",carBMW.carPrice);

	/*	carFord.carNumber = 1011;

	printf("carNumber= %u\n",carBMW.carNumber);
	printf("carPrice= %u\n",carBMW.carPrice);
	printf("carMaxSpeed= %u\n",carBMW.carMaxSpeed);
	printf("carWeight= %f\n",carBMW.carWeight);
	printf("carHonda carWeight = %f\n",carHonda.carWeight);

*/
	printf("sizeof=%u\n", sizeof(unsigned int));
	printf("sizeof of structure carModel is =%u\n", sizeof(struct carModel));

	return 0;
}

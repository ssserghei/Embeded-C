/*
 * DataAllignment.c
 *
 *  Created on: 12 авг. 2020 г.
 *      Author: SimpalsGarage
 */


#include<stdint.h>
#include<stdio.h>

struct DataSet
{
	char 	data1;
	int 	data2;
	char 	data3;
	short 	data4;

};



int main (void)
{

	struct DataSet data;

		data.data1=0x11;
		data.data2=0XFFFFEEEE;
		data.data3=0x22;
		data.data4=0xABCD;

		uint8_t *ptr;

		ptr=&data; //


	printf("Memory address				Content\n");
	printf("====================================\n");

}

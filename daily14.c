/***********************************************
Author: Derrick Lor
Date: 30 October, 2018
Purpose: Asks user if they want to convert lengths
or weights using 1 or 2 respectively. If they input
0 then terminate the program. Then ask if they want to convert
metric to us or us to metric depending on length or weight.
Sources of Help: Inclass notes on pointers and dereference
 Time Spent: 26mins
***********************************************/
#include <stdio.h>

void run_length_or_weights(int* pContinue_playing);
void convert_lengths(int* in_loop);
void length_to_metric(void);
void length_to_us(void);

void convert_weights(int* in_loop);
void weight_to_metric(void);
void weight_to_us(void);

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int continue_playing = 1;

	//infinite loop until continue_playing is assigned 0
	while (continue_playing)
	{
		//the function below takes &continue_playing,
		//which is the address of continue_playing
		run_length_or_weights(&continue_playing);
	}
	return 0;
}

/**
Asks user to choose from lengths or weights or 0 to exit
@param pContinue_playing the pointer to the address of continue_playing
*/
void run_length_or_weights(int* pContinue_playing)
{
	int choice, noc;
	int in_loop = 1;//used to keep user looping inside length or weight conversion
	printf("Do you want to convert values that are lengths or weights?\n");
	printf("(0)Exit \n(1)lengths \n(2)weights\n");
	noc = scanf(" %d", &choice);
	clear_keyboard_buffer();
	while (noc != 1 || choice < 0 || choice > 2)
	{
		printf("Error!!\n");
		printf("Do you want to convert values that are lengths or weights?\n");
		printf("(0)Exit \n(1)lengths \n(2)weights\n");
		noc = scanf(" %d", &choice);
		clear_keyboard_buffer();
	}
	switch (choice)
	{
	case 0:
		//dereference the pointer so it changes to the location
		//in memory, then assign it a new value of 0
		*pContinue_playing = 0;
		break;
	case 1:
		while (in_loop)
		{
			convert_lengths(&in_loop);
		}
		break;
	case 2:
		while (in_loop)
		{
			convert_weights(&in_loop);
		}
		break;
	}
}

void convert_lengths(int* pin_loop)
{
	int choice, noc;

	printf("(0) Exit\n");
	printf("(1) Convert lengths from feet / inches to meters / centimeters\n");
	printf("(2) Convert lengths from meters / centimeters to feet / inches\n");
	noc = scanf(" %d", &choice);
	clear_keyboard_buffer();

	while (noc != 1 || choice < 0 || choice > 2)
	{
		printf("Error!!\n");
		printf("(0) Exit\n");
		printf("(1) Convert lengths from feet / inches to meters / centimeters\n");
		printf("(2) Convert lengths from meters / centimeters to feet / inches\n");
		noc = scanf(" %d", &choice);
		clear_keyboard_buffer();
	}
	switch (choice)
	{
	case 0: printf("User chose to exit.\n");
		*pin_loop = 0;
		return;
		break;
	case 1: length_to_metric();
		break;
	case 2: length_to_us();
		break;
	}
}

void convert_weights(int* pin_loop)
{
	int choice, noc;

	printf("(0) Exit\n");
	printf("(1) Convert weights from pounds/ounces to kilograms/grams\n");
	printf("(2) Convert weights from  kilograms/grams to pounds/ounces\n");
	noc = scanf(" %d", &choice);
	clear_keyboard_buffer();

	while (noc != 1 || choice < 0 || choice > 2)
	{
		printf("Error!!\n");
		printf("(0) Exit\n");
		printf("(1) Convert weights from pounds/ounces to kilograms/grams\n");
		printf("(2) Convert weights from  kilograms/grams to pounds/ounces\n");
		noc = scanf(" %d", &choice);
		clear_keyboard_buffer();
	}
	switch (choice)
	{
	case 0: printf("User chose to exit.\n");
		*pin_loop = 0;
		return;
		break;
	case 1: weight_to_metric();
		break;
	case 2: weight_to_us();
		break;
	}
}

void length_to_metric(void)
{
	printf("User chose convert length to metric.\n");
}

void length_to_us(void)
{
	printf("User chose convert length to us.\n");
}

void weight_to_metric(void)
{
	printf("User chose convert weight to metric.\n");
}

void weight_to_us(void)
{
	printf("User chose convert weight to us.\n");
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

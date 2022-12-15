/***********************************************
Author: Derrick Lor
Date: 30 October, 2018
Purpose: Asks user if they want to convert lengths
or weights using 1 or 2 respectively. If they input
0 then terminate the program.
Sources of Help: Inclass notes on pointers and dereference
 Time Spent: 57mins
***********************************************/
#include <stdio.h>

void run_values_or_weights(int* pContinue_playing);
void convert_lengths(void);
void convert_weights(void);
void clear_keyboard_buffer(void);
int main(int argc, char* argv[])
{
	int continue_playing = 1;
	//create a pointer and assign it the address of continue_playing
	int* pContinue_playing = &continue_playing;
	
	//infinite loop until continue_playing is assigned 0
	while (continue_playing)
	{
		//the function below takes pContinue_playing, which is a pointer
		//to the address of continue_playing
		run_values_or_weights(pContinue_playing);
	}
	return 0;
}

/**
Asks user to choose from lengths or weights or 0 to exit
@param pContinue_playing the pointer to the address of continue_playing
*/
void run_values_or_weights(int* pContinue_playing)
{
	int choice, noc;
	printf("Do you want to convert values that are lengths or weights?\n");
	printf("(0)exit \t(1)lengths \t(2)weights\n");
	noc = scanf(" %d", &choice);
	clear_keyboard_buffer();
	while (noc != 1 || choice < 0 || choice > 2)
	{
		printf("Error!!\n");
		printf("Do you want to convert values that are lengths or weights?\n");
		printf("(0)exit \t(1)lengths \t(2)weights\n");
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
		convert_lengths();
		break;
	case 2: 
		convert_weights();
		break;
	}
}

void convert_lengths(void)
{
	printf("User chose convert lengths.\n");
}
void convert_weights(void)
{
	printf("User chose convert weights.\n");
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
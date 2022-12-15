/***********************************************
Author: Derrick Lor
Date: 28 Sept, 2018
Purpose: Asks the user to input a negative integer, if they enter a character 
or positive integer it will keep asking for the correct input.
Time Spent: 40 minutes
***********************************************/
#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int number;
	int noc;

	printf("Please enter a negative integer: ");
	noc = scanf("%d", &number);
	clear_keyboard_buffer();

	while (noc != 1 || number >= 0)
	{
		printf("Sorry, you must enter a negative integer less than zero: \n");
		printf("Please enter a negative integer: ");
		noc = scanf("%d", &number);
		clear_keyboard_buffer();
	}
	
	printf("The negative integer was: %d", number);
	return 0;
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
/***********************************************
Author: Derrick Lor
Date: 1 Oct, 2018
Purpose: Prompts the user how many asterisks(1-79) they
want printed on a line. Keeps asking for input if they enter
an invalid input.
Time Spent: 9 minutes
***********************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);
void draw_line(int);

int main(int argc, char* argv[])
{
	int number;
	int noc;

	printf("Please enter the number of asterisks you want in your line: ");
	noc = scanf("%d", &number);
	clear_keyboard_buffer();

	while (noc != 1 || number <= 0 || number >= 80)
	{
		printf("I'm sorry, that number is unrecognized or out of range, try [1-79]: \n");
		printf("Please enter the number of asterisks you want in your line: ");
		noc = scanf("%d", &number);
		clear_keyboard_buffer();
	}

	draw_line(number);
	
	return 0;
}

void draw_line(int number)
{
	while (number > 0)
	{
		printf("*");
		number--;
	}
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
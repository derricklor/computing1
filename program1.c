/***********************************************
Author: Derrick Lor
Date: 12 October, 2018
Purpose: Asks user for starting number above 1 and below 1000.
Next asks user for ending number above starting number but below 10000.
Then prints the number of steps to reach 1 using the collatz conjecture for all
the numbers between starting and ending numbers.
Time Spent: 39mins
***********************************************/

#include <stdio.h>

int get_collatz_number_of_steps(int);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int starting_point;
	int ending_point;
	int noc;
	
	//get the starting point number
	printf("Enter a starting point: ");
	noc = scanf("%d", &starting_point);
	clear_keyboard_buffer();
	while (noc != 1 || starting_point < 2 || starting_point >= 1000)
	{
		printf("Sorry, your input must be a positive integer above 1 and below 1,000.\n");
		printf("Enter a starting point: ");
		noc = scanf("%d", &starting_point);
		clear_keyboard_buffer();
	}

	//get the ending point number
	printf("Enter an ending point: ");
	noc = scanf("%d", &ending_point);
	clear_keyboard_buffer();
	while (noc != 1 || ending_point < starting_point || ending_point >= 10000)
	{
		printf("Sorry, your input must be a positive integer and be greater ");
		printf("than your starting point, while still below 10,000.\n");
		printf("Enter an ending point: ");
		noc = scanf("%d", &ending_point);
		clear_keyboard_buffer();
	}
	//start printing using the format rules
	int i;
	int k = 1;
	for (i = starting_point; i <= ending_point; i++, k++)
	{
		printf("%5d", i);
		printf(":");
		printf("%-5d", get_collatz_number_of_steps(i));
		if (k % 7 == 0)//use k as a counter for when we need to print a new line
		{
			printf("\n");
		}
	}
	return 0;
}

int get_collatz_number_of_steps(int x)
{
	int steps_count = 0;
	while (x != 1)//collatz conjecture that x will eventually get down to 1
	{
		if (x % 2 == 0)		//if x is even, divide by 2
		{
			x = x / 2;
			steps_count++;
		}
		else
		{
			x = (3 * x) + 1;	//if x is odd, multiply by 3 then add 1
			steps_count++;
		}
	}

	return steps_count;
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
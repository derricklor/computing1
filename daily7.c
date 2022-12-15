/***********************************************
Author: Derrick Lor
Date: 9/19/18
Purpose: Write a function that takes in a positive
integer and outputs the corresponding binary number.
***********************************************/

# include <stdio.h>

void print_binary(int num);

int main(int argc, char* argv[])
{
	printf("42 in binary is: ");
	print_binary(42);
	
	printf("\n123456789 in binary is: ");
	print_binary(123456789);
	printf("\n");

	return 0;
}

void print_binary(int num)
{
	if (num > 0)	//must have situation to stop recursion
	{

		//Since printf prints left to right, we must print after the stop case is reached.
		//Go up the entire recursion stack until the stop case is reached,
		//then print 0 or 1 before each function ends.

		print_binary(num / 2);	//using the repeated division method

		if (num % 2 == 0)	//if there is no remainder, print 0
		{
			printf("0");
		}
		else
		{
			printf("1");	//else there is a remainder, print 1
		}
		
	}
}
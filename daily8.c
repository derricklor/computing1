/***********************************************
Author: Derrick Lor
Date: 9/24/18
Purpose: Prompts the user to input a positive 
integer and outputs the next number in the sequence.
If the number is even, then divide by 2. If the number is 
odd, multiply by 3 then add 1.
***********************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
	int x;
	printf("Please enter a positive integer: ");
	scanf("%d", &x);

	if (x % 2 == 0)		//if x is even, divide by 2
	{
		x = x / 2;
	}
	else
	{
		x = (3 * x) + 1;	//if x is odd, multiply by 3 then add 1
	}

	printf("The next value of the number is: %d", x);
	return 0;
}
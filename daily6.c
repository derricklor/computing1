/***********************************************
Author: Derrick Lor
Date: 9/17/18
Answer to question: The program will eventually use up all of the stacks it has
assigned and stack overflow. There is not enough space to assign the new function call
and will result in an error.
***********************************************/

#include <stdio.h>

void  recursive_down_to_zero(int n)
{
	if (n >= 0)
	{
		printf("%d\n", n);
		recursive_down_to_zero(n - 1);
	}
}

void  recursive_up_to_int(int n)
{
	if (n >= 0)
	{
		recursive_up_to_int(n - 1);
		printf("%d\n", n);
	}
}

int main(int argc, char* argv[])
{
	recursive_down_to_zero(10);
	printf("****\n");
	recursive_up_to_int(10);
	return 0;
}
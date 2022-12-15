/***********************************************
Author: Derrick Lor
Date: 9/26/18

Answer to question: 
What happens if the integer that you type is again big? Say 500000?
When you enter a big integer, like 500000, the program outputs the maximum amount of 
stacks from memory to target integer.It executes but the output is not what we wanted.

Why is this behavior different than what you saw with your daily7?
This behavior is different because we are doing all the work within one function call.
While with daily7, we continuously call another function to do some of the work.

***********************************************/
#include <stdio.h>

void loop_down_to_zero(int number);
void loop_up_to_int(int number);

int main(int argc, char* argv[])
{
	int x;
	printf("Please enter a positive integer: ");
	scanf("%d",&x);

	loop_down_to_zero(x);
	printf("****\n");
	loop_up_to_int(x);

	return 0;
}

void loop_down_to_zero(int number)
{
	while (number >= 0)
	{
		printf("%d\n",number);
		number--;
	}

}

void loop_up_to_int(int number)
{
	int i = 0;
	while (i <= number)
	{
		printf("%d\n", i);
		i++;
	}
}
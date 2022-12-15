/***********************************************
Author: Derrick Lor
Date: 7 December, 2018
Purpose: Asks user to enter a number, and then creates a dynamic
array of integers that has user input size of space allocated. 
Then randomly assigns a number into each space allocated. Finally
iterates through the dynamic array backwards and prints out the
index of where 42 is assigned in the dynamic array.

Sources of Help: Inclass lecture capture on malloc and srand. Class notes
 Time Spent: 59 mins
COMP1010 Day 18 F18 - Dr. Adams
on the assignment here>
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int num_of_ints, i, noc;
	int *p;

	srand(time(NULL));//randomize seed

	//get number from user
	printf("Enter a number between 10,000 and 1,000,000 :");
	noc = fscanf(stdin, "%d", &num_of_ints);
	clear_keyboard_buffer();
	while (noc != 1 || num_of_ints < 10000 || num_of_ints > 1000000)
	{
		printf("Enter a number between 10,000 and 1,000,000 :");
		noc = fscanf(stdin, "%d", &num_of_ints);
		clear_keyboard_buffer();
	}

	//allocated space in memory for all the numbers
	p = (int*)malloc(sizeof(int) * num_of_ints);

	//assign random int to the value in that address
	for (i = 0; i < num_of_ints; i++)
	{
		p[i] = rand();

		//check if malloc has failed
		if (p == NULL)
		{
			printf("Failed to allocate memory.\n");
			exit(1);
		}
	}
	
	//iterate backwards through the dynamic array
	for (i = num_of_ints-1; i >= 0; i--)
		//num_of_ints must be one less to avoid index out of bounds
	{
		if (p[i] == 42)
		{
			printf("%d\n", i);//print index of where 42 occured
		}
	}

	free(p); p = NULL;//free the spot or else memory leaks
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
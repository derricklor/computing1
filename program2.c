/***********************************************
Author: Derrick Lor
Date: 16 October, 2018
Purpose: Prints out the final population of green crud in the 
fibonacci sequence given a starting amount and a certain amount of days.
The green crud only grows on the 5th day, any days before that the
population of the  green crud remains the same.
Time Spent: 51mins
***********************************************/

#include <stdio.h>

int get_initial_size(void);
int get_number_of_days(void);
int get_final_population(int, int);
void clear_keyboard_buffer(void);
int continue_playing(void);

int main(int argc, char* argv[])
{
	int initial_size;
	int days;
	int final_population;
	
	do
	{
		initial_size = get_initial_size();
		days = get_number_of_days();
		final_population = get_final_population(initial_size, days);

		printf("With an initial population of %d pounds of crud growing for %d days.\n", initial_size, days);
		printf("The final population would be %d pounds.\n", final_population);

	} while (continue_playing());
	
	return 0;
}

int get_initial_size()
{
	int x;
	int noc;
	printf("Please enter the initial size of the green crud: ");
	noc = scanf("%d", &x);
	clear_keyboard_buffer();
	while (noc != 1 || x < 0)
	{
		printf("I'm sorry that value is unrecognized or is negative. \n");
		printf("Please enter the initial size of the green crud: ");
		noc = scanf("%d", &x);
		clear_keyboard_buffer();
	}
	return x;
}

int get_number_of_days()
{
	int x;
	int noc;
	printf("Please enter the number of days: ");
	noc = scanf("%d", &x);
	clear_keyboard_buffer();
	while (noc != 1 || x < 0)
	{
		printf("I'm sorry that value is unrecognized or is negative. \n");
		printf("Please enter the number of days: ");
		noc = scanf("%d", &x);
		clear_keyboard_buffer();
	}
	return x;
}

int get_final_population(int initial_size, int days)
{
	int i;
	int place_holder;
	//must have place holder or else next_size will be overidden
	//and current_size cannot be set to old next_size
	int current_size = initial_size;
	int next_size = initial_size;

	for (i = 0; i < days/5; i++)//crud only grows on the 5th day
	{
		place_holder = next_size;
		next_size = next_size + current_size;
		current_size = place_holder;
	}
	return (current_size);
}

void clear_keyboard_buffer()
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

int continue_playing()
{
	char answer; 
	//don't have to worry about number of conversions
	printf("Do you wish to continue(y/n)?: ");
	scanf(" %c", &answer);
	clear_keyboard_buffer();

	while (answer != 'Y' && answer != 'y' &&
		   answer != 'N' && answer != 'n')
	{
		printf("I'm sorry, I do not recognize that answer.\n");
		printf("Do you wish to continue(y/n)?: ");
		scanf(" %c", &answer);
		clear_keyboard_buffer();
	}

	switch (answer)
	{
	case 'y':
	case 'Y':
		return 1; break;
	case 'n':
	case 'N':
		return 0; break;
	}

}
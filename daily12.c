/***********************************************
Author: Derrick Lor
Date: 5 October, 2018
Purpose: Allows two players to play a game of Rock, Paper, Scissors.
Only allows specific choices to be inputed in order to progress the game.
The program will continuously ask to be replayed until the players end it.
Time Spent: 1hr 24mins
***********************************************/
#include <stdio.h>


enum choice { ROCK, PAPER, SCISSOR };//create an enumerated type. 
			//ROCK = 0, PAPER = 1, SCISSORS = 2
typedef enum choice Choice;//shorten the key words "enum choice" into "Choice"

int continue_playing(void);
void clear_keyboard_buffer(void);
Choice get_choice(void);

int main(int argc, char* argv[])
{
	
	Choice player1choice;
	Choice player2choice;
	
	do
	{
		printf("Player-1 it is your turn!\n");
		player1choice = get_choice();
		//printf("Player-1 chose: %d\n", player1choice);

		printf("Player-2 it is your turn!\n");
		player2choice = get_choice();
		//printf("Player-2 chose: %d\n", player2choice);

		if (player1choice == player2choice)//both chose same choice
		{
			printf("There is no winner.\n");
		}
		else
		{
			switch (player1choice)
			{
			case ROCK://player1 chose rock
				if (player2choice == SCISSOR)//player2 chose scissors
				{
					printf("Player 1 wins! Rock breaks scissors\n");
				}
				else
				{
					printf("Player 2 wins! Paper covers rock\n");
				}
				break;
			case PAPER://player1 chose paper
				if (player2choice == ROCK)//player2 chose rock
				{
					printf("Player 1 wins! Paper covers rock\n");
				}
				else
				{
					printf("Player 2 wins! Scissors cut paper\n");
				}
				break;
			case SCISSOR://player1 chose scissors
				if (player2choice == PAPER)//player2 chose paper
				{
					printf("Player 1 wins! Scissors cut paper\n");
				}
				else
				{
					printf("Player 2 wins! Rock breaks scissors\n");
				}
				break;
			}

		}
	} while (continue_playing());
	return 0;
}

Choice get_choice()
{
	char answer;
	//don't have to worry about number of conversions
	printf("Please enter your choice (r)ock, (p)aper, or (s)cissors: ");
	scanf(" %c", &answer);
	clear_keyboard_buffer();
	while ( answer != 'r' && answer != 'R' &&
			answer != 'p' && answer != 'P' &&
			answer != 's' && answer != 'S')
	{
		printf("I'm sorry, I do not recognize that answer.\n");
		printf("Please enter your choice (r)ock, (p)aper, or (s)cissors: ");
		scanf(" %c", &answer);
		clear_keyboard_buffer();
	}
	switch (answer)
	{
	case 'r':
	case 'R':
		return ROCK; break;
	case 'p':
	case 'P':
		return PAPER; break;
	case 's':
	case 'S':
		return SCISSOR; break;
	}
	
}

int continue_playing()
{
	char answer; 
	//don't have to worry about number of conversions
	printf("Do you wish to keep playing(y/n)?: ");
	scanf(" %c", &answer);
	clear_keyboard_buffer();

	while (answer != 'Y' && answer != 'y' &&
		   answer != 'N' && answer != 'n')
	{
		printf("I'm sorry, I do not recognize that answer.\n");
		printf("Do you wish to keep playing(y/n)?: ");
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

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}
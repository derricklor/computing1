/**
31 October, 2018
Chapter 6 Pointers and Modular Programming pg368
Write a program to dispense change. The user enters the amount paid and the amount due.
The program determines how many dollars, quarters, dimes, nickels, and pennies
should be given as change. Write a function with four output parameters
that determines the quantitiy of each kind of coin.
*/
#include <stdio.h>
#include <math.h>
void change(double coin_change, int *quarters, int *dimes, int *nickels, int *pennies);
int main(void)
{
	int c_dollars, c_quarters = 0, c_dimes = 0, c_nickels = 0, c_pennies = 0;
	double a_paid, a_due, m_change, coin_change;
	printf("Enter the amount paid> ");
	scanf("%lf", &a_paid);
	printf("Enter the amount due> ");
	scanf("%lf", &a_due);
	m_change = a_paid - a_due;
	c_dollars = floor(m_change);
	coin_change = (int)((m_change - floor(m_change)) * 100 + 0.5);
	// shows coin change (int)((m_change - floor(m_change)) * 100 + 0.5)
	//coin_change = coin_change * 100;
	printf("\n%f\n", coin_change);

	change(coin_change, &c_quarters, &c_dimes, &c_nickels, &c_pennies);
	printf("Change is dollars: %d$, quarters: %d, dimes: %d, nickels: %d,\
pennies: %d", c_dollars, c_quarters, c_dimes, c_nickels, c_pennies);
	return(0);
}
void change(double coin_change, int *quarters, int *dimes, int *nickels, int *pennies)
{
	int q = 1, d = 1, n = 1, p = 1;
	do {
		if (coin_change >= 25) {
			*quarters = *quarters + q;
			coin_change = coin_change - 25;
		}
		else if (coin_change >= 10) {
			*dimes = *dimes + d;
			coin_change = coin_change - 10;
		}
		else if (coin_change >= 5) {
			*nickels = *nickels + n;
			coin_change = coin_change - 5;
		}
		else if (coin_change >= 1) {
			*pennies = *pennies + p;
			coin_change = coin_change - 1;
		}
	} while (coin_change >= 1);
}
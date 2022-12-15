#include <stdio.h>
#include <stdlib.h>

void average(void);

int main(int argc, char* argv[])
{
	average();

	return 0;
}

void average()
{
	double average;
	int number = 0, noc;
	int sum = 0, size = 0;

	printf("enter a number(99999 to exit):");
	noc = fscanf(stdin,"%d", &number);
	while (number != 99999)
	{
		if (noc != 1)
		{
			printf("error occurred exiting now");
			exit(1);
		}
		sum += number;
		size++;
		printf("enter a number:");
		noc = fscanf(stdin, "%d", &number);
	}
	average = sum / (double)size;
	printf("average is : %d divided by %d which is %lf", sum, size, average);
}
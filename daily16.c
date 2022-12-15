/***********************************************
Author: Derrick Lor
Date: 12 October, 2018
Purpose: Reads two files and outputs the numbers in those
files in numerical order to another file.
Sources of Help: <Please list any sources that you used
 for help: tutors, web sites, lab assistants etc.>
 Time Spent: 5:40
***********************************************/
#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *fpnumbers1, *fpnumbers2, *fpoutput;
	char c, x;
	int noc1 = 1;
	int noc2 = 1;

	fpnumbers1 = fopen("numbers1.txt", "r");//read
	fpnumbers2 = fopen("numbers2.txt", "r");//read

	fopen("output.txt", "w");//create new file
	fpoutput = fopen("output.txt", "w");//write

	if (fpnumbers1 == NULL)
	{
		printf("Error failed to open file for input 1.");
		exit(1);
	}
	if (fpnumbers2 == NULL)
	{
		printf("Error failed to open file for input 2.");
		exit(1);
	}

	noc1 = fscanf(fpnumbers1, "%c", &c);//try
	noc2 = fscanf(fpnumbers2, "%c", &x);//try

	while (noc1 == 1 && noc2 == 1)//check
	{
		if (c == x)//if c,x have the same char
		{
			fprintf(fpoutput, "%c\n", c);//print out char c to the file
			noc1 = fscanf(fpnumbers1, "%c", &c);//scan the newline
			noc1 = fscanf(fpnumbers1, "%c", &c);//scan the next char

			fprintf(fpoutput, "%c", x);//print out char x to the file
			noc2 = fscanf(fpnumbers2, "%c", &x);//try
		}
		else if (c < x)//c is smaller
		{
			fprintf(fpoutput, "%c", c);//print out char c to the file
			noc1 = fscanf(fpnumbers1, "%c", &c);//try
		}
		else//x is smaller
		{
			fprintf(fpoutput, "%c", x);//print out char x to the file
			noc2 = fscanf(fpnumbers2, "%c", &x);//try
		}
	}
	/*print out the rest of the file that is larger
	if (noc1 == 0)
	{
		fprintf(fpoutput, "%c", c);//print out char c to the file
	}
	else if (noc2 == 0)
	{
		fprintf(fpoutput, "%c", x);//print out char x to the file
	}
	*/
	
	return 0;
}
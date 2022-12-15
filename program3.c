/*
Author: Derrick Lor
Course : CS 91.101, Computing I
Date : 26 November, 2018
Description : This file implements the
functionality required by
Program 3.

*/

#include <stdio.h>
#include <stdlib.h>//for exit
#include <ctype.h>//for read_string

void get_full_name(FILE *fpQuiz, FILE *fpOutput);
void get_scores(FILE *fpQuiz, FILE *fpOutput);
char* read_string(FILE* fp, char* buffer, int size);

int main(int argc, char* argv[])
{
	FILE *fpQuiz, *fpOutput;
	int noc = 0;
	int a, repeat = 0;
	char c;

	fpQuiz = fopen("quiz.txt", "r");
	fpOutput = fopen("average.txt", "w");//create new file

	if (fpQuiz == NULL)
	{
		printf("Failed to open quiz.txt file.");
		exit(1);
	}

	//find how many new lines there are in the input
	c = fgetc(fpQuiz);//try
	while (c != EOF)//check
	{
		if (c == '\n')//do
		{
			repeat++;
		}
		c = fgetc(fpQuiz);//try
	}

	//close and reopen file to reset character 
	//stream to the beginning
	fclose(fpQuiz);
	fpQuiz = fopen("quiz.txt", "r");

	for (a = 0; a < repeat+1; a++)//must repeat 1 extra time
		//to account for any extra new lines at end of file
	{
		get_full_name(fpQuiz, fpOutput);
		get_scores(fpQuiz, fpOutput);
	}

	//close all opened files
	fclose(fpQuiz);
	fclose(fpOutput);

	//prepare files for final step
	fpQuiz = fopen("quiz.txt", "w");//open input file for writing
	fpOutput = fopen("average.txt", "r");//open output file for reading

	//then copy paste output to input file
	noc = fscanf(fpOutput, "%c" , &c);//try
	while (noc == 1)//check
	{
		fprintf(fpQuiz, "%c", c);//do
		noc = fscanf(fpOutput, "%c", &c);//try	}
	}
	fclose(fpQuiz);
	fclose(fpOutput);
	
	return 0;
}

/*
Takes in two words, preferrably first name and last name in that specific order, and 
assigns them in different arrays. Then formats those arrays to be "last name, first name"
into array called full_name. Then prints it left justified 20 spaces.
PRECONDITION: Must begin at starting of a character, and not end of file
POSTCONDITION: Prints the name of the student last name, first name
@param fpQuiz  the input file
@param fpAverage the output file
*/
void get_full_name(FILE *fpQuiz, FILE *fpOutput)
{
	int i = 0, k = 0;
	char a;
	char first[21];//20 spaces for characters, plus 1 for null terminator
	char last[21];
	char full_name[41];
	int size = sizeof(first) / sizeof(char);//first and last have same size

	//check if next character is end of file
	a = fgetc(fpQuiz);
	if (a == EOF)
	{
		exit(0);//if so, then exit
	}
	ungetc(a, fpQuiz);//if not, unget character

	read_string(fpQuiz, first, size);//read first name
	read_string(fpQuiz, last, size);//read last name

	//in order to print both "last, first" names left justified 20 spaces
	//we must combine the names into one formatted string

	//copy characters from array last[] until null terminator 
	//into array full_name[]
	while (last[i] != '\0')
	{
		full_name[i] = last[i];//use i for indexing into array full_name[]
		i++;
	}

	//add the comma and space
	full_name[i] = ','; i++;
	full_name[i] = ' '; i++;
	
	//copy array first[] into array full_name[]
	while (first[k] != '\0')//use k for indexing into array first[]
	{
		full_name[i] = first[k];//i is still being incremented and has not been reset
		k++; i++;
	}
	//finally add the null terminator
	full_name[i] = '\0';

	//print left justified 20 spaces
	fprintf(fpOutput,"%-20s", full_name);
}

/*
Prints out the average of 10 given scores, even if less than
10 scores are supplied.
Each quiz score should be listed in a right justified column that is 4
characters wide, and the average should appear in its own right justified
column that is 10 characters wide.
PRECONDITION: The next data that is read must be of type int, and # of ints can be 10 or lower
POSTCONDITION: Prints the ints that is read, and the average of those scores divided by 10
@param fpQuiz  the input file
@param fpAverage the output file
*/
void get_scores(FILE *fpQuiz, FILE *fpOutput)
{
	int i, sum = 0, noc = 0 ;
	double average;
	
	noc = fscanf(fpQuiz, "%d", &i);

	//run only if we successfully get a conversion
	//and we haven't reached end of file
	while (noc != 0 && noc != EOF)
	{
		fprintf(fpOutput, "%4d ", i);
		sum += i;
		noc = fscanf(fpQuiz, "%d", &i);
	}
	
	average = (double)sum / 10.0;
	fprintf(fpOutput, "%10f\n", average);

}


/*
Takes in an input from FILE pointer fp, char array called buffer, and buffer's size (see NOTE).
Then reads (from fp) words or characters (separated by spaces) up to buffer's size, and 
stores them in array buffer.
Words that exceed buffer's size (character count is higher than buffer size) will be
shortened to match buffer's size.

NOTE: buffer's size already includes the null terminator. E.g. buffer size of 10
will only have enough size for 9 characters plus null terminator.
@PRECONDITION: must take in input file, buffer array, and size of buffer array
@POSTCONDITION: returns the buffer array with with whatever characters from input, without exceeding buffer size

@param fp  file pointer to source which we will read from
@param buffer  array that will store characters
@param size  size of buffer array
@return buffer  returns the buffer or NULL
*/
char* read_string(FILE* fp, char* buffer, int size)
{
	int c;
	c = getc(fp);
	int i = 0;

	//if c is not at end of file, and is a space, then skip it
	while (c != EOF && isspace(c))
	{
		c = getc(fp);
	}

	//if c is at end of file or size of array is 1 or less, then return
	if (c == EOF || size <= 1)
	{
		return NULL;
	}

	//assign first character, c, into array buffer
	buffer[i] = (char)c;
	i++;

	//begin looping
	c = getc(fp);//try
	//if c is not at end of file, and is not a space, and array still has space, then
	//assign c into buffer
	while (c != EOF && !isspace(c) && i < size - 1) //check
	{
		buffer[i] = c; //do
		i++;
		c = getc(fp);//try
	}

	//if everything ran correctly, and c has not reached end of file, then return c
	//back to file pointer
	if (c != EOF)
	{
		ungetc(c, fp);
	}

	//set last character in array buffer to be null terminator
	buffer[i] = '\0';
	return buffer;
}
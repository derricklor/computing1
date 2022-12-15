/***********************************************
Author: Derrick Lor
Date: 5 November, 2018
Purpose: Asks user if they want to convert lengths
or weights using 1 or 2 respectively. If they input
0 then terminate the program. Then ask if they want to convert
metric to us or us to metric depending on length or weight.
Allow user to input numbers and outputs the correct conversion.

Sources of Help: Inclass notes on pointers and dereference
				techonthenet.com for floor() function with math.h
 Time Spent: 6hr 20mins 
***********************************************/
#include <stdio.h>
#include <math.h>

void run_length_or_weights(int* pContinue_playing);

void convert_lengths(int* in_loop);
void length_to_metric(void);
void length_to_us(void);

void convert_weights(int* in_loop);
void weight_to_metric(void);
void weight_to_us(void);

void get_input_value(double* pValue);

void do_conversion_length_to_metric(double* pmeters, double* pcentimeters);
void do_conversion_length_to_us(double* pfeet, double* pinches);

void do_conversion_weight_to_metric(double* pkilograms, double* pgrams);
void do_conversion_weight_to_us(double* ppounds, double* pounces);

void print_results(double measure1, double measure2, int is_length, int is_metric);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int continue_playing = 1;

	//infinite loop until continue_playing is assigned 0
	while (continue_playing)
	{
		//the function below takes &continue_playing,
		//which is the address of continue_playing
		run_length_or_weights(&continue_playing);
	}
	return 0;
}

/**
Asks user to choose from lengths or weights or 0 to exit
@param pContinue_playing the pointer to the address of continue_playing
*/
void run_length_or_weights(int* pContinue_playing)
{
	int choice, noc;
	int in_loop = 1;//used to keep user looping inside length or weight conversion
	printf("Do you want to convert values that are lengths or weights?\n");
	printf("(0)Exit \n(1)lengths \n(2)weights\n");
	noc = scanf(" %d", &choice);
	clear_keyboard_buffer();
	while (noc != 1 || choice < 0 || choice > 2)
	{
		printf("Error!!\n");
		printf("Do you want to convert values that are lengths or weights?\n");
		printf("(0)Exit \n(1)lengths \n(2)weights\n");
		noc = scanf(" %d", &choice);
		clear_keyboard_buffer();
	}
	switch (choice)
	{
	case 0:
		//dereference the pointer so it changes to the location
		//in memory, then assign it a new value of 0
		*pContinue_playing = 0;
		printf("User chose to exit.\n");
		break;
	case 1:
		while (in_loop)
	{
		convert_lengths(&in_loop);
	}
		break;
	case 2:
		while (in_loop)
		{
			convert_weights(&in_loop);
		}
		break;
	}
}
/**
Puts user into a loop if they want to convert us to metric or metric to us,
then call appropriate functions, or return to exit the loop and this function.
*/
void convert_lengths(int* pin_loop)
{
	int choice;
	int noc;

	printf("(0) Exit\n");
	printf("(1) Convert lengths from feet / inches to meters / centimeters\n");
	printf("(2) Convert lengths from meters / centimeters to feet / inches\n");
	noc = scanf(" %d", &choice);
	clear_keyboard_buffer();

	while (noc != 1 || choice < 0 || choice > 2)
	{
		printf("Error!!\n");
		printf("(0) Exit\n");
		printf("(1) Convert lengths from feet / inches to meters / centimeters\n");
		printf("(2) Convert lengths from meters / centimeters to feet / inches\n");
		noc = scanf(" %d", &choice);
		clear_keyboard_buffer();
	}
	switch (choice)
	{
	case 0: printf("User chose to exit.\n");
		*pin_loop = 0;
		return;
		break;
	case 1: length_to_metric();
		break;
	case 2: length_to_us();
		break;
	}
}

/**
Puts user into a loop if they want to convert us to metric or metric to us,
then call appropriate functions, or return to exit the loop and this function.
*/
void convert_weights(int* pin_loop)
{
	int choice;
	int noc;

	printf("(0) Exit\n");
	printf("(1) Convert weights from pounds/ounces to kilograms/grams\n");
	printf("(2) Convert weights from  kilograms/grams to pounds/ounces\n");
	noc = scanf(" %d", &choice);
	clear_keyboard_buffer();

	while (noc != 1 || choice < 0 || choice > 2)
	{
		printf("Error!!\n");
		printf("(0) Exit\n");
		printf("(1) Convert weights from pounds/ounces to kilograms/grams\n");
		printf("(2) Convert weights from kilograms/grams to pounds/ounces\n");
		noc = scanf(" %d", &choice);
		clear_keyboard_buffer();
	}
	switch (choice)
	{
	case 0: printf("User chose to exit.\n");
		*pin_loop = 0;
		return;
		break;
	case 1: weight_to_metric();
		break;
	case 2: weight_to_us();
		break;
	}
}
/**
Calls appropriate functions to take one input value from user,
do the length conversion from us to metric, then output the results.
*/
void length_to_metric(void)
{
	double feet;//we will cast as integer later
	double inches;

	printf("User chose convert length to metric.\n");
	printf("Enter feet in whole numbers: ");
	get_input_value(&feet);
	printf("Enter inches in decimals: ");
	get_input_value(&inches);
	printf("User chose %d feet and %lf inches.\n", (int)feet, inches);

	do_conversion_length_to_metric(&feet, &inches);
	print_results(feet, inches, 1, 1); //feet will be meters and inches will be centimeters
}

/**
Calls appropriate functions to take one input value from user,
do the length conversion from metric to us, then output the results.
*/
void length_to_us(void)
{
	double meters;//we will cast as integer later
	double centimeters;

	printf("User chose convert length to us.\n");
	printf("Enter meters in whole numbers: ");
	get_input_value(&meters);
	printf("Enter centimeters in decimals: ");
	get_input_value(&centimeters);
	printf("User chose %d meters and %lf centimeters.\n", (int)meters, centimeters);

	do_conversion_length_to_us(&meters, &centimeters);
	print_results(meters, centimeters, 1, 0);//meters will be feet and centimeters will be inches
}

/**
Calls appropriate functions to take one input value from user,
do the weight conversion from us to metric, then output the results.
*/
void weight_to_metric(void)
{	
	double pounds;//we will cast as integer later
	double ounces;

	printf("User chose convert weight to metric.\n");
	printf("Enter pounds in whole numbers: ");
	get_input_value(&pounds);
	printf("Enter ounces in decimals: ");
	get_input_value(&ounces);
	printf("User chose %d pounds and %lf ounces.\n", (int)pounds, ounces);

	
	do_conversion_weight_to_metric(&pounds, &ounces);
	print_results(pounds, ounces, 0, 1);//pounds will be kilograms and ounces will be grams
}

/**
Calls appropriate functions to take one input value from user,
do the weight conversion from metric to us, then output the results.
*/
void weight_to_us(void)
{	
	double kilograms;//we will cast as integer later
	double grams;

	printf("Enter kilograms in whole numbers: ");
	get_input_value(&kilograms);
	printf("Enter grams in decimals: ");
	get_input_value(&grams);
	printf("User chose %d kilograms and %lf grams.\n", (int)kilograms, grams);

	do_conversion_weight_to_us(&kilograms, &grams);
	print_results(kilograms, grams, 0, 0);//kilograms will be pounds and grams will be ounces
}


/**
Allows the user to input whole numbers and decimals, the assigns a 
double of whatever was inputted to the value in the location of pValue
PRECONDITION: The parameter given must be a pointer to a double
POSTCONDITION: Changes the value in the location of the pointer to whatever was inputted
			   to be a double
*/
void get_input_value(double* pValue)
{
	double val;
	int noc;
	noc = scanf(" %lf", &val);
	clear_keyboard_buffer();

	while (noc != 1)
	{
		printf("Error! Must enter a valid number. Try again: ");
		noc = scanf(" %lf", &val);
		clear_keyboard_buffer();
	}
	*pValue = val;
}

void do_conversion_length_to_metric(double* pmeters, double* pcentimeters)
{
	double difference = 0;
	//feet to meters
	*pmeters = ((int)*pmeters) * 0.3048;

	//convert inches to feet, then to meters, then to cm
	*pcentimeters = (*pcentimeters /12.0) * 0.3048 * 100;

	//Since the conversion is not perfect, we will need to take the extra
	//decimals in the larger unit and convert it to the smaller unit
	
	//find difference between pmeter and next lowest whole number
	difference = *pmeters - floor(*pmeters);

	//truncate the decimals of the bigger unit
	*pmeters = *pmeters - difference;

	//add the difference to smaller unit, dont forget to convert
	*pcentimeters = *pcentimeters + difference*100;

	//while centimeters can be converted to meters, then add 1 to meters
	//and subtract 100 from centimeters
	while (*pcentimeters >= 100)
	{
		*pcentimeters = *pcentimeters - 100.0;
		*pmeters = *pmeters + 1;
	}
	
}

void do_conversion_length_to_us(double* pfeet, double* pinches)
{
	double difference = 0;
	//meters to feet
	*pfeet = ((int)*pfeet) / 0.3048;

	//centimeter to meter to feet to inch
	*pinches = (*pinches * 12.0) / (100.0 * 0.3048);

	//Since the conversion is not perfect, we will need to take the extra
	//decimals in the larger unit and convert it to the smaller unit

	//find difference between pfeet and next lowest whole number
	difference = *pfeet - floor(*pfeet);//difference is measured in feet

	//truncate the decimals of the bigger unit
	*pfeet = *pfeet - difference;

	//add the difference to smaller unit, dont forget to convert
	*pinches = *pinches + (difference*12.0);

	while (*pinches >= 12)
	{
		*pinches = *pinches - 12;
		*pfeet = *pfeet + 1;
	}
}

void do_conversion_weight_to_metric(double* pkilograms, double* pgrams)
{
	double difference = 0;
	//pounds to kilograms 
	*pkilograms = ((int)*pkilograms) / 2.2046;

	//convert ounces to pounds, then to kilograms, then to grams
	*pgrams = ((*pgrams / 16.0) / 2.2046) * 1000;

	//Since the conversion is not perfect, we will need to take the extra
	//decimals in the larger unit and convert it to the smaller unit

	//find difference between pkilograms and next lowest whole number
	difference = *pkilograms - floor(*pkilograms);//difference measured in kilograms

	//truncate the decimals of the bigger unit
	*pkilograms = *pkilograms - difference;

	//add the difference to smaller unit, dont forget to convert
	*pgrams = *pgrams + (difference*1000);//convert difference to grams

	//while grams can be converted to kilograms, then add 1 to kilograms
	//and subtract 1000 from grams
	while (*pgrams >= 1000)
	{
		*pgrams = *pgrams - 1000.0;
		*pkilograms = *pkilograms + 1;
	}
}

void do_conversion_weight_to_us(double* ppounds, double* pounces)
{
	double difference = 0;
	//kilograms to pounds
	*ppounds = ((int)*ppounds) * 2.2046;

	//convert grams to kilograms to pounds to ounces
	*pounces = (*pounces / 1000.0) * 2.2046 * 16.0 ;

	//Since the conversion is not perfect, we will need to take the extra
	//decimals in the larger unit and convert it to the smaller unit

	//find difference between ppounds and next lowest whole number
	difference = *ppounds - floor(*ppounds);//difference measured in pounds

	//truncate the decimals of the bigger unit
	*ppounds = *ppounds - difference;

	//add the difference to smaller unit, dont forget to convert
	*pounces = *pounces + (difference * 16);//convert difference to ounces

	//while ounces can be converted to pounds, then add 1 to pounds
	//and subtract 16 from ounces
	while (*pounces >= 16)
	{
		*pounces = *pounces - 16.0;
		*ppounds = *ppounds + 1;
	}
}

/**
Prints out the length or weight in either us or metric.
*/
void print_results(double measure1, double measure2, int is_length, int is_metric)
{
	//if is_length true, then print the length version
	if (is_length)
	{
		if (is_metric)//if is_metric is true, then print the metric version
		{
			printf("Converts to: %d meters and %lf centimeters\n", (int)measure1, measure2);
		}
		else//else print the us version
		{
			printf("Converts to: %d feet and %lf inches\n", (int)measure1, measure2);
		}
	}
	else//else print the weight version
	{
		if (is_metric)
		{
			printf("Converts to: %d kilograms and %lf grams\n", (int)measure1, measure2);
		}
		else//else print the us version
		{
			printf("Converts to: %d pounds and %lf ounces\n", (int)measure1, measure2);
		}
	}
	printf("\n");
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

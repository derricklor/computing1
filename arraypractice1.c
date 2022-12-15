#include <stdio.h>

int main(int argc, char* argv[])
{
	/* sum of an array
	int i, sum = 0;
	int arr[] = {1,2,3,4};
	int size = sizeof(arr) / sizeof(int);

	for (i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	printf("sum of arr is : %d", sum);
	*/

	/* average of array
	int i;
	double average = 0;
	int arr[] = { 1,2,3,4 };
	int size = sizeof(arr) / sizeof(int);

	for (i = 0; i < size; i++)
	{
		average += arr[i];
	}
	average = average/size;//double division
	printf("average of arr is : %10.2f ", average);
	*/

	/*smallest number of array
	int i;
	int arr[] = { 1,2,3,4,0,7,4,1,4,-8,-34,-90 };
	int size = sizeof(arr) / sizeof(int);
	int smallest = arr[0];

	for (i = 0; i < size-1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			smallest = arr[i + 1];
		}
	}
	printf("smallest number of arr is : %d ", smallest);
	*/

	/* biggest number of array
	int i;
	int arr[] = { 1,2,3,4,0 };
	int size = sizeof(arr) / sizeof(int);
	int biggest;

	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			biggest = arr[i + 1];
		}
	}
	printf("biggest number of arr is : %d ", biggest);
	*/

	/* index of smallest number of array
	int i, indexOfSmallest=0;
	int arr[] = { 1,2,3,4,0,7,4,1,4,-8,-34,-90 };
	int size = sizeof(arr) / sizeof(int);

	for (i = 0; i < size ; i++)
	{
		if (arr[indexOfSmallest] > arr[i])
		{
			indexOfSmallest = i;
		}
	}
	printf("index of smallest number of arr is : %d ", indexOfSmallest);
	*/

	/*index of biggest number of array
	int i, indexOfBiggest = 0;
	int arr[] = { 1,2,3,4,0 };
	int size = sizeof(arr) / sizeof(int);

	for (i = 0; i < size; i++)
	{
		if (arr[indexOfBiggest] < arr[i])
		{
			indexOfBiggest = i;
		}
	}
	printf("index of biggest number of arr is : %d ", indexOfBiggest);
	*/

	/* index of negative numbers of array
	int i, indexOfNegative;
	int arr[] = { 1,2,3,4,0,7,4,1,4,8,34,90 };
	int size = sizeof(arr) / sizeof(int);

	printf("index of negative number of arr is : ");
	for (i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			indexOfNegative = i;
			printf("%d ", indexOfNegative);
		}
		else
		{
			indexOfNegative = NULL;

		}

	}
	if (indexOfNegative == NULL)
	{
		printf("NULL");
	}
	*/
	return 0;
}
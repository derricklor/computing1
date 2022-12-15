#include <stdio.h>

int find_max(int* p, int size);

int main(int argc, char* argv[])
{
	int i, k;
	int number;
	int* p;
	printf("enter number of spaces to allocate:");
	fscanf(stdin, "%d", &number);

	p = (int*)malloc(sizeof(int)*number);

	for (i = 0; i < number; i++)
	{
		p[i] = rand();
		printf("%d\n", p[i]);
	}

	k = find_max(p, number);
	printf("largest number index is %d\n", k);
	k = p[k];
	printf("largest number is %d", k);

	free(p);
	return 0;
}

int find_max(int* p, int size)
{
	int j;
	int largest_index ;
	largest_index = 0;
	for (j = 0; j < size - 1; j++)
	{
		if (p[largest_index] < p[j + 1])
		{
			largest_index = j+1;
		}
	}
	return largest_index;
}
#include <stdio.h>
#include <stdlib.h>
/*
char* reverse(char* word);
int compare_string(char* pleft_string, char* pright_string);

struct my_string
{
	int size;
};

typedef struct my_string My_string;
*/









struct node
{
	int value;
	int priority_level;
};
typedef struct node Node;

struct priority_queue
{
	int size;
	int capacity;
	Node heap[50];
};
typedef struct priority_queue Priority_queue;


int main(int argc, char* argv[])
{
	Priority_queue test;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
	/*
	My_string array[100];
	My_string* node = &array[0];

	node->size = 1;
	printf("%d\n", node->size);

	node = &array[1];
	node->size = 2;
	printf("%d\n", node->size);

	node = &array[2];
	node->size = 3;
	printf("%d\n", node->size);

	printf("%d\n", array[0]);



	///char word[] = "i";
	//printf("%s\n", word);
	//printf("%s\n", reverse(word));
	//printf("%s\n", word);
	//printf("%s\n", reverse(word));
	//return 0;
	
	/*
	char left_string[] = "hi";
	char right_string[] = "hir";
	//printf("%d\n",compare_string(left_string, right_string));
	*/
	
}



/*
char* reverse(char* pword)
{
	int i;
	int size = 0;
	char temp;

	////check if empty
	if (pword[0] == NULL)
	{
		return pword;
	}

	//find size
	for (i = 0; pword[i] != '\0'; i++)
	{
		size++;
	}
	size--;
	//size must decrease by 1 or will result in array out of bounds
	for (i = 0; i < size / 2; i++)//works with even or odd sizes
	{
		temp = pword[i];
		pword[i] = pword[size - i];
		pword[size - i] = temp;
	}
	return pword;
}

int compare_string(char* pleft_string, char* pright_string)
{
	char c, d;
	int i = 0;

	c = pleft_string[i];
	d = pright_string[i];
	
	while (c == d)
	{
		if (c == '\0' && d == '\0')
		{
			return 0;
		}
		
		i++;
		c = pleft_string[i];
		d = pright_string[i];
	}
	if (c == '\0')
	{
		return -1;//if left is lexicographically smaller return -1
	}
	if (d == '\0')
	{
		return 1;//if left is lexicographically bigger return 1
	}
	if (c < d) //a=97 z=122 A=65 Z=90
	{
		return 1;//if left is lexicographically bigger return 1
	}
	if (c > d)
	{
		return -1;//if left is lexicographically smaller return -1
	}
}*/

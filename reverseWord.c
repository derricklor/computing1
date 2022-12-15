#include <stdio.h>

char* reverse(char* word);

int main(int argc, char* argv[])
{
	char word[] = "Happy Birthday!";
	printf("%s\n", word);
	printf("%s\n", reverse(word));

	return 0;
}

char* reverse(char* pword)
{
	int i;
	int size = 0;
	char temp;

	for (i = 0; pword[i] != '\0'; i++)
	{
		size++;
	}
	size--;
	printf("%d\n", size);
	for (i = 0; i < (size)/2 ; i++)
	{
		temp = pword[i];
		pword[i] = pword[size - i];
		pword[size - i] = temp;
	}
	return pword;
}
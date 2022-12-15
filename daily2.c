/*Author: Derrick Lor
  Date: 9/9/18

  Output: The program outputs the name of the program and where 
  the program is located inside of the computer, which is 
  C:\Users\Derrick_Lor\source\repos\daily2\Debug\daily2.exe
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("This program has the executable name : %s\n", argv[0]);
	printf("That is all!\n");
	return 0;
}
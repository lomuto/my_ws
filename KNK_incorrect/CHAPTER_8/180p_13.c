/*
Modify Programming Project 11 from Chapter 7 so that the program labels its
output:

```
Enter a first and last name: Lloyd Fosdick
You entered the name: Fosdick, L.
```

The program will need to store the last name (but not the first name) in an
array of characters until it can be printed. You may assume that the last name
is no more than 20 characters long.
*/

#include <stdio.h>
#define MAX_NAME 20
int main(void)
{
	char name[MAX_NAME] = {0,};                                           // 0 == '\0' == NULL. 문자형 배열도 0으로 초기화됨.

	for (int i = 0; (name[i] = getchar()) != '\n'; i++)		     // 여기서 name배열 끝에 '\n' 저장되고 비교하는거라 '\n'가 배열 안에있음
		;
	char last_name[MAX_NAME];
	int temp;
	for (int i = 0; i < sizeof(name) / sizeof(char); i++)
	{
		if (name[i] == ' ')
		{
			temp = i + 1;
		}
	}
	for (int i = temp, j = 0; i < sizeof(name) / sizeof(char); i++, j++)
	{
		last_name[j] = name[i];
	}
	for (int i = 0; last_name[i] != '\n'; i++)                            // lastname 받아올 때 개행문자까지 포함해서 받아줬으므로  != '\n' 으로 해야함
	{                                                                     // 위에서 개행문자 빼고 저장해주던가 했어야했음
		printf("%c", last_name[i]);
	}
	printf(", %c", name[0]);
}

#include <stdio.h>
#include <stdlib.h>
#define STR_SIZE 5

int main() {
	char str[STR_SIZE+1] = "Hello";		//good habit to define string size as preprocessor and add 1 to STR_SIZE
	char* ptr = str;

	*ptr = 'A';	// ptr points to array, so it's legal to access elements in string 

	printf("%s", str);	//Aello\0
	}


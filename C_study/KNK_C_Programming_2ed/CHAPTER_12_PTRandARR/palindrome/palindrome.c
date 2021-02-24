#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100

int ARRAY[SIZE] = { 0, };
int* ptr = &ARRAY[0] - 1;

void push(int);

int main() {
	int ch;
	for (ch = getchar(); ch != '\n'; ch = getchar()) {
		if(isalpha(ch)) push(tolower(ch));
	}

	int middle = (ptr-&ARRAY[0])/2;
	int n = 0;

	for (; ptr > &ARRAY[middle];) {
		if (ARRAY[n++] == *ptr--);
		else {
			printf("Not a palindrome\n");
			exit(EXIT_SUCCESS);
		}
	}
	printf("Palindrome\n");
}

void push(int n) {
	if (ptr < &ARRAY[SIZE - 1]) *++ptr = n;
	else {
		printf("overflow\n");
		exit(EXIT_SUCCESS);
	}
}

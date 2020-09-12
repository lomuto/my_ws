#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int STACK[SIZE] = { 0, };	// make sure not to use char type when adding an integer to pointer 
int* ptr = STACK-1;
void push(int);
int pop();

int main() {
	char ch;
	
	printf("Enter a Message: ");
	for (ch = getchar(); ch != '\n'; ch = getchar()) {
		push(ch);
	}

	printf("Reverseal is: ");
	for (; ptr >= & STACK[0];) printf("%c", pop());

	printf("\n");
}

void push(int n) {
	if (ptr < &STACK[SIZE-1]) *++ptr = n;
	else {
		printf("overflow\n");
		exit(EXIT_SUCCESS);
	}
}

int pop() {
	if (ptr >= & STACK[0]) return *ptr--;
	else {
		printf("underflow\n");
		exit(EXIT_SUCCESS);
	}
}

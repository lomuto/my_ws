#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

int STACK[STACK_SIZE] = { 0, };
int ptr = -1;
void push(int);
int pop();

int main() {
	int num,n;
	printf("Enter num: ");
	scanf("%d", &num);

	while (1) {
		push(num % 2);
		if (num < 2) break;
		num /= 2;
	}
	while ((n = pop()) != 2) {
		printf("%d", n);
	}
	printf("\n");

	return 0;
}

void push(int n) {
	if (ptr < STACK_SIZE - 1) {
		STACK[++ptr] = n;
	}
	else {
		printf("STACK OVERFLOW\n");
		exit(EXIT_SUCCESS);
	}
}

int pop() {
	if (ptr > -1) {
		return STACK[ptr--];
	}
	else {
		return 2;
	}
}

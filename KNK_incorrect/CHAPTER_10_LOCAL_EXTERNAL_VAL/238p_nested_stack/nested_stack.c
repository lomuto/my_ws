#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

int STACK[STACK_SIZE];
int ptr = -1;

void push(char n) {
	if (ptr < 99) {
		ptr++;
		STACK[ptr] = n;
	}
	else {
		printf("stack overflow\n");
		exit(EXIT_SUCCESS);

	}
}

void pop(){
	if (ptr > -1) {
		STACK[ptr] = 0;
		ptr--;
	}
	else printf("stack underflow\n");
}

int main() {
	char n;
	while ((n = getchar()) != '\n') {
		if (n == ')' || n == '}' || n == ']') {
			switch (n) {
			case ')':
				if (STACK[ptr] == '(') pop();
				else {
					printf("unmatched\n");
					return 0;
				}
				break;
			case '}':
				if (STACK[ptr] == '{') pop();
				else {
					printf("unmatched\n");
					return 0;
				}
				break;
			case ']':
				if (STACK[ptr] == '[') pop();
				else {
					printf("unmatched\n");
					return 0;
				}
				break;
			}
		}
		else push(n);
	}
	if (ptr == -1) {
		printf("matched!\n");
		return 0;
	}
	else printf("unmathced!\n");
	
}
	

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

int STACK[STACK_SIZE];
int ptr = -1;
char temp = 0;

void push(char n) {
	if (ptr < STACK_SIZE-1) {
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
	char ch;
	while (1) { 
		printf("Enter RPN expression: ");
		for (scanf(" %c", &ch); ch != '='; scanf(" %c", &ch)) {
			if (ch == 'q')exit(EXIT_SUCCESS);
			temp = 0;
			if (ch - '0' < 0 || ch - '0' > 9) {
				switch (ch) {
				case '+':
					temp = (STACK[ptr - 1] - '0') + (STACK[ptr] - '0');
					pop();
					pop();
					push(temp + '0');
					break;
				case '-':
					temp = (STACK[ptr - 1] - '0') - (STACK[ptr] - '0');
					pop();
					pop();
					push(temp + '0');
					break;
				case '*':
					temp = (STACK[ptr - 1] - '0') * (STACK[ptr] - '0');
					pop();
					pop();
					push(temp + '0');
					break;
				case '/':
					temp = (STACK[ptr - 1] - '0') / (STACK[ptr] - '0');
					pop();
					pop();
					push(temp + '0');
					break;
				}
			}
			else push(ch);
		}
		if (STACK[ptr] > '0') {
			printf("Value is: %c\n", STACK[ptr]);
		}
		else printf("Value is: %d\n", STACK[ptr]-'0');

			for ( int i = ptr; i > -1; i--) {
				STACK[i] = 0;
			}
			ptr = -1;
	}
}
	

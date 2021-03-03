#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define STACK_SIZE 101
#define MAX_EXP 101
typedef void* STACK_t;

STACK_t STACK[STACK_SIZE];
STACK_t* ptr = STACK - 1;

bool is_empty() {
	return ptr == STACK - 1 ? true : false;
}

bool is_full() {
	return ptr == STACK + STACK_SIZE - 1 ? true : false;
}

void push(STACK_t n) {
	if (is_full()) {
		printf("STACK OVERFLOW\n");
		exit(EXIT_FAILURE);
	}
	else
		*(++ptr) = n;
}

STACK_t pop() {
	if (is_empty()) {
		printf("STACK UNDERFLOW\n");
		exit(EXIT_FAILURE);
	}
	else
		return *ptr--;
}

void clear_STACK() {
	for (;!is_empty();)
		*ptr-- = NULL;
}

STACK_t peek() {
	return *ptr;
}

bool operator_precedence(char a, char b) {
	switch (a) {
	case '*':
		a = 2;
		break;
	case '/':
		a = 2;
		break;
	case '+':
		a = 1;
		break;
	case '-':
		a = 1;
		break;
	}
	switch (b) {
	case '*':
		b = 2;
		break;
	case '/':
		b = 2;
		break;
	case '+':
		b = 1;
		break;
	case '-':
		b = 1;
		break;
	}
	if (a - b >= 0) return true;
	else return false;
}

void parentheses_check(const char* EXP) {
	for (; *EXP != '\0'; EXP++) {
		if (*EXP == '(')
			push((void*)EXP);
		else if (*EXP == ')')
			pop();
	}

	if (!is_empty()) {
		printf("EXPRESSION'S PARENTHESES ARE ASYMMETRICAL\n");
		exit(EXIT_FAILURE);
	}
}

char* to_POSTFIX(char* EXP, int EXP_LEN) {
	char temp[MAX_EXP];
	strcpy(temp, EXP);
	int i = 0;

	for (int k = 0; k < EXP_LEN; k++) {
		if (isdigit(*(temp + k)))
			*(EXP + i++) = *(temp + k);
		else {
			if (is_empty())	
				push((void*)(temp + k));
			else {
				if (*(temp + k) == '(')
					push((void*)(temp + k));
				else if (*(temp + k) == ')') {
					for (; *(char*)peek() != '(';)
						*(EXP + i++) = *(char*)pop();
					pop();
				}
				else if (*(char*)peek() != '(') {
					if (operator_precedence(*(char*)peek(), *(temp + k))) {
						for (; peek() && *(char*)peek() != '(' && !is_empty() && operator_precedence(*(char*)peek(), *(temp + k));) {
							/*if peek() return NULL than *(char*)peek() try to reference NULL adress and occur error
							add peek() for first of && operator, it would break loop instantly*/
							*(EXP + i++) = *(char*)pop();
						}
						push((void*)(temp + k));
					}
					else
						push((void*)(temp + k));
				}
				else
					push((void*)(temp + k));
			}
		}
	}
	for (;!is_empty();)
		*(EXP + i++) = *(char*)pop();

	*(EXP + i) = '\0';

	return EXP;
}
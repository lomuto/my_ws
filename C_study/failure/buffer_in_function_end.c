#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STACK_SIZE 50
char STACK[STACK_SIZE] = { 0, };
char* ptr = STACK - 1;
void push(char);
char pop();
int read_line();
int main() { 
	char T;
	for (char temp; (temp = getchar()) != '\n';) T = temp;
	for (int i = 0; i < T-'0'; i++) {
		int temp = read_line();
		if (temp)printf("YES\n");
		else printf("NO\n");
	}
}
void push(char n) {
	if (ptr > STACK + STACK_SIZE - 1) return;
	else *++ptr = n;
	return;
}
char pop() {
	if (ptr < STACK) return 0;
	else return *ptr--;
}
int read_line() {
	ptr = STACK - 1;
	char ch=0;
	for (; (ch = getchar()) != '\n';) {
		if (ch == '(') {
			push(ch);
		}
		else if (ch == ')') {
			if (pop() != '(') return 0;	
/* if function ends in here, remain buffer will effect getchar() at execption of ending loop
you must clear the buffer before ends function or set error checking variable and add at final ending execption*/
		}
	}
	if (pop()) return 0;
	else return 1;
}

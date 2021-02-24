#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>		// isdigit()
#include <stdlib.h>
#define SEGEMENT_SIZE 7
#define STACK_SIZE 30

bool segments[10][SEGEMENT_SIZE] = {
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1} };
char digit[SEGEMENT_SIZE] = { '_','|','|','_','|','|','_' };

char STACK[STACK_SIZE] = { 0, };
int STACK_ptr = -1;

char display_digit(char,int);
void push(char);

/*/////////////////////////////////////////////////////////////////////////////////////////
printf(" %c\n",display_digit(num,0));
	printf("%c%c%c\n", display_digit(num, 5), display_digit(num, 6), display_digit(num, 1));
	printf("%c%c%c\n", display_digit(num, 4), display_digit(num, 3), display_digit(num, 2));
*/
void top_digit();
void middle_digit();
void bottom_digit();
/////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	char n;
	printf("Enter a number: ");
	for(scanf("%c",&n);n != '\n'; scanf("%c", &n)){
		push(n);
	}

	top_digit();
	middle_digit();
	bottom_digit();
}

char display_digit(char num,int n) {
	if (segments[num-'0'][n]) {
		return digit[n];
	}
	else {
		switch (n) {
		case 1: case 2: case 4: case 5:
			return ' ';
		default:
			return '  ';
		}
	}
}

void push(char n) {
	if (STACK_ptr > STACK_SIZE-2) {
		printf("STACK OVERFLOW\n");
		exit(EXIT_SUCCESS);
	}
	else if (isdigit(n)) {
		STACK_ptr++;
		STACK[STACK_ptr] = n;
	}
}

void top_digit() {
	for (int i = 0; i < STACK_ptr+1; i++) {
		printf(" %c ", display_digit(STACK[i], 0));
		printf("  ");
	}
	printf("\n");
}

void middle_digit() {
	for (int i = 0; i < STACK_ptr + 1; i++) {
		printf("%c%c%c", display_digit(STACK[i], 5), display_digit(STACK[i], 6), display_digit(STACK[i], 1));
		printf("  ");
	}
	printf("\n");
}

void bottom_digit() {
	for (int i = 0; i < STACK_ptr + 1; i++) {
		printf("%c%c%c", display_digit(STACK[i], 4), display_digit(STACK[i], 3), display_digit(STACK[i], 2));
		printf("  ");
	}
	printf("\n");
}
	

#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 7

bool segments[10][STACK_SIZE] = {
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
char digit[STACK_SIZE] = { '_','|','|','_','|','|','_' };

char display_digit(int,int);

int main() {
	
	int num;
	printf("Enter number: ");
	scanf("%d", &num);

	printf(" %c\n",display_digit(num,0));
	printf("%c%c%c\n", display_digit(num, 5), display_digit(num, 6), display_digit(num, 1));
	printf("%c%c%c\n", display_digit(num, 4), display_digit(num, 3), display_digit(num, 2));
}

char display_digit(int num,int n) {
	if (segments[num][n]) {
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
	

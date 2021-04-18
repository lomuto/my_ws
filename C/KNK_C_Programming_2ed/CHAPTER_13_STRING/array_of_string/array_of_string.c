#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_NUM 4
#define MAX_STR 6

int main() {
	char str[MAX_NUM][MAX_STR];

	for (int i = 0; i < MAX_NUM; i++) {
		scanf("%s", *(str+i));
	}

	for (int i = 0; i < MAX_NUM; i++) {
		printf("%d is %s\n",i+1, *(str + i));
	}
}



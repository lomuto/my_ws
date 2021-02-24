#include <stdio.h>
#include <string.h>

int main() {
	char* str1 = "I am hungry";
	char str2[] = "I am hungry";

	if (str1 == str2) printf("We are hungry\n");

	char* str3 = "waffle";

	if (str3 == "waffle")printf("waffle!\n");

	if (!strcmp(str1, str2))printf("We are hungry!");
	}


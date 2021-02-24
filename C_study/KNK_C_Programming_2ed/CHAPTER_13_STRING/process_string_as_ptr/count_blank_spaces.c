#include <stdio.h>

int count_space(char* str) {
	int temp=0;
	for (int i = 0; *(str + i) != '\0'; i++) {
		if(*(str+i) == ' ') temp++;
	}

	return temp;
}

int count_space_onlyPTR(const char* str) {		// handing over parameter str as const, it prevents variable `str` to be modified
	int temp=0;
	for (; *str != '\0'; str++) if(*str == ' ') temp++;
	return temp;
}

int main() {
	char str[] = "빈 칸 빈 칸 희 희";

	printf("%d\n", count_space(str));
	printf("%d\n", count_space_onlyPTR(str));
	}

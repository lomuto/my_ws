#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STR_SIZE 10

char* strCpy(char*, const char*);
int strLen(const char*);
char* strCat(char*, const char*);
int strCmp(const char*, const char*);

int main() {
	char str[STR_SIZE];

	strCpy(str, "abce");
	printf("str is %s and length is %d\n", str, strLen(str));

	strCat(str, "fgh");
	printf("str is now %s and length is %d\n", str, strLen(str));

	printf("%d", strCmp("abv", "abvd"));
}

char* strCpy(char* str1, const char* str2) {
	for (int i = 0; *(str1 + i) = *str2; i++, str2++);	// string copy ends when *str2 is NULL.

	return str1;
}

int strLen(const char* str) {
	int size=0;
	
	for (; *str; str++) size++;		// won't count NULL

	return size;
}

char* strCat(char* str1, const char* str2) {
	int end = strLen(str1);

	/*
	int* end = str1;
	for(;*end;end++);
	*/

	for (int i = 0; *(str1 + end + i) = *str2; i++, str2++);
	// In pointer arthmertic, i treats as one block of memory even though i is an INTEGER(4bytes) while str is CHARACTER(1byte)

	return str1;
}

int strCmp(const char* str1, const char* str2) {

	for (;; str1++, str2++) { 
		if (*str1 > * str2) return 1;
		else if (*str1 < *str2) return -1;
		else if (*str1 == NULL && *str2 == NULL) break;
	}

	return 0;
}

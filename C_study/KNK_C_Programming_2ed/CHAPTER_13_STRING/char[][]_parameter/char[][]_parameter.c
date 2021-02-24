#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 50

int str_check(const char strs[][LEN + 1], const char*, int);
void SWAP(char*, char*);
void SORT(char str[][LEN + 1],int);

int main() {
	int N,count=0;
	scanf("%d", &N);

	char temp[LEN], words[19999][LEN + 1];

	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		if (str_check(words, temp, count)) {
			strcpy(*(words + count), temp);
			count++;
		}
	}

	SORT(words,count);

	for (int i = 0; i < count; i++) {
		printf("%s\n", *(words + i));
	}
}

int str_check(const char strs[][LEN+1],const char* str, int n) {
	for (int i = 0; i < n; i++) {
		if (!strcmp(str, *(strs+i))) return 0;
	}
	return 1;
}

void SWAP(char* str1, char* str2) {
	char temp[LEN];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

void SORT(char str[][LEN+1], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (strlen(*(str + i)) < strlen(*(str + j))) {
				SWAP(*(str + i), *(str + j));
			}
			else if (strlen(*(str + i)) == strlen(*(str + j))) {
				if (strcmp(*(str + i),*(str + j))<0)SWAP(*(str + i), *(str + j));
			}
		}
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

//divide
void mergeSort(int*, int, int);

//conquer
void merge(int*, int, int, int);

int main() {
	int N;
	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * MAX);

	for (int i = 0,temp; i < N; i++) {
		scanf("%d", &temp);
		*(arr + i) = temp;
	}
	
	mergeSort(arr, 0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d\n", *(arr + i));

	return 0;
}

void mergeSort(int* arr, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;

		mergeSort(arr, left, middle);
		mergeSort(arr, middle+1 , right);

		merge(arr, left, middle, right);
	}
	else
		return;
}

void merge(int* arr, int left, int middle, int right) {
	int* A_copy = (int*)malloc(sizeof(int*) * (middle-left+1));   //필요한 만큼의 길이만 malloc
	for (int i = left; i <= right; i++) {
		*(A_copy + i-left) = *(A + i);                              // copy 시 인덱스 맞춰야함
	}

	int count = left,i,j;                                         // count 는 원배열의 인덱스, i와j라는 복사된 배열에 맞는 인덱스 변수 사용
	
	for (i = 0, j = middle-left+1; i <= middle-left && j <= right-left;) {
		if (*(A_copy + i) < *(A_copy + j))
			*(A + count++) = *(A_copy + i++);
		else if(*(A_copy + i) > *(A_copy + j))
			*(A + count++) = *(A_copy + j++);
	}

	for (; i <= middle-left || j <= right-left;) {
		if(i<=middle)
			*(A + count++) = *(A_copy + i++);
		else if (j <= right)
			*(A + count++) = *(A_copy + j++);
	}
	free(A_copy);

}

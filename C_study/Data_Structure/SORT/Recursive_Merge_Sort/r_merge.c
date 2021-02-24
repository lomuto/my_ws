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
	int count = left,i,j;
	int brr[MAX];		//메모리낭비 심함... 숫자맞출라고 필요한거 이상으로 메모리 할당
	for (i = left; i <= right; i++) {
		*(brr + i) = *(arr + i);
	}
	for (i = left, j = middle + 1; i <= middle && j <= right;) {	// 두개의 조각 중 하나 다 비워질때까지 모배열 arr에 넣음
		if (*(brr + i) < *(brr + j))
			*(arr + count++) = *(brr + i++);
		else
			*(arr + count++) = *(brr + j++);
	}

	for (; i <= middle || j <= right;) {	// 남은거 다 넣어줌. split된 배열들은 재귀적 증명으로 모두 sort되어있으니까, 넣기만 하면 됨
		if (i <= middle)
			*(arr + count++) = *(brr + i++);
		else if(j <= right)
			*(arr + count++) = *(brr + j++);
	}

}

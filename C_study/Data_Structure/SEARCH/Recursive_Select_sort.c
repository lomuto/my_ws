#include <stdio.h>
#define SWAP(x,y) x = x^y, y = x^y, x = x^y

int Rselect_sort(int*, int);

int main() {
	int arr[] = { 1,7,3,89,39,5,8,11,6,28,78,32,2,235,23 };
	int size = sizeof(arr) / sizeof(arr[0]);

	Rselect_sort(arr, size);

	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}

int Rselect_sort(int* arr, int n) {
	if (n < 1) return 0;

	for (int i = 1; i < n; i++) {
		if (*arr > * (arr + i)) SWAP(*arr, *(arr + i));
	}
	return Rselect_sort(arr + 1, n - 1);
}

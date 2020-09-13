#include <stdio.h>
#define SWAP(x,y) {int temp; temp=x; x=y; y = temp;}
int quick_sort(int*, int);

int main() {
	int arr[] = { 1,7,3,89,39,5,8,11,6,28,78,32,2,235,23 };
	int size = sizeof(arr) / sizeof(arr[0]);

	quick_sort(arr, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int quick_sort(int* arr, int n) {

	int* left, *right;
	left = arr;
	right = arr + n - 1;

	if (left >= right) return 0;

	int pivot = *arr;

	while(left <= right) {
		while (pivot >= *left) left++;
		while (pivot <= *right && right > arr) right--;
		if (left > right) { SWAP(*right, pivot); }
		else { SWAP(*left, *right); }
	}
	
	quick_sort(arr, arr+n - right-1);
	quick_sort(right+1, arr + n - right - 1);
}

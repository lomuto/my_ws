#include <stdio.h>

int* R_bsearch(int*, int, int);

int main() {
    int arr[] = { 2,7,9,13,19,35,45,67,88,101,234,423,621,910 };    // array must be SORTED
    int n = sizeof(arr) / sizeof(arr[0]);
    int* ans = R_bsearch(arr, n, 88);

    ans == -1 ? printf("Failure\n") : printf("target's index is %d\n", ans-arr);
}
int* R_bsearch(int* arr, int n, int key) {
    if (n < 1) {
        return -1;
    }

    int middle = (n - 1) / 2;         // divide n-1 by 2 instead of n. It helps to understand operation of index easily

    if (key == *(arr + middle)) return arr + middle;        // While middle's position is relative, in order to return key's index, return adress of absolute position 
    else if (key > * (arr + middle)) return R_bsearch(arr + middle + 1, n-middle-1 /*make sure size is not just 'middle'*/, key);       //Use array as Starting point of adress to split array. Adress of `arr+middle+1` would be half point of array
    else return R_bsearch(arr, middle, key);
}

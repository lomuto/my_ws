#pragma once
#include <stdlib.h>
#include <string.h>

void MergeSort(int a[], int n) {
    if (n <= 1)
        return;

    int *a_copy = (int *)malloc(n * sizeof(int));
    memcpy(a_copy, a, n * sizeof(int));

    int middle = n / 2;
    MergeSort(a_copy, middle);
    MergeSort(a_copy + middle, n - middle);

    int left = 0;
    int right = middle;

    int pivot = 0;
    while (left < middle && right < n) {
        a[pivot] = a_copy[left] < a_copy[right] ? a_copy[left++] : a_copy[right++];
        pivot++;
    }
    while (left < middle) {
        a[pivot] = a_copy[left++];
        pivot++;
    }
    while (right < n) {
        a[pivot] = a_copy[right++];
        pivot++;
    }

    free(a_copy);
}
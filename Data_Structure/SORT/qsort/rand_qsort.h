void SWAP(int *x, int *y) {
    if (*x != *y) {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

void Rand_Q_sort(int *arr, int st, int end) {
    if (st >= end)
        return;
    int idx = rand() % (end - st + 1) + st;
    printf("IDX: %d\n", idx);
    int target = arr[idx];
    int left = st;
    int right = end;

    SWAP(arr + idx, arr + st);

    while (left < right) {
        while (target < arr[right])
            right--;
        while (left < right && target >= arr[left])
            left++;
        SWAP(arr + left, arr + right);
    }

    SWAP(arr + st, arr + left);
    Rand_Q_sort(arr, st, left - 1);
    Rand_Q_sort(arr, left + 1, end);
}
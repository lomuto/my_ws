/*
배열 arr에 대해
int* p = arr;
라고 p를 초기화하면 *p == arr[0]
저 개념을 끌고와서

2차원 배열 arr[2][3] 에 대해
int* p = arr 하고
*p + n (== arr[n/2][n%2]) 해서 2차원 배열에 접근

당장은 잘 안와닿으니까 일단 써놓자,,
*/

int sum_two_dimensional_array(const int a[][LEN], int n) {

    const int *p = *a;
    int sum = 0;

    while (p < *a + n * LEN)
        sum += *p++;
    return sum;
}

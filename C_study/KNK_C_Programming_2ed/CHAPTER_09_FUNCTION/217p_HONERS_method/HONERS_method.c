#include <stdio.h>
int n = 0;

int f(int);

int main() {
    int x;
    printf("Enter x:");
    scanf_s("%d", &x);

    printf("Output is %d\n", f(x));
}

int f(int x) {
    int constant[] = { 0,-6,7,-1,-5 };
    if (n == 4) return 3 * x + 2;
    n += 1;
    return f(x) * x + constant[n];
}

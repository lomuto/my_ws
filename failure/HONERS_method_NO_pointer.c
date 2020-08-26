/*
얘는 왜 오류날까..
*/

#include <stdio.h>
int n = 0;

int f(int);

int main() {
    int x;
    printf("Enter x:");
    scanf("%d", &x);

    printf("Output is %d\n", f(x));
}

int f(int x) {
    int constant[] = { -6,7,-1,-5 };
      if (n == 4) return 3 * x + 2;
    return f(x) * x + constant[n++];
}

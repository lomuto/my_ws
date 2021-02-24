/*
개 좆같은 포인터...
포인터 어떤 개념 헷갈리는지 정확히 하기
*/


#include <stdio.h>
int* n; 
int k= 0;	// 우선 하나 해결. 전역변수에서 포인터 이렇게 선언 못함. 자세하게 왜인지는 모름
n = &k;

int f(int, int*);

int main() {
    int x;
    printf("Enter x:");
    scanf("%d", &x);

    printf("Output is %d\n", f(x,&n));
}

int f(int x, int* n) {
    int constant[] = { -6,7,-1,-5 };
      if (*n == 4) return 3 * x + 2;
    return f(x,&n) * x + constant[(*n)++];
}

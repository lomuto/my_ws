/*
MAX함수는 틀린 함수이다.
내가 이 코드를 작성하면서 몰랐던건 함수 scope 안에서 변수가 어떻게 생성되는지
생성된 변수가 어떻게 작동하는지 몰랐다

지금 작성한 MAX함수가 반환하는것은 정확히 무엇인지 설명할 수 있어야함
*/

#include <stdio.h>

int* MAX(int*, int*);

int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	int* ans = MAX(&a,&b);
	printf("%d\n", *ans);
}

int* MAX(int* a, int* b) {
	return *a > *b ? &a : &b;
}

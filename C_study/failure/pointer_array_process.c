/*
for문에서 인스턴스 포인터 변수를 선언해 메모리를 아끼려고했음

for문에서 어디가 틀렸을까요?

인스턴스 변수 p가 뭔지, p[4] 가 뭘 의미하는지 헷갈렸었음
*/




#include <stdio.h>

int main() {
	int sum = 0;
	int arr[] = { 3,6,3,1 };

	for (int* p = arr; p < &p[4]; p++) {
		sum += *p;
	}
	printf("%d", sum);

	int* p = arr;
	printf("%d\n", *p);
	p++;
	printf("%d\n", *p);
}

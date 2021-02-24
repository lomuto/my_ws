/*
주석친대로 함수 수정하면 변수형 포인터 p가 가리키는 주소에 할당된 값이 328이 됨
근데
p = &i 하게되면 할당 안댐

왜그럴까?
C언어는 기본적으로 call by Reference 가 아닌 Call by Value 임을 명시하며.,.
*/

#include <stdio.h>

void f(int* p) {
	int i = 328;
	p = &i;		//*p = i;
	return;
}

int main() {
	int a = 1;
	int* p = &a;
	f(p);

	printf("%d\n", *p);
}


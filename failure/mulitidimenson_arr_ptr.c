/*
각각 어떤걸 출력하는지 생각해보고
2차원 배열 arr에 대해서
arr은 arr[0][0] 의 주소가 아니라 arr[0] 의 주소를 가르킨다는거ㅓ..명심
*/

#include <stdio.h>

int main() {
	int arr[2][3] = { 1,2,3,4,5,6 };
	int* p = arr;
	printf("%d\n", arr[1][2]);
	printf("%d\n", p[0]);
	printf("%x\n", &arr[1][2]);
	printf("%x\n", &p[2]);
	printf("%x\n", (&arr[1][2])-(&p[2]));
}

/*
Project 6.11

The value of the mathematical constant e can be expressed as an infinite series:

e = 1 + 1/1! + 1/2! + 1/3! + ...

Write a program that approximates e by computing the value of

1 + 1/1! + 1/2! + 1/3! + ... + 1/n!

where n is an integer entered by the user.
*/

#include <stdio.h>

int main(void)
{
	int n;
	float sum = 1, sum_n = 1;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		sum += 1 / (sum_n *= i);
	}
	/*
	 두개의 식을 하나의 for문에 묶는법 참고해서 코드 작성.
	 반복문은 for문으로 최소한의 공간 차지하게 묶는연습...
	 */

	printf("%f\n", sum);
}


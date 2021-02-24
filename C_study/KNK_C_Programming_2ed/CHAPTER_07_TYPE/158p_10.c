/* 
Project 7.6
Write a program that counts the number of vowels (a, e, i, o and u) in a
sentence:

```
Enter a sentence: And that's the way it is.
Your sentence contains 6 vowels.
```
*/


#include <stdio.h>

int main(void)
{
	int count = 0;
	char a;

	// a = getchar() != '\n' 하게 되면 연산자 우선순위에 의해서 [대입연산자 < 비교연산자] 이므로
	// 개행 문자가 입력되지 않으면 getchar()!='\n' ==> 1을 반환한다. 최종적으로 a에 1을 할당 (a = 1)
	// (a = getchar()) != '\n' 이렇게 앞에 먼저 계산되게 묶어줘야지 원하는대로 실행 됨
	while (a = getchar() != '\n')
	{
		// 대문자를 처리하는 간단한 코드는?
		if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		{
			count++;
		}
	}
	printf("Your sentence contains %d vowls", count);
}

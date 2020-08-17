/*
### Project 7.13
Write a program that calculates the average word length for a sentence:

```
Enter a sentence: It was deja vu all over again.
Average word length: 3.4
```

For simplicity, your program should consider a punctuation mark to be part of
the word to which it is attached. Display the average word length to one decimal
place.
*/


#include <stdio.h>

int main(void)
{
	char c;
	float sum = 0, count = 0;		//단어를 카운트 하는 count 간과하고 알고리즘 짬. 다시 생각
	while ((c = getchar()) != '\n')
	{
		sum++;
		if (c == ' ')
		{
			count++;
			sum--;
		}
	}
	printf("%.1f", sum / count);
}

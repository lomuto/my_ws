/*
The prototypical Internet newbie is a fellow named BIFF, who has a unique way of
writing messages. Here's a typical BIFF communiqué:

```
H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
```

Write a "BIFF filter" that reads a message entered by the user and translates it
into BIFF-speak:

```
Enter message: Hey dude, C is rilly cool
In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
```

Your program should convert the message to upper-case letters, substitute digits
for certain letters (A→4, B→8, E→3, I→1, O→0, S→5), and then append 10 or so
exclamation marks. *Hint*: Store the original message in an array of characters,
then go back through the array, translating and printing characters one by one.
*/

#include <stdio.h>
#include <ctype.h>                                          // 대문자 변환 함수 toupper ctype.h 헤더에 존재
#define MAX 100                                             // 배열 크기 define으로 안전하게!

int main(void)
{
	char c, words[MAX] = {0,};                                // ASCII 에서 0은 NULL. 문자형 배열 NULL로 초기화

	for (int i = 0; (c = getchar()) != '\n'; i++){
		words[i] = toupper(c);                                  // 대문자로 배열에다가 저장해줌.
	}

	for (int i = 0; i<MAX; i++){                      // for (int i = 0; words[i] != NULL; i++) 
		switch (words[i]){			  // 위에처럼 해도 가능.
		case 'A':
			words[i] = '4';
			break;
		case 'B':
			words[i] = '8';
			break;
		case 'E':
			words[i] = '3';
			break;
		case 'I':
			words[i] = '1';
			break;
		case 'O':
			words[i] = '0';
			break;
		case 'S':
			words[i] = '5';
			break;
		}
    
    printf("%c", words[i]);
	}
	printf("!!!!!!!!!!\n");
	return 0;
}

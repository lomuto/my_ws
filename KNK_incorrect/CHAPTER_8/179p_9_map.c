/*
Write a program that generates a "random walk" across a 10 x 10 array. The array
will contain characters (all `'.'` initially). The program must randomly "walk"
from element to element, always going up, down, left or right by one element.
The elements visited by the program will be labeled with the letters `A` through
`Z`, in the order visited. Here's an example of the desired output:

```
A . . . . . . . . .
B C D . . . . . . .
. F E . . . . . . .
H G . . . . . . . .
I . . . . . . . . .
J . . . . . . . Z .
K . . R S T U V Y .
L M P Q . . . W X .
. N O . . . . . . .
. . . . . . . . . .
```

*Hint* Use the `srand` and `rand` functions (see `deal.c`) to generate random
numbers. After generating a number, look at its remainder when divided by 4.
There are four possible values for the remainder -- 0, 1, 2 and 3 -- indiciating
the direction of the next move. Before performing a move, check that (a) it
won't go outside the array, and (b) it doesn't take us to an element that
already has a letter assigned. If either condition is violated, try moving in
another direction. If all four directions are blocked, thr program must
terminate. Here's an example of premature termination:

```
A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
```

`Y` is blocked on all four sides, so there's no place to put `Z`.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_OF_MAP 10

int main(void)
{
	srand((unsigned)time(NULL));
	char MAP[SIZE_OF_MAP][SIZE_OF_MAP] = {
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
	};

	int i = 0, j = 0;
	char MARK = 'A';
	MAP[0][0] = MARK;

	while (MAP[i][j] != 'Z')
	{
		if (MAP[i + 1][j] != '.' && MAP[i][j + 1] != '.' && MAP[i - 1][j] != '.' && MAP[i][j - 1] != '.')   // 사방이 막힌 데드락인 경우 탈출
		{
			printf("\n**DEAD LOCK**\n\n");
			break;
		}
		int direction = rand() % 4;

		switch (direction)                                                                                  // 랜덤함수 통해 갈 방향 정해줌
		{
		case 0:
			if (i < 9 && MAP[i + 1][j] == '.')                                  // 가고자 하는 좌표가 '.' 이여야지만 갈 수 있게 조건 설정
				i++;                                                              // 이 조건을 설정하지 않으면 길이 이어지지 않고 띄엄띄엄 생길수도 있음
			break;
		case 1:
			if (j < 9 && MAP[i][j + 1] == '.')
				j++;
			break;
		case 2:
			if (i > 0 && MAP[i - 1][j] == '.')
				i--;
			break;
		case 3:
			if (j > 0 && MAP[i][j - 1] == '.')
				j--;
			break;
		}

		if (MAP[i][j] == '.')
		{
			MAP[i][j] = ++MARK;
		}
	}

	for (int i = 0; i < SIZE_OF_MAP; i++)
	{
		for (int j = 0; j < SIZE_OF_MAP; j++)
		{
			printf(" %c ", MAP[i][j]);
		}
		printf("\n");
	}
}

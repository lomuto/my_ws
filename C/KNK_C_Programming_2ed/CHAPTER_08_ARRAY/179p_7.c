/*
Write a program that reads a 5 x 5 array of integers and then prints the row
sums and the column sums:

```
Enter row 1: 8 3 9 0 10
Enter row 2: 3 5 17 1 1
Enter row 3: 2 8 6 23 1
Enter row 4: 15 7 3 2 9
Enter row 5: 6 14 2 6 0

Row totals: 30 27 40 36 28
Column totals: 34 37 37 32 21
```
*/

#include <stdio.h>

int main(void)
{
	int num[5][5] = {
		0,
	};

	for (int i = 0; i < 5; i++)
	{
		printf("Enter row %d: ", i + 1);
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &num[i][j]);                                // scanf에서 바로 넘겨줄 수 있음
		}
	}

	for (int j = 0; j < 5; j++)
	{
		int colsum = 0;
		for (int i = 0; i < 5; i++)
		{
			colsum += num[i][j];
		}
		printf("%d ", colsum);                                    // 행 = ROW = 가로.  행거는 가로~
	}
	printf("\n");
	for (int j = 0; j < 5; j++)
	{
		int rowsum = 0;                                           // 열 = COLUMN = 세로. 열쇠는 세로~
		for (int i = 0; i < 5; i++)
		{
			rowsum += num[j][i];
		}
		printf("%d ", rowsum);
	}
	printf("\n");
	return 0;
}

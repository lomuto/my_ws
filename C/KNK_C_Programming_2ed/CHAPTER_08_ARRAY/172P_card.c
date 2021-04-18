#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	int n;
	printf("Enter number of cards in hand: ");
	scanf("%d", &n);
	int count = n;

	printf("Your hand: ");

	for (int i = 0; i < n; i++)
	{

		srand((unsigned)time(NULL));              // 이렇게 srand가 안에있으면 반복문이 도는 시간이 너무 짧아 time함수의 값의 변동이 없어
		int hand_num = rand() % 12 + 2;           // rand함수에 계속 같은값이 들어가게됨.
                                              // srand 사용 시 반복문 쓰이면 rand는 반복문 안에 두어 계속 호출되며 값이 변하게 하되
		int hand_shape = rand() % 3;              // srand함수는 반복문 밖에다 쓰기... 그리고 unsigned int로 형변환 꼭 해주어야함
		if (i == n - 1)
		{
			printf("as ");
		}
		char temp_num;
		char temp_shape;

		if (hand_num > 10)
		{
			switch (hand_num)
			{
			case 11:
				temp_num = 'a';
				break;
			case 12:
				temp_num = 'k';
				break;
			case 13:
				temp_num = 'q';
				break;
			case 14:
				temp_num = 'j';
				break;
			}
			printf("%c", hand_num);
		}
		printf("%d", hand_num);

		switch (hand_shape)
		{
		case 0:
			temp_shape = 'c';
			break;
		case 1:
			temp_shape = 'd';
			break;
		case 2:
			temp_shape = 'h';
			break;
		case 3:
			temp_shape = 's';
			break;
		}
		printf("%c ", temp_shape);
	}
	printf("\n");

	return 0;
}

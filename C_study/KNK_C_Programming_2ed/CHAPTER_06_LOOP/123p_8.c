/*
Project 6.08

Write a program that prints a one-month calendar. The user specifies the number of days in the month and the day of the week on which the month begins:

Enter number of days in month: 31
Enter starting day of the week (1=Sun, 7=Sat): 3

       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31

Hint: This program isn't as hard as it looks. The most important part is a for statement that uses a variable i to count from 1 to n, where n is the number of days in the month, printing each value of i. Inside the loop, an if statement tests whether i is the last day in a week; if so, it prints a new-line character.
*/

#include <stdio.h>

int main(void)
{
	int days, start_day, cal_day = 1;
	printf("Enter number of days in month: ");
	scanf("%d", &days);
	printf("Enter starting day of the week: ");
	scanf("%d", &start_day);

	int week = start_day;
	while (days != cal_day)
	{
		for (; start_day > 1; start_day--)
		{
			printf(" ");
		}

		for (; week <= 7; week++, cal_day++)
		{
			printf("%d",cal_day);
		}
		/*
			조건을 확인해주는 while문이 밖에있어서
			for문에서 7일 단위로 반복문을 끊으면 중간에 while문의 종료조건이 되어도 알지 못함.
			고로 for문 안에도 while문과 같은 조건의 break조건 추가해줌

			for (; week <= 7; week++, cal_day++)
		{
			printf("%3d",cal_day);
			if(cal_day==31){
				break;
		*/
		printf("\n");
		week = 1;
	}
}

/*
for (i = 1, day = 1; i <= n + weekday - 1; i++) {
        if (i < weekday)
            printf("   ");
        else
            printf("%3d", day++);
        if (i % 7 == 0)
            printf("\n");

더 좋은 알고리즘의 예시

두번의 for문을 한번에 묶어서 처리해주고
일주일 단위로 끊는 계산은 7로 나눴을 때의 나머지로 처리
*/


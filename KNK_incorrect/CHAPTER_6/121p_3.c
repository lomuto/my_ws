#include <stdio.h>

int main(){

    int i,j;
    
    for(i = 5, j = i - 1; i > 0, j > 0; --i, j= i - 1)
	printf("%d", i);

    /*
	for문의 expr에 변수가 여러개 들어갈 수 있다는거도 환기하기 위함이지만
	이 문제의 오답을 적은건 for문의 동작 순서를 제대로 하기 위함이다.
	
	for(식1, 조건, 식2) statement; 가 있을 때 실행 순서는
	식1 -> 조건검사 -> statement -> 조건검사 -> 식2 -> statement 가 아니라
	식1 -> 조건검사 -> statement -> 식2 -> 조건검사 -> statement 이렇게.
	최초 1회 조건 확인 후에 문장 실행 후, 식2 실행 하고 조건검사를 한다
	헷갈리지 않게 주의하자.
    */

    return 0;
}

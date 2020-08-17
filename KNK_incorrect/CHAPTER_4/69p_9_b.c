#include <stdio.h>

int main(){
  
  int i, j, k;
  
  i = j = k = 1;    // '=' 연산자는 우항결합적. k에 1이 할당된 후  j에 1, i에 1 이 할당되는 순서로 진행  
  
  i += j += k;      // 복합연산자 +=도 우항결합적. j = j + k 먼저 실행되어 j에 2 할당. 이어서 i = i + 2 실행되고 i에 3 할당
  
  printf("%d %d %d", i, j, k);    // 순서대로 3 2 1
  
  return 0;
}

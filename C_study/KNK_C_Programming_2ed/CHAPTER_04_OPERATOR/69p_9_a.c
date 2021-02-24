#include <stdio.h>

int main(){
  
  int i = 7, j = 8;
  
  i *= j + 1;
  
  /*
    연산자 우선순위에 의해 사칙연산인 +가 먼저 실행.    i *= 9
    i = i*9 이므로 i = 63
  */
  
  printf("%d, %d", i,j);    // 순서대로 63, 8 출력
  
  return 0;
}

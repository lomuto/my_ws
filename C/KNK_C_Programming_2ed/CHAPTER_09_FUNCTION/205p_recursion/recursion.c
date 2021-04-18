#include <stdio.h>

int power(int, int);

int main(){
	int x,n;
	printf("Enter x,n: ");
	scanf("%d,%d",&x,&n);
	printf("x power n is: %d\n",power(x,n));

	return 0;
}

/*int power(int x, int n){
	if(n == 1){
	return x;
	}

	return x * power(x,n-1); 
}*/

/******************************************************
* Simplyfy return statement by using Ternary Operator *
******************************************************/

int power(int x, int n){
	return n == 1 ? x : x*power(x,n-1);
}

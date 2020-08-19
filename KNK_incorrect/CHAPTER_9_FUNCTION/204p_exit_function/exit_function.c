#include <stdio.h>
#include <stdlib.h>

int exit_function();

int main(){
	exit_function();
	printf("If you see this, exit_function didn't work\n");
}

int exit_function(){
	int a;
	printf("type a: ");
	scanf("%d",&a);
	
	if(a != 0){
	exit(EXIT_FAILURE);	
	}
}

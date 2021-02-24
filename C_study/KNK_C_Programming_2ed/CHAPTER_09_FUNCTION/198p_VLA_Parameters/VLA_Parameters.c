#include <stdio.h>

int length_of_array(int,int*);

int main(){
	int arr[] = {1,2,3,4,5};
	printf("length of arr is %d\n",length_of_array(6,arr));
}

int length_of_array(int n, int array[n]){
	printf("Last index of array: %d\n",array[n-1]);
	return n;
}

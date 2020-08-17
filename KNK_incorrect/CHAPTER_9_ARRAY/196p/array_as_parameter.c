#include <stdio.h>

int sizeof_array_as_parameter(int*);

int main(){
	int arr[] = {1,2,3,4,5};
	printf("size of arr is %d byte\n",(int)(sizeof(arr)/sizeof(int))); // sizeof(arr)/sieeof(arr[0])
	printf("size of arr as parameter is %d byte \n",sizeof_array_as_parameter(arr));
}

int sizeof_array_as_parameter(int* arr){
	return (int)(sizeof(arr)/sizeof(int));
}

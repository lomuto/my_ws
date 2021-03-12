#include <stdio.h>

int function(int a){
    return a;
}

int main(){
    void* func_ptr = function;
    printf("%d\n",(*(int (*)(int))func_ptr)(3));
    //printf("%d\n",function(3));
}
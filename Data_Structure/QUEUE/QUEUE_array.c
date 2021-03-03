/*Understanding QUEUE before implementing it by using Linked list*/

#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

int QUEUE[QUEUE_SIZE];
int front,rear;

void __init__(){
    front = -1;
    rear = -1;
}

int is_empty(){
    if(front==rear)
        return 1;
    else
        return 0;
}

int is_full(){
    if((rear+1)%QUEUE_SIZE == front)    // if popq() never exectued befor QUEUE gets full,
        return 1;                       // front will stay in -1 and is_full() cant handle whether QUEUE is full or not
    else
        return 0;
}

void pushq(int n){
    if(!is_full())
        *(QUEUE+(++rear%QUEUE_SIZE)) = n;   // index of QUEUE is "rear%QUEUE_SIZE" so that it can rotate
    else{
        printf("QUEUE is FULL\n");
        return;
    }
}

int popq(){
    if(!is_empty())
        return *(QUEUE+(front++%QUEUE_SIZE));   // index of QUEUE is "front%QUEUE_SIZE" so that it can rotate
    else{
        printf("QUEUE is Empty\n");
        return;
    }
}

int peek(){
    return QUEUE[rear];
}

int main(){
    __init__();

    for(int i=0; i<10; i++){
        pushq(i+1);
        for(int k=0; k<QUEUE_SIZE; k++){
            printf("%d ",QUEUE[k]);
        }
        printf("\n");
    }

    for(int i=0; i<10; i++){
        popq(i);
        for(int k=0; k<QUEUE_SIZE; k++){
            printf("%d ",QUEUE[k]);
        }
        printf("\n");
    }
}

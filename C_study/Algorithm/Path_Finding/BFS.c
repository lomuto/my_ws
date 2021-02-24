#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAZE_SIZE 10
#define QUEUE_SIZE 100

int MAZE[MAZE_SIZE][MAZE_SIZE] = {
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
   { 2, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
   { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
   { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
   { 1, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
   { 1, 1, 0, 1, 1, 1, 0, 0, 0, 1 },
   { 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
   { 1, 1, 0, 1, 1, 1, 0, 0, 0, 1 },
   { 1, 1, 0, 1, 1, 1, 0, 1, 0, 3 },
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};


typedef struct _COORDINATE{
    int x;
    int y;
}COR;

typedef struct _queue{
    COR location[QUEUE_SIZE];
    int rear;
    int front;
}QUEUE;

void VISIT(COR cor){        // VISIT must be declared before its reference
    MAZE[cor.y][cor.x] = 7;
}

void __init__(QUEUE* queue){
    queue->front = -1;
    queue->rear = -1;
}

int is_empty(QUEUE* queue){
    if((queue->front)%QUEUE_SIZE==(queue->rear)%QUEUE_SIZE)
        return 1;
    else
        return 0;
}

int is_full(QUEUE* queue){
    if((queue->rear+1)%QUEUE_SIZE == (queue->front)%QUEUE_SIZE)
        return 1;
    else
        return 0;
}

void pushq(QUEUE* queue,COR loc){
    if(!is_full(queue)){
        VISIT(loc);
        queue->rear++;                                          // as Coordinate is x and y so it calls two times
        queue->location[(queue->rear)%QUEUE_SIZE].x = loc.x;    // if location[++(queue->rear)] for two time casues wrong coordinate to push
        queue->location[(queue->rear)%QUEUE_SIZE].y = loc.y;    // queue->rear++; for once at begining
    }
    else{
        printf("QUEUE is FULL\n");
    }
}

COR popq(QUEUE* queue){
    if(!is_empty(queue))
        return queue->location[++(queue->front)/*%QUEUE_SIZE*/];
    else{
        printf("QUEUE is Empty\n");
    }
}

int main(){

    QUEUE queue;
    __init__(&queue);

    COR current;

    for(int i=0,exit_outer_loop=0; i<MAZE_SIZE; i++){          // 미로 시작지점 탐색
        for(int j=0; j<MAZE_SIZE; j++){
            if(MAZE[i][j]==2){
                current.x = j;
                current.y = i;
                //pushq(&queue,current);
                exit_outer_loop++;
            }
        }
        if(exit_outer_loop)
            break;
    }
    
    /*********************** print************************/
    system("cls");
    printf("Starts at [%d,%d]\n",current.x,current.y);
    Sleep(1200);
    system("cls");
    //

    for(COR temp;MAZE[current.y][current.x+1] != 3 && MAZE[current.y+1][current.x] != 3 && MAZE[current.y][current.x-1] != 3 && MAZE[current.y-1][current.x] != 3;){
        if(!MAZE[current.y][current.x+1]){
            temp.x = current.x+1;
            temp.y = current.y;
            pushq(&queue,temp);
            printf("right ");
        }
        if(!MAZE[current.y+1][current.x]){
            temp.x = current.x;
            temp.y = current.y+1;
            pushq(&queue,temp);
            printf("down ");
        }
        if(!MAZE[current.y-1][current.x]){
            temp.x = current.x;
            temp.y = current.y-1;
            pushq(&queue,temp);
            printf("up ");
        }
        if(!MAZE[current.y][current.x-1]){
            temp.x = current.x-1;
            temp.y = current.y;
            pushq(&queue,temp);
            printf("left ");
        }
        
        current = popq(&queue);
        
        
        printf("\n");
        for(int i=0; i<MAZE_SIZE; i++){
            for(int j=0; j<MAZE_SIZE; j++){
                printf("%d ",MAZE[i][j]);
            }
            printf("\n");
        }
        Sleep(3000);
        system("cls");
    }

    /*********************** print************************/
    printf("\n");
        for(int i=0; i<MAZE_SIZE; i++){
            for(int j=0; j<MAZE_SIZE; j++){
                printf("%d ",MAZE[i][j]);
            }
            printf("\n");
        }
    printf("Exit!\n");
    //
}

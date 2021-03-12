#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAZE_SIZE 10
#define STACK_SIZE 100

typedef struct _COORDINATE{
    int x;
    int y;
}COR;

typedef struct _STACK{
    COR coordinate[STACK_SIZE];
    int top;
}STACK;

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

void VISIT(COR cor){
    MAZE[cor.y][cor.x] = 7;
}

void __init__(STACK* stack){
    stack->top = -1;
}

int is_empty(STACK* stack){         // 구조체 변수를 매개변수로 줘도 사용가능
    if(stack->top == -1)            // 하지만 매개변수에 구조체의 모든 멤버변수가 복사되므로 비효율적
        return 1;                   // 그래서 함수의 매개변수로는 구조체 포인터를 사용한다
    else if(stack->top > -1)
        return 0;
}

void push(STACK* stack,COR cor){
    if(stack->top > STACK_SIZE-1){
        printf("STACK OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else{
        (stack->top)++;
        stack->coordinate[stack->top].x = cor.x;
        stack->coordinate[stack->top].y = cor.y;
        VISIT(cor);                                 // 미로 방문처리
    }
}

COR pop(STACK* stack){
    if(stack->top < 0){
        printf("STACK UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else{
        return stack->coordinate[--(stack->top)];
    }
}

int main(){

    STACK stack;
    __init__(&stack);

    COR current;

    for(int i=0,exit_outer_loop=0; i<MAZE_SIZE; i++){          // 미로 시작지점 탐색
        for(int j=0; j<MAZE_SIZE; j++){
            if(MAZE[i][j]==2){
                current.x = j;
                current.y = i;
                push(&stack,current);
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

    for(;MAZE[current.y][current.x+1] != 3 && MAZE[current.y+1][current.x] != 3 && MAZE[current.y][current.x-1] != 3 && MAZE[current.y-1][current.x] != 3;){
        if(!MAZE[current.y][current.x+1]){
            ++current.x;
            push(&stack,current);
        }
        else if(!MAZE[current.y+1][current.x]){
            ++current.y;
            push(&stack,current);
        }
        else if(!MAZE[current.y-1][current.x]){
            --current.y;
            push(&stack,current);
        }
        else if(!MAZE[current.y][current.x-1]){
            --current.x;
            push(&stack,current);
        }
        else{
            current = pop(&stack);
        }
        
        printf("\n");
        for(int i=0; i<MAZE_SIZE; i++){
            for(int j=0; j<MAZE_SIZE; j++){
                printf("%d ",MAZE[i][j]);
            }
            printf("\n");
        }
        printf("Current Location is: [%d,%d]\n",current.x,current.y);
        Sleep(1000);       // 리눅스는 sleep함수, 초단위. Window OS window.h의 는 Sleep() ms 단위
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

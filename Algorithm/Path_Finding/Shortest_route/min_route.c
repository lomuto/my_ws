#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100
#define QUEUE_SIZE 100
#define BUFFER_SIZE 100


/****************** STACK *******************/
int STACK[STACK_SIZE];
int top = -1;

int is_stack_empty() { return top > -1 ? 0 : 1; }

int is_stack_full() { return top < STACK_SIZE - 1 ? 0 : 1; }

void stack_init() { top = -1; }

void PUSH(int n) {
    if (is_stack_full()) {
        printf("STACK OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else
        *(STACK + (++top)) = n;
}

int POP() {
    if (is_stack_empty()) {
        printf("STACK UNDERFLOW\n");
        exit(EXIT_FAILURE);
    }
    else
        return *(STACK + (top--));
}
/********************************************/


/****************** QUEUE *******************/
int QUEUE[QUEUE_SIZE];
int rear = 0;
int front = 0;

int is_queue_empty() { return rear == front ? 1 : 0; }

int is_queue_full() { return (rear + 1) % QUEUE_SIZE == front; }

void queue_init() { rear = 0; front = 0; }

void PUSHQ(int n) {
    if (is_queue_full()) {
        printf("QUEUE is full\n");
        exit(EXIT_FAILURE);
    }
    else
        *(QUEUE + (++rear)) = n;
}

int POPQ() {
    if (is_queue_empty()) {
        printf("QUEUE is empty\n");
        exit(EXIT_FAILURE);
    }
    else
        return *(QUEUE + (++front));
}
/********************************************/

void DFS(const int** GRAPH, int NODE_AMOUNT) {
    stack_init();
    int* DFS_visited = (int*)calloc(NODE_AMOUNT, sizeof(int));   // initialize visited array to 0
    (*DFS_visited)++; //starting from first node
    PUSH(0);
    printf("1 ");

    for (int i = 0, j = 0, count = 1; count < NODE_AMOUNT;) {
        if (*(*(GRAPH + i) + j) && !*(DFS_visited + j)) {
            (*(DFS_visited + j))++;
            PUSH(i = j);
            count++;
            printf("%d ", j + 1);
            j = 0;
        }
        else if (j == NODE_AMOUNT - 1) {
            i = POP();
            j = 0;
        }
        else j++;
    }

    free(DFS_visited);
}

void BFS(const int** GRAPH, int NODE_AMOUNT) {
    queue_init();
    int* BFS_visited = (int*)calloc(NODE_AMOUNT, sizeof(int));
    (*BFS_visited)++; //starting from first node
    PUSHQ(0);
    printf("1 ");

    for (int i = 0, j = 0, count = 1 ; count < NODE_AMOUNT;) {
        if (*(*(GRAPH + i) + j) && !*(BFS_visited + j)) {
            (*(BFS_visited + j))++;
            PUSHQ(j);
            count++;
            printf("%d ", j + 1);
        }
        else if (j == NODE_AMOUNT - 1) {
            i = POPQ();
            j = 0;
        }
        else j++;
    }


    free(BFS_visited);
}

int main() {
    int** GRAPH;
    int NODE_AMOUNT;
    char BUFFER[BUFFER_SIZE];

    FILE* fp = fopen("input.txt", "r");

    //// Build Graph ////
    for (int ct = 1; (fgets(BUFFER, BUFFER_SIZE, fp)); ct++) {
        NODE_AMOUNT = atoi(BUFFER);

        GRAPH = (int**)malloc(NODE_AMOUNT * sizeof(int*));          // col
        for (int i = 0; i < NODE_AMOUNT; i++)
            *(GRAPH + i) = (int*)calloc(NODE_AMOUNT, sizeof(int));  // row

        for (int i = 0; i < NODE_AMOUNT && fgets(BUFFER, BUFFER_SIZE, fp); i++) {
            char* temp = strtok(BUFFER, " ");
            int GRAPH_COL = atoi(temp) - 1;    // index of array: minus 1
            for (; temp = strtok(NULL, " ");)
                (*(*(GRAPH + GRAPH_COL) + atoi(temp) - 1))++;
        }

        printf("\n===================\n");
        printf("GRAPH[%d]\n", ct);
        printf("------------------\n");
        printf("DFS Route\n");
        DFS(GRAPH, NODE_AMOUNT);
        printf("\n");
        printf("BFS Route\n");
        BFS(GRAPH, NODE_AMOUNT);
        printf("\n");
        printf("===================\n");

        for (int i = 0; i < NODE_AMOUNT; i++)
            free(GRAPH[i]);
        free(GRAPH);
    }
}
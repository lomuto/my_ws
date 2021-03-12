#include <cassert>
#include <iostream>
#include <queue>
#include <stack>

/*
간과했던것들

노드 방문 시 다른 노드에서 그 노드 방문 못하게 막아야 했음
(열 삭제 안함)

항상 모든 노드가 연결되어있다는 보장이 없음.

그래서 for문의 종료조건을 cnt != SIZE 로 하게되면 불필요하게 돌아다님.
테스트케아스에 결점이 없다는 가정 하에 스택 또는 큐가 비면 종료하게 했어야함


*/

int **D_MAP, **B_MAP;
std::stack<int> STACK;
std::queue<int> QUEUE;

void DFS(int START, int SIZE) {
    std::cout << START << " ";
    int st = START - 1;

    for (int i = 0; i < SIZE; i++) {
        (D_MAP[i][st]) = 0;
    }

    for (int i = st, j = 0;;) {
        if (j == SIZE) {
            if (STACK.empty()) {
                std::cout << std::endl;
                return;
            }

            i = STACK.top();
            STACK.pop();
            j = 0;
        } else if (D_MAP[i][j]) {
            std::cout << j + 1 << " ";
            //visit
            (D_MAP[j][i]) = 0;
            for (int i = 0; i < SIZE; i++) {
                (D_MAP[i][j]) = 0;
            }

            // // DEBUG
            // std::cout << std::endl;
            // for (int i = 0; i < SIZE; i++) {
            //     for (int j = 0; j < SIZE; j++) {
            //         std::cout << D_MAP[i][j];
            //     }
            //     std::cout << '\n';
            // }
            // std::cout << std::endl;
            // ///////////

            STACK.push(i);
            i = j;
            j = 0;
        } else {
            j++;
        }
    }
}

void BFS(int START, int SIZE) {
    std::cout << START << " ";
    int st = START - 1;

    for (int i = 0; i < SIZE; i++) {
        (D_MAP[i][st]) = 0;
    }

    for (int i = st, j = 0;;) {

        if (j == SIZE) {
            if (QUEUE.empty()) {
                std::cout << std::endl;
                return;
            }

            i = QUEUE.front();
            QUEUE.pop();
            j = 0;

        } else if (B_MAP[i][j]) {
            std::cout << j + 1 << " ";
            //visit
            (B_MAP[j][i]) = 0;
            for (int i = 0; i < SIZE; i++) {
                (B_MAP[i][j]) = 0;
            }

            QUEUE.push(j);
            j++;
        } else {
            j++;
        }
    }
    std::cout << std::endl;
}

int main() {
    int SIZE, EDGE, START;
    std::cin >> SIZE >> EDGE >> START;

    D_MAP = (int **)malloc(SIZE * SIZE * sizeof(int));
    B_MAP = (int **)malloc(SIZE * SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        *(D_MAP + i) = (int *)calloc(SIZE, sizeof(int));
        *(B_MAP + i) = (int *)calloc(SIZE, sizeof(int));
    }

    for (int i = 0, x, y; i < EDGE; i++) {
        std::cin >> x >> y;
        D_MAP[x - 1][y - 1]++;
        D_MAP[y - 1][x - 1]++;
        B_MAP[x - 1][y - 1]++;
        B_MAP[y - 1][x - 1]++;
    }

    DFS(START, SIZE);
    BFS(START, SIZE);
}
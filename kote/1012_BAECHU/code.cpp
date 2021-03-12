#include <iostream>
#include <stack>

int **MAP;

typedef struct _COR {
    int x;
    int y;
} COR;

void DEBUG(int row, int col) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            std::cout << MAP[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DFS(int i, int j, int row, int col) {
    std::stack<COR *> STACK;
    COR *cor = (COR *)malloc(sizeof(COR));
    cor->x = j;
    cor->y = i;
    STACK.push(cor);
    MAP[i][j] = 0;
    for (;;) {

        // std::cout << "Looking at [" << i + 1 << "," << j + 1 << "]" << std::endl;

        if (i != row - 1 && MAP[i + 1][j] == 1) {
            COR *cor = (COR *)malloc(sizeof(COR));
            cor->x = j;
            cor->y = i;
            STACK.push(cor);
            MAP[i + 1][j] = 0;
            i++;
        } else if (j != col - 1 && MAP[i][j + 1] == 1) {
            COR *cor = (COR *)malloc(sizeof(COR));
            cor->x = j;
            cor->y = i;
            STACK.push(cor);
            MAP[i][j + 1] = 0;
            j++;
        } else if (i && MAP[i - 1][j] == 1) {
            COR *cor = (COR *)malloc(sizeof(COR));
            cor->x = j;
            cor->y = i;
            STACK.push(cor);
            MAP[i - 1][j] = 0;
            i--;
        } else if (j && MAP[i][j - 1] == 1) {
            COR *cor = (COR *)malloc(sizeof(COR));
            cor->x = j;
            cor->y = i;
            STACK.push(cor);
            MAP[i][j - 1] = 0;
            j--;
        } else {
            if (STACK.empty())
                return;
            j = STACK.top()->x;
            i = STACK.top()->y;
            STACK.pop();
        }
    }
}

int BAECHU(int row, int col) {
    int cnt = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (MAP[i][j]) {
                cnt++;
                DFS(i, j, row, col);
            }
        }
    }

    return cnt;
}

int main() {
    int T, M, N, K;

    std::cin >> T;

    for (int t = 0; t < T; t++) {

        std::cin >> M >> N >> K;

        MAP = (int **)malloc(M * N * sizeof(int));

        for (int i = 0; i < N; i++) {
            *(MAP + i) = (int *)calloc(M, sizeof(int));
        }

        // (x,y) 는 MAP[y][x]
        for (int i = 0, x, y; i < K; i++) {
            std::cin >> x >> y;
            (MAP[y][x])++;
        }

        // DEBUG(M, N);

        std::cout << BAECHU(N, M)
                  << std::endl;

        for (int i = 0; i < N; i++) {
            free(*(MAP + i));
        }
        free(MAP);
    }
}
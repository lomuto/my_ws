#include <stdio.h>
#define INF 100000000
#define MIN(x,y) (x)<(y)?(x):(y)
#define N 5

int Graph[][N] = {
    0, 10, INF, 30, 100,
    INF,0, 50, INF, INF,
    INF, INF, 0, INF, 10,
    INF, INF, 20, 0, 60,
    INF, INF, INF, INF, 0
};

int Distance[N];
int Selected[N] = {0,};         // 이미 최소거리에 해당하는지 유무 판별. type으로 bool 사용하는게 좋지만 print 안돼서 int사용

void dijkstra(){
    for(int i=0; i<N; i++)
        Distance[i] = Graph[0][i];

    for(int i=0; i<N; i++){     // i<N-1 로 해도 결과값은 같음 (마지막에는 최단거리 바뀌는거 없음). printf 함수로 Selected 배열 상태 보려고 종료조건 i<N 으로 함
        int current_selected=0;
        for(int k=0,min = INF; k<N; k++)
            if(!*(Selected+k)&&(min>*(Distance+k))){
                current_selected = k;                   // 이번 for문에서 최소거리 집합의 원소가 될 최소거리
                min = *(Distance+k);
            }

        *(Selected+current_selected) = 1;
        for(int i=0; i<N; i++)
            printf("%d ",*(Selected+i));
        printf("\n");

        for(int j = 0;j<N; j++){
            if(!*(Selected+j))
                *(Distance+j) = MIN(*(Distance+j),*(Distance+current_selected)+*(*(Graph+current_selected)+j));
                // MIN 전처리함수에서 비교대상은 이번에 Selected 된 정점(vertax). 즉 current_selected 이다. i 아님 
        }
        for(int i=0; i<N; i++)
            printf("%d ",*(Distance+i));
        printf("\n");
        printf("\n");
    }
}

int main(){
    dijkstra();
}

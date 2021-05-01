# 행렬순환

[https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1168/](https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1168/)

Base Condition의 중요성, **그래프 탐색에서 방문처리는 반드시 처음에 해야한다는걸** 꺠닫게 해주는 문제.

맵이 주어질 때 나선형으로 원소들을 돌며, 진행중이던 방향의 다음 원소가 맵의 경계를 벗어나거나 방문했던곳이면 방향을 바꾸는 문제.

탐색방향은 DFS,BFS에서 많이해봤으므로

```cpp
int dr[] = {0,-1,0,1};
int dc[] = {1,0,-1,0};
```

을 잡고, 크기가 4인 배열을 순회하는 d는

```cpp
d++;
dr[d%4];
dc[d%4];
```

와 같이 설정.

---

</br>   
   
1. 원소의 진행방향이 경계를 벗어나거나 방문했던 곳일 경우   
2. 방문이 가능한경우   
   
이렇게 반복문에서의 조건문이 크게 두개로 나뉠텐데,   
**방문처리를 반복문 초기에 처리해주지 않고 조건문 안에서 처리해주면 무한루프에 빠진다.**   
   
```cpp
if(r+dr[d] > -1 && r+dr[d] < row && c+dc[d] > -1 && c+dc[d] < col && matrix[r+dr[d]][c+dc[d]] != -101){ // 원소의 범위가 -100 ~ 100 이라 방문처리를 원소가 -101 일때로 함.
    ans[pivot++] = matrix[r][c];
    matrix[r][c] = -101;
}
else{
    d++;
}
```   
이렇게 코드를 쓰면 **사방이 방문처리된 맨 마지막 원소는 조건문에 들어가지 못하고 계속 뺑뺑이를 돌게 된다,**   
그러므로 반드시 조건문 이전의 반복문 진입 시 방문처리를 해주어야 한다.   
   
```cpp
while(pivot < row*col){
            ans[pivot++] = matrix[r][c];    // 반복문 진입 시 방문처리
            matrix[r][c] = -101;
            int d = dm%4;
            if(r+dr[d] > -1 && r+dr[d] < row && c+dc[d] > -1 && c+dc[d] < col && matrix[r+dr[d]][c+dc[d]] != -101)
                ;
            else{
                dm++;
                d = dm%4;
            }
            r += dr[d];
            c += dc[d];
        
        }
```

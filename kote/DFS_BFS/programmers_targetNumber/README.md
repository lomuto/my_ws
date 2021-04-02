# 타겟 넘버

[https://programmers.co.kr/learn/courses/30/lessons/43165](https://programmers.co.kr/learn/courses/30/lessons/43165)

`1,1,1,1,1` 이 배열로 주어질 때, 각각의 수에 +,-을 붙여 타겟 넘버 `3`을 만들 수 있는 경우의 수는 5가지.

```
-1 +1 +1 +1 +1
+1 -1 +1 +1 +1
+1 +1 -1 +1 +1
+1 +1 +1 -1 +1
+1 +1 +1 +1 -1
```

임의의 배열과 타겟 넘버가 주어질 때 가능한 경우의 수 출력.

---

전체합에서 target 뺀만큼을, 배열 오름차순으로 정렬해서 하나하나 끼워 맞춰가려다가 중복체크랑 오름차순만이 정답이 아닌거 생각하고 일찌감치 포기하고 해설을 본 문제.

재귀호출을 통해 전부를 탐색하는 DFS 문제라고 한다.  
DFS, BFS는 미로찾기밖에 안해봐서 그런지 이게 DFS 일줄은 꿈에도 몰랐다.

```cpp
#include <vector>

using namespace std;

int cnt=0;
int tg;

void dfs(vector<int> num,int index,int sum){
    if(index == num.size()-1){
        if(tg == sum-num[index])
            cnt++;
        else if(tg == sum+num[index])
            cnt++;
        return;
    }else{
        dfs(num,index+1,sum+num[index]);
        dfs(num,index+1,sum-num[index]);
        return;
    }
}

int solution(vector<int> numbers, int target) {
    tg=target;
    dfs(numbers,0,0);
    return cnt;
}
```

# 경주로 건설

[https://programmers.co.kr/learn/courses/30/lessons/67259](https://programmers.co.kr/learn/courses/30/lessons/67259)

격자에서 경주로를 건설하는데 꺾이는 구간이 있으면 비용이 늘어남. 시작점부터 목적지까지 최소 건설비용을 구하는 문제.

단순 BFS는 최소비용을 구해주지 못한다... BFS의 한계점을 극복한 다익스트라 처럼 **방문했던 지점을 한번 더 보면서 최소값으로 거리를 업데이트 하는** 성질을 이용해야한다.

한번 봤던 점을 또 보자니 어떻게 해야할지 감이 안잡힌다..  
첫번째로 시도했던 방식은 `while(!q.empty())` 안의 반복문에서 방문처리를 하는 지점을 옮기는 것이었다.

### 내가 했던 틀린 방법

```cpp
while(!q.empty()) {
    int curr = q.front();
    q.pop();
    // grid[curr] = true;

    for(int adjacentNode : curr) {
        if(grid[adjacentNode] == false) {
            // grid[adjacentNode] = true;
            q.push(adjacentNode);
        }
    }
}
```

주석친 두 부분은 모두 동일한 방문처리를 수행하고있다. 차이점은 **상위 부분에서 방문처리를 수행하면 큐에 노드가 중복해서 담길 수 있다는 점이다** 이런 경우로 중복방문을 허용해 각 노드까지의 최소거리를 갱신할 수 있겠지만 이는 시간초과가 났다..

### 옳은 방법

```cpp
// dijkstra 일부
int curr = pq.top().second;
int weight = pq.top().first;
pq.pop();

for(int adjacentNode : graph[curr]){
    if(dist[curr] + weight < dist[adjacentNode]) {
        continue;
    }
    // ...
    pq.push(...);
}
``
```

다익스트라에서는 위와 같이 최소거리로 업데이트가 되지 않으면 큐에 push하지 않는다 (최소거리로 업데이트 되는 노드를 큐에 push한다)  
위 문제에서도 동일하게 주어진 도로에서 갈 수 있는 거리일 경우 이 길을 보되, **최소 거리로 업데이트가 가능한 경우만 큐에 push하면** 최소거리만 한번 더 탐색할 수 있다.

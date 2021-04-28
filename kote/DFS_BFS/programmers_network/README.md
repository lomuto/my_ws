# 네트워크

[https://programmers.co.kr/learn/courses/30/lessons/43162](https://programmers.co.kr/learn/courses/30/lessons/43162)

---

<br/>   
   
푸는데 1시간이 걸렸다..

나는 bfs로 풀었는데 다른 풀이 보니까 dfs가 훨씬 깔끔하고 간결한 것 같다.  
다음에 dfs 버전도 이해되면 추가해야겠다

---

<br/>  
   
노드간의 연결 여부가 표시된 맵을 요리조리 왔다갔다 하다가 **큐가 비어있고 col==SIZE 일때 방문되지 않은 노드가 없을경우를 종료조건으로 설정했다.**   
   
`a[row][col] == 1` 일 경우 좌표를 queue에 push하고 **해당 좌표와 대칭에 위치한 좌표를 0으로 바꾼다.**   
다음부터 볼 좌표는 `a[col][row]`가 되게 한다.   
```cpp   
if (a[row][col] == 1) {
            q.push(make_pair(row, col));
            a[row][col] = a[col][row] = 0;
            VISITED[col] = 1;
            row = col;
            col = 1;
        }
```   
<br/>

만약 col 이 끝에 다다랐을 때( `col == SIZE` ) 큐가 비어있다면 이는 **노드간의 연결의 막바지**란 뜻이므로 네트워크의 개수를 하나 추가해준다.  
방문되지 않은 노드가 없으면 이는 종료조건이고, 방문되지 않은 노드가 있다면 **방문처리 후 노드의 처음으로 이동한다.**  
큐가 비어있지 않다면 pop 한 노드로 이동해 나머지 노드의 연결여부를 살핀다.

```cpp
else if (col == SIZE) {
            if (q.empty()) {
                network++;
                int flag = 0;
                for (int i = 1; i <= SIZE; i++) {
                    if (VISITED[i] == 0) {
                        VISITED[i] = 1;
                        row = i;
                        col = 1;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    return;
            } else {
                row = q.front().first;
                col = q.front().second;
                q.pop();
            }
```

<br/>
   
위에 언급한 case가 아니면 현 노드에서 다른 노드와의 연결여부를 살피기 위해 col을 증가한다   
```cpp
else col++;
```

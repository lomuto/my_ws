# 지하철

[https://www.acmicpc.net/problem/17940](https://www.acmicpc.net/problem/17940)

기존의 다익스트라 문제에서 살짝 꼰 문제.

간선의 weight 말고도 최소환승 경로를 찾아야 해 처음에 방법이 안떠올랐다.

방법은 의외로 간단했다... 환승이 일어날 경우 **기존 weight에 가중치를 더해 환승하는 경로를 더 길게 보는 것**

주어진 노드는 1000개, 가중치의 최대값도 1000개.

모든 노드가 연결되어있을 경우 `1e6/2` 개의 간선에 대해 각각 `1e3` 의 weight 가 주어지겠지만...  
최적경로는 결국 **각 노드에서 다른 노드로 가는 간선 중 weight가 최소인 단일 간선만의 집합이므로, 최악의 상황에서의 최단경로는 1e6일 것 이다.**  
고로 가중치를 1e6로 잡고 풀었다.

<br/>   
   
환승횟수는 최종 최단경로를 지나는 거리에서 가중치를 mod 연산하면 나올것...   
``` cpp
//ex   
2000018 이 최단거리라면, 가중치가 두번 더해진거   
진짜 길이: 18
```   
   
처음에 이걸 캐치 못하고 path 추적해서 재귀로 카운팅했다 ㅡㅡ

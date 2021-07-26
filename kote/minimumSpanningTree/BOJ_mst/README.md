# 최소 스패닝 트리

[https://www.acmicpc.net/problem/1197](https://www.acmicpc.net/problem/1197)

- set이 Node를 가리키고, Node의 parnet 멤버는 해당 노드가 속한 트리의 root를 가리킴.  

- 모든 Node들에 대해, 각 Node를 root로 가지는 트리를 V개 생성.  

- edge들을 가중치의 오름차순으로 정렬 후, 해당 edge를 전부 돌며 트리를 형성하면 edge를 mst에 포함, 아닐경우 다음 edge를 봄.  

- edge가 트리를 형성하는지, 사이클을 형성하는지는, 첫번째 언급했던대로 set은 Node를, Node는 속한 트리의 root를 가리키므로 그거로 판단 가능.

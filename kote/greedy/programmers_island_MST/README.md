# 섬 연결하기

[https://programmers.co.kr/learn/courses/30/lessons/42861](https://programmers.co.kr/learn/courses/30/lessons/42861)

문제 분류가 왜 그리디일까...  
mst에서 edge들을 적은 가중치 순으로 평가하면서, `최소 가중치의 set ==> 최종 가중치가 minimum` 인 해법을 추구하기 때문인 것 같다.

edge들을 가중치의 오름차순으로 정렬하고, 유니온 파인드 수행하면 되는 문제 (크루스칼 알고리즘)

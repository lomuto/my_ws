# 1012 유기농배추

[https://www.acmicpc.net/problem/1012](https://www.acmicpc.net/problem/1012)

</br>   
   
- 가로 세로 길이 받을 때 행,열로 할건지 가로,세로로 할건지 변수명 명확하게 할 필요가 있음.   
Vertical, Horizon 이 깔끔할듯...
   
- DFS 말고 BFS로 구현해도 난이도는 비슷할듯함   
   
- 이중for문으로 전체 순회하되 길이 있으면 DFS 시작.   
   
- **그래프를 둘러싼 안전쿠션? 이 없으면 할당받지 않은 메모리 if문에서 접근 ( if(MAP[i+1][j] == 1) )하는거만으로도 Segmentation fault 발생. ( i != row - 1 && MAP[i + 1][j] == 1 ) 와같이 and연산자 앞에 조건을 둬서 메모리 침범 못하게 해줘야함**

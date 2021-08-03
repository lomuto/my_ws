# 등굣길

[https://programmers.co.kr/learn/courses/30/lessons/42898](https://programmers.co.kr/learn/courses/30/lessons/42898)

![ex](./images/ex.PNG)

dfs로 푸려고 코드 짜다 보니까 경우의 수를 1000000007로 나누라는거 보고 이렇게 짜면 시간초과 나겠구나 싶어서 DP 풀이를 떠올린 문제.

grid[i][j] 에 대해, 움직일 수 있는 경우의 수는 **오른쪽** 아니면 **아래** 이므로  
grid[i][j] = grid[i-1][j] + grid[i][j-1] 이 성립한다.

물웅덩이는 가지 못하므로 이에대한 예외처리면 잘 해주면 통과하는 문제.

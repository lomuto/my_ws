# Taxi

[https://codeforces.com/problemset/problem/158/B](https://codeforces.com/problemset/problem/158/B)

### **큰수에서 작은수로 따지기**

1. 4명씩 태워서 보내기
2. 3명+1명 태우기.  
   `min(three,one)` 해서 나온값을 세명과 한명 그룹의 인원에서 각각 빼고 그 값을 `sum` 에 더하기.
3. 2명+2명  
   만약 2명 그룹이 짝수가 아니면 한 그룹이 남아서 그 그룹은 1명 그룹이랑 묶어서 보내야함
4. 나머지 1명그룹  
   `one/4` 한 수를 sum에 더하고 `if(one%4)` 이면 4로 나눠떨어지지 않았으므로 택시 한대 더 추가 `sum++`  


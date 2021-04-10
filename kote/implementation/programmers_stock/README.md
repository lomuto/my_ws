# 주식 가격

[https://programmers.co.kr/learn/courses/30/lessons/42584](https://programmers.co.kr/learn/courses/30/lessons/42584)

다른 풀이 보니까 스택으로 풀던데 굳이...  
내 풀이로도 풀려서 구현 항목에 추가했다.  
스택이나 내 풀이나 시간복잡도는 똑같이 `다항시간 제곱`

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int SIZE = prices.size();

    for (int pivot = 0; pivot < SIZE - 1; pivot++) {
        int cnt = 1;
        for (int i = pivot + 1; i < SIZE - 1; i++) {
            if (prices[i] >= prices[pivot])
                cnt++;
            else
                break;
        }
        cnt ? answer.push_back(cnt) : answer.push_back(1);
    }
    answer.push_back(0);

    return answer;
}
```

pivot 두개 놓고 배열 전체 탐색. pivot2 값이 나보다 작아지는 순간 break

**신경써야할 점**

- **내 바로 다음 직후 값이 떨어져도 1초간 값이 안떨어진거로 해야함 = default 값이 1** ==> cnt 초기값 1로 설정  

- **맨 마지막 원소의 경우 다음 원소값이 없어서 위의 정의에 따라 default 값을 1로 하는게 아니라 0으로 예외적으로 처리** ==> 탐색범위를 `시작 ~ 끝` 이 아닌 `시작 ~ 끝-1` 로 하고 끝에 0인 원소 하나 추가.

이렇게 두가지 정도 신경쓰면 되는데 스택을 쓰면 신기하게도 예외조건들이 다 처리가 되더라

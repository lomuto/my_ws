# Check Double    
   
[https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/](https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/)   
   
정렬되지 않은 배열이 주어질 때,   
안의 임의의 원소 `k` 가 다른 원소 `n == k*2` 를 만족하는경우 `true`를, 없다면 `false`를 리턴하는 문제.   
   
주먹구구식으로 풀면 `O(n^2)` 이거 줄여보겠다고 정렬 -> 이분탐색 시도했는데 원소가 0일 경우가 있어서 범위 다시 조정하고 음수인 경우도 있어서 현재 보는 숫자가 음수면 왼쪽을, 아니면 오른쪽을 보고.. 별의 별 짓 다 하다가 1시간을 날려버린 문제.   
   
``` java
public boolean checkIfExist(int[] arr) {
        HashSet<Integer> set = new HashSet<>();

        for(int i : arr) {
            if(set.contains(i*2)) {
                return true;
            }
            if(i % 2 == 1 && set.contains(i / 2)) {
                return true;
            }

            set.add(i*2);
        }

        return false;
    }
```   
   
그냥 이렇게 HashSet 활용해서 나의 두배, 또는 내가 짝수일경우 절반 (홀수일경우 절반을 따져버리면 정확히 두배 아닌데 통과하는 경우 생겨벌임) set에서 확인하면 `O(n)` 에 끝나는 문제.   
   
ㅠㅠ
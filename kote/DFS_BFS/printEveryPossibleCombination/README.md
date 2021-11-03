# 가능한 모든 경우의 수 출력하기

```java
public void printEveryPossibleNumber(int[] nums, int currDigit, int maxDigit, HashSet<Integer> isVisited, StringBuilder sb) {
    if(currDigit == maxDigit) {
        System.out.println(sb.toString());
        return;
    }

    for(int i : nums) {
        if(isVisited.contains(i)) {
            continue;
        }

        // 지금 보는 숫자 이전까지 경로에서 본적 없음
        isVisited.add(i);
        sb.append(i);
        printEveryPossibleNumber(nums, currDigit + 1, maxDigit, isVisited, sb);
        sb.remove(sb.size()-1);
        isVisited.remove(i);
    }
}
```

여기까지는 떠올렸는데 숫자의 자릿수를 어떻게 제한하지 하다가 그냥 main에서 `maxDigit` loop돌리면 된다는거 깨달았음....

```java
for(int i=0; i<maxDigitIWant; i++) {
    printEveryPossibleNumber(nums, 0, i, isVisited, sb);
}
```

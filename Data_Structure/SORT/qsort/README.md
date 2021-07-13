# Quick sort

퀵소트 구현 함수 안에서

```cpp
while(left<right) {
    while(target < arr[right]){
        right--;
    }
    while(left<right && target >= arr[left]){   // 여기 크거나 or 작거나 and 같다도 넣어주어야 한다.
        left++;
    }
}
```

while(left<right && target **>=** arr[left])

퀵소트 손수 구현할때 맨날 헷갈리는건데, 두번째 비교함수에서는 같거나도 들어간다..

</br>     
    
---   
   
</br>

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 5   | 9   | 4   | 7   | 3   | 2   | 8   | 1   |

</br>

Set `5` as pivot.  
Index `7` will be `right`, and index `1` would be `left`.  
Each will decrease and increase for each untill it mets smaller than pivot for `right` and larger than pivot for `left`

When job is done, swap element in `left` and `pivot`

Array after first sort would be like.

| 0   | 1   | 2   | 3   | 4     | 5   | 6   | 7   |
| --- | --- | --- | --- | ----- | --- | --- | --- |
| 3   | 1   | 4   | 2   | **5** | 7   | 8   | 9   |

</br>     
    
   
---   
   
</br>
   
## Random pivot   
   
Same process, but some extras in inital one.

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 5   | 9   | 4   | 7   | 3   | 2   | 8   | 1   |

</br>   
   
Assume that randomly choosen index is `3`.   
Swap its element with first element( index `0` ).

| 0     | 1   | 2   | 3     | 4   | 5   | 6   | 7   |
| ----- | --- | --- | ----- | --- | --- | --- | --- |
| **7** | 9   | 4   | **5** | 3   | 2   | 8   | 1   |

</br>    
   
Following process would be same as normal q_sort.   
   
   
Array after first sort would be like.

| 0   | 1   | 2   | 3   | 4   | 5     | 6   | 7   |
| --- | --- | --- | --- | --- | ----- | --- | --- |
| 2   | 1   | 4   | 5   | 3   | **7** | 8   | 9   |

# Quick sort

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 5   | 9   | 4   | 7   | 3   | 2   | 8   | 1  |

</br>

Set `5` as pivot.  
Index `7` will be `right`, and index `1` would be `left`.  
Each will decrease and increase for each untill it mets smaller than pivot for `right` and larger than pivot for `left`

When job is done, swap element in `left` and `pivot`

| 0 | 1 | 2 | 3 | 4   | 5 | 6 | 7 |
| --- | --- | --- | --- | ----- | --- | --- | --- |
| 3   | 1   | 4   | 2   | **5** | 7   | 8   | 9   |

</br>   
   
Array after first sort would be like.   
    
   
---   
   
</br>
   
## Random pivot   
   
Same process, but some extras in inital one.   
   

| 0 | 1 | 2 | 3 | 4   | 5 | 6 | 7 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 5   | 9   | 4   | 7   | 3   | 2   | 8   | 1   |   
   
</br>   
   
Assume that randomly choosen index is `3`.   
Swap its element with first element( index `0` ).   
   

| 0 | 1 | 2 | 3 | 4   | 5 | 6 | 7 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **7**   | 9   | 4   | **5**   | 3   | 2   | 8   | 1   |     
   
</br>    
   
Following process would be same as normal q_sort.   
   

| 0 | 1 | 2 | 3 | 4   | 5 | 6 | 7 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 2   | 1   | 4   | 5   | 3   | **7**   | 8   | 9   |    
   
Array after first sort would be like.

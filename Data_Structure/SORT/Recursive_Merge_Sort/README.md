# Recursive Merge Sort   
   
Split array till its length is at least 1.   
   
Merge two splited array as...   
1. make a copy of original array   
2. Starting form its first element of each splited array, compare two elements and put smaller one to original arrray untill one of them meet its end.   
3. As each splited pieces are SORTED,(proof by mathmaticial induction) push rest of its element to original array till it meets end.
   
***FATAL ERROR deteced when left = right while they are at the end of array.    
Segementation fault my middle + 1 while it exceed its maximum index (middle = (left+right)/2)***

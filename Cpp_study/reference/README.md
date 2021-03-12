# What is Reference

**Reference and Pointer are basically same**

```cpp
void SWAP(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

As C hands over parameter as **call by value**,
inorder to make SWAP function, we passes parameters as _pointer_.

This might cause two problems.

1. `SWAP(null,foo)`  
   This could cause unexpected run time error.  

2. Invading unallocated memory

```cpp
/*What I intended*/ (*a)++
/*What I wrote*/ *a++
```

As unary operator exceeds pointer operator, latter exp can lead to invading unallocated memory.

</br>   
   
To avoid those kind of problems, C++ provides `Reference`   
   
Reference is basically same as pointer in assembly level.   
   
Reference provides user friendly function that limits its initial allocation of pointer.

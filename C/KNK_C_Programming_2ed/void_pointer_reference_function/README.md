# Void pointer that referencing function

data type of certain variable `int* a` is `int*`  
same for such function `int func(int a)` is `int (*)(int)` which is data type it self.

let `m (*)n` is a data type of function then,

> `m` is a data type of function's ret value  
> while function's name is a pointer : `(*)` stands for pointer operator  
> `n` is a data type of function's parameter

think of `int*` as same for `int (*)(int)` which is both data type.  
while former one's variable name comes `int* _here_`  
latter one comes `int (* _here_)(int)`

Hence, followed by declared variable `void* func_ptr`  
if it wants to points function: `char* function(int a)`  
casting `func_ptr` must be

```
(char* (*)(int))func_ptr
```

passing parameter `3` would be

```
(*(char* (*)(int))func_ptr)(3) // dereference func_ptr while it is a pointer
```

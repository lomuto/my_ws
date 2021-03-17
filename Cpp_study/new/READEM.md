# new operator

</br>

### **new int(n)** : Returns address of pointer that dereferencing `n`

### **new int[n]** : Returns starting address of array that its size is `n`

</br>

```cpp
int* foo = (int*)malloc(SIZE*sizeof(int));
```

Code above is dynamically allocating memory for given `SIZE`  
In C++, **operator** `new` enables memory allocation easier.

</br>
   
```cpp
int* foo = new int[SIZE];
```
   
`new` also returns pointer variable, while `malloc` is `void*` but `new` is exact type corresponds to `foo`.   
   
</br>

When it comes to `class`,

```cpp
class Foo{
    public:
       Foo(){ ... };
};

...

Foo a = new Foo();
```

`new` operator will execute a constructor

</br>

---

</br>
   
For `malloc` , clearing a memory in `heap` has done by `free`   
for `new`, **`delete`** does it.

```cpp
int* foo = new int(4);  // create 4byte memory in heap and init with `4`

delete foo;

int* bar = new int[4];

delete [] bar;
```

When it comes to use `delete` in array,  
**Its essential to use bracket [] to letting know `delete` that not to deallocate just first element of array**  
(`delete bar` will deallocate only `bar+0` memory while cause memory leak by leaving `bar+1`.`bar+2`,`bar+3`)

</br>

---

</br>

```cpp
int* foo = (int*)calloc(10,sizeof(int));
int* bar = new int[10]{};
```

While `calloc` is `malloc` + `memset`,  
initialize whole memory to `0` could be done by `{}` **Uniform initializer**.

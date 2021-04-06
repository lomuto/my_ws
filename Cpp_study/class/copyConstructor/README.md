# Shallow and Deep Copy

We all know that when struct is passed by parameter, its entire memory is being copied. So when struct gets big, we use struct pointer to pass it as parameter instead.

hbu class? class and struct is just same thing in assembly. So passing an instance of class would yield same issue. That's when `copy constructor` is called.

```cpp
class Foo{
    private:
        int* arr;
    public:
        Foo(int n){
            arr = new int[n];
        };
        Foo(Foo& origin){
            arr = origin.arr;
        };   // same as constructor but parameter is referecne of its class type instance
};
```

As class `Foo` above

```cpp
Foo a(3);

Foo b = a;
Foo c(a);
```

both `b` and `c` are copy of `a`.

while those **`a` and `b` are shallow copied,** there might be an issue while those 3 are sharing same heap memory `arr[3]`.  
To avoid this problem,

```cpp
Foo(Foo& origin){
    memcpy(arr,origin.arr,sieof(int)*arr.size());
}
```

Modify `copy constructor` to enable **Deep copy** that each copied instance's pointer type member points to its own memory.

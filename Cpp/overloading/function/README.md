# Function Overloading

As we've saw at `constructor`, function can be overloaded with same name and differenct params.

```cpp
class Foo{
    ...
    Foo();
    Foo(int a);
    Foo(int a, string name);
};
```

---

</br>

## Return type

```cpp
int Foo(int a){...}
bool Foo(char a){...}   // legal
bool Foo(int a){...}    // illegal
```

While overloading a function with differenct parameter is legal, overloading it with different return type is also legal **as long as it has different parameters**.

Compiler can catch the differenece in `bool Foo(char a)` while its parameter is `char` as unique,  
`bool Foo(int a)` will yield confusion to compiler to choose with between `int Foo(int a)`.

---

</br>   
   
## Must be clear with argument   
   
Suppose we have overloaded function as   
```cpp
int Foo(int a,int b){...}
double Foo(double a, double b){...}
```
If we call a function as `Foo(4.3f,2)` it will yield an error while making compiler to confusing with **casting `int to double` or `double to int` are both legal**

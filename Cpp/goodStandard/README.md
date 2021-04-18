# Good (didn't say best :)) standard

```cpp
int foo(int a, int b, int c)
```

By simply looking at the function's return value and parameters, its hard to understand what it actually does.

```cpp
int foo(int a, const int b, const int c)
```

Its more clear to explicitely set `b` and `c` parameters as `const` by telling they are not manipulted.

</br>

```cpp
int foo(int& a,const int b, const int c)
```

Now we can clearly understand that `a` is to be manipulated and return as function, while `b` and `c` manipulates `a`.

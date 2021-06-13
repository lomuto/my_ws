# invalid initialization of non-const reference of type from an rvalue of type

```cpp
void foo(int *&arg) {
    cout << *arg << '\n';
}

int main() {
    int *sth = new int(2);
    foo(sth);   // fine

    foo(new int(4));    //error
}
```

As `new int(4)` is r-value, it has no address to reference. So we must set parameter as `int *const &` **(reference of const memory)** or `int* &&` **(in this case `foo(sth)` has to be `foo(move(sth))` to cast l-value sth to r-value)**

```cpp
void foo(int *const &arg) {
    cout << *arg << '\n';
}

int main() {
    int *sth = new int(2);
    foo(sth);

    foo(new int(4));
}
```

or

```cpp
void foo(int *&&arg) {
    cout << *arg << '\n';
}

int main() {
    int *sth = new int(2);
    foo(move(sth));

    foo(new int(4));
}
```

# destructor

```cpp
class Foo{
    ...
    ~Foo(){
        cout << "Instance destructed\n";
    }
};
```

Add `~` in prefix to name of constructor to make destructor.

Mostly used for avoid memory leakage, such situatuion that member of class' memory are dynamically allocated.

```cpp
class Foo{
    private:
        int* mem;
    public:
    Foo(int)
    ~Foo()
};

Foo::Foo(int n){
    mem = new int[n];
}
Foo::~Foo(){
    delete[] mem;
}
```

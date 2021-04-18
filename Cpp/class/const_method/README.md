# const method

```cpp
class Foo{
    private:
        int num;

    public:
        int get_num() const;
        void set_num(int arg);
};

int Foo::get_num() const{
    // num = 1;     ERROR
    return num;
}

void Foo::set_num(int arg){
    num = arg;
}
```

For getter and setter above,  
using `const` keyword in method **lock modifing member inside that function**

This feature is really useful for `get` method.  
Use `const method` as many as you can.

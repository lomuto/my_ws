# Overall

```cpp
class Foo{
    private:
        int mX;

    public:
        Foo();
        Foo(int arg);
        int get_X();
        void set_X(int arg);
        void show();
};

Foo::Foo()
    : mX(0){
        cout << "Member initiated to 0" << endl;
    }

Foo::Foo(int arg)
    : mX(arg){
        cout << "Member initiated to " << arg <<endl;
}

int Foo::get_X(){
    return mX;
}

void Foo::set_X(int arg){
    mX = arg;
}

void Foo::show(){
    cout << mX << endl;
}
```

Few things to notice first....

### 1. **Must end class with `;`** like structure, otherwise it will cause weird error.

### 2. Implementation of method must be held in same scope. ( Class definition in global, method implementation in main function in illegal. )

**It doesn't mean that define class and implement method in main function is leagal. Class doesn't allow nested function.**

### 3. Class' default access specifier is `private` while Structure's is `public`

</br>

- class' name comes with uppercase
- Sort members with access specifier

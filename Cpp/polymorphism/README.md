# Polymorphism: Single name, Multiple functionality

## How method is defined in cpp

<br/>

```cpp
// C++

class Foo{
    public:
        string name;
        void printName();
};

void Foo::printName(){
    cout << name;
}
```

 </br>

Such class `Foo` with `string name` as member with method `printName` whose job is to print a member name,  
Implementing those bunch of work could be expressed abstractly with `C` woule be...

</br>

```c
// C

struct Foo {
    char *name;
    void (*constructor_ptr)(struct Foo *this, char *name);
    void (*printName_ptr)(struct Foo *this);
};

void printName(struct Foo *this) {
    printf("%s\n", this->name);
}

void constructor_foo(struct Foo *this, char *name) {
    this->name = name;
    this->printName_ptr = printName;
}

int main() {
    struct Foo f;
    f.constructor_ptr = constructor_foo;
    f.constructor_ptr(&f, "John");
    // Abstracted as `Foo f("John") in Cpp`

    f.printName_ptr(&f);
    // Abstracted as `f.printName_ptr() in Cpp`
}
```

</br>   
   
As you see, there are so many abstraction.    
One important thing is that **method in Cpp is a just function pointer that referencing a function in C**   
   
When it comes to a `Inheritance`   
   
```cpp
// Cpp

class Foo{
public:
string name;
void printName();
};

class Bar : public Foo{
public:
void printName();
};

````

<br/>

```c
//C
// This is just an example...

struct Foo {
    char *name;
    void (*constructor_ptr)(struct Foo *this, char *name);
    void (*printName_ptr)(struct Foo *this);
};

struct Bar{
    struct Foo* parent;
    void (*constructor_ptr)(struct Bar *this, struct Foo* parent,char *name);
}


void printName_Bar(struct Foo *this) {
    printf("Bar.name: %s\n", this->name);
}
void printName_Foo(struct Foo *this) {
    printf("Foo.name: %s\n", this->name);
}
````

As we can see in here, `printName_ptr` points different function which does different operation.

So calling same `printName_ptr` in different class would yield different result.

---

</br>   
   
## Static and Dynamic binding
   
Instance of `Foo` can be can be copied to instance of `Bar`, but not vice versa    
```cpp
Foo f("Kim");
Bar b("Lisa");

b = f; // legal
f = b; // Illegal

````

<br/>

In contrast, `Foo*` variable can reference `Bar*` variable, not vice versa also.

```cpp
Foo f("Kim");
Bar b("Lisa");

Foo* f_ptr;
Bar* b_ptr;

*f_ptr = b;     // legal
*b_ptr = f;     // Illegal
````

<br/>

What happen if we call `printName` method in `f_ptr`?

```cpp
...
*f_ptr = b;
f_ptr->printName()  //?????
```

<br/>

In general `f_ptr` will read memory as **layout of class Foo**: which will executes function of `Foo`, even though its type is `Bar`.

We can solve this problem by adding `virtual` keyword to such method that both exist in `Foo` and `Bar`

```cpp
class Foo{
public:
    tring name;
    virtual void printName();   // virtual
};

class Bar : public Foo{
    public:
    virtual void printName();   // Virtual keyword in here is not necessary. But recommend for later unforseen derivation.
};
```

This enables a **Dynamic Binding** which creates an Lookup table for methods in each class (this means that each class has its unique lookup table) so that determins which function to execute when certain method is called ( which class to bind ).

---

</br>

## Polymorphism

To the bottom line, same named `printName` yields an different execution in different class, so polymorphism can be described as **single name, multiple functionality**

</br>

Others might argue that why would someone do stupid things that referencing derived class with type of parent class.

Suppose we have class `B,C,D` which derived from `A` with overrided method in `A`.  
If we have to execute same method in `B,C,D` that derived from `A`

```cpp
instanceOfB.METHOD();
instanceOfC.METHOD();
instanceOfD.METHOD();
```

we have to repeat it.  
**But what if we have dozens of `A`'s child classes? how about thousands?**  
It is where polymorphism and virtual shines.

```cpp
class A{
    ...
    virtual void METHOD();
    ...
};
...
A* listOfChildClass = new A[n];
... // load childeren
for(int i=0; i<n; i++)
    listOfChildClass[i].METHOD();
```

Each method call would be done appropriately with binding of class by lookup table.

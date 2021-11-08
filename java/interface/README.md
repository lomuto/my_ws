# Interface

Using Abstract class, we can pass derived objects with type of base(super) class

```java
// Class Child inherits Class Parent
public static void foo(Parent p) {
    p.abstractMethod();
}

public static void main(String args[]) {
    Child[] children = new Child();
    foo(children);
}
```

Some might argue that **Passing an instance of `Parent` seems redundant about its data(member) also goes with it, while what method `foo` does is only executing a `abstractMethod`**

This is where interface comes out.

**Inteface is an abstract class with only methods!**

## Multiple inheritance in interfaces

Unlike class, java provides multiple inheritance in interfaces

```java
interface IFooable {
    void foo();     // in interface, access modifier is not needed as set by public default.
                    // this is quite obvious... why would someone delcare unaccessable method in interface?!
    void magic();
}

interface IBarable {
    void bar();
    void magic();
}

public class A implements IFooable, IBarable {
    ...

    // If neither of one did not implemented, it would yields a compile error
    public void foo() {
        ...
    }

    public void bar() {
        ...
    }

    // duplicated method in IFooable and IBarable is good to go with single inplementation
    public void magic() {
        ...
    }
}
```

As you can see here, `magic` has implemented just one time as **implementation of interface has same concept with override**
This also means **if something is impossible in override, than so do it is in implementation**

```java
interface IA {
    int no();
}

interface IB {
    void no();
}

public class A implements IA, IB {

    // Methods between only difference in return type can't be overrided
        ...
        int no() {       // compile error
        }
        void no() {     // compile error
        }
}
```

Usually signature in function contains its return type but not in OOP.

```C
int hello() {
    ...
}

void hello() {
    ...
}

int main() {
    hello();    // which function would executed?!
}

```

As code above implies, same signature in function doesn't includes its return type.

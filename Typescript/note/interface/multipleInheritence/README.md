# Multiple inheritence

```ts
class A {
    constructor(
        private a: string
    ){};
};

class B {
    constructor(
        private b: string
    ){};
};

class C extends A,B {
    // compile error
}
```

If we try to compile this code, typescript will yeild an error: `Classes can only extend a single class`.  
Just like the Java, class can only be inherited with a single class in typescript (while C++ can do such thing!)

We can hack this in typescript by interface implementation.

```ts
interface Foo {
  name: string;
}

interface Bar {
  age: number;
}

class Z implements Foo, Bar {
  constructor(public name: string, public age: number) {}
}
```

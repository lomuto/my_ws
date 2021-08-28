# Class implement interface

```ts
interface Foo {
  name: string;
}

class Bar implements Foo {
  constructor(public name: string, private age: number) {}
}
```

We can create a class with given interface with `implements` keyword.

One thing to notice is that **Given property with interface must be implemented with public access modifier in class**.

```ts
interface Foo {
  name: string;
}

class Bar implements Foo {
  constructor(private name: string) {} // compile error
}
```

Inorder to implement class that has priavte member with given interface, there is a hack about it.

```ts
interface Foo {
  getName(): string;
}

class Bar implements Foo {
  constructor(public name: string) {}

  getName() {
    return this.name;
  }
}
```

We can force it with method `getName` which is getter of private property `name`

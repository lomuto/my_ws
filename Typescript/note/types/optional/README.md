# Optional property

Property in object or parameters in function can be optional with `?` keyword.

```ts
interface Foo {
  name?: string;
  age: number;
}

interface Func {
  (a?: number, b: string): void;
}
```

With instance of such object `Foo` or function `Func`, their `name` and `a` would be optional.

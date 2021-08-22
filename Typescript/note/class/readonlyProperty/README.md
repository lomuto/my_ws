# readonly property

```ts
class foo {
  private prop0; // compile error
}
```

`const` keyword is not provided in typescript.

If we want **property to remians unmutable after initialization**, this is where `readonly` keyword comes in.

<br/>

```ts
class foo {
  private readonly prop0; // compile error
}
```

Thiss will make `prop0` as constant.

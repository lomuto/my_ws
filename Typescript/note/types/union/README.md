# Union

Suppose your variable could be `string` and also `number` which is you can't be sure through runtime.

This is where `union` take place.

```ts
let foo: string | number;
```

`foo` now can be assigned as `string` and also `number`.

---

<br/>   
   
### Handle union type as parameter

```ts
const combine = (
  arg0: string | number,
  arg1: string | number
): string | number => {
  return arg0 + arg1; // error
};
```

Although I want to just concatnate parameters when it is `string`, but typescript compiler wouldn't let me do it.

Simply double check type inside function....

```ts
const combine = (
  arg0: string | number,
  arg1: string | number
): string | number => {
  if (typeof arg0 === "number" && typeof arg1 === "number") {
    return arg0 + arg1;
  }

  return `${arg0}${arg1}`;
};
```

will do

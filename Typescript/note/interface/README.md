# interface

```ts
interface Obj {
  name: string;
  age: number;
  [key: string]: string | number;
}

const obj0: Obj = {
  name: "Kim",
  age: 12,
  prop0: "bar",
  prop1: 123,
  prop2: true, // compile error
  prop3: [123, 123], // compile error
};
```

Interface is a blueprint of object.

`[key: string]: string | number` enables such object can hold infinite count of _key_ with value type of _string_ and _number_.  
So while `prop2`, `prop3` is not a given type, typescript would yield a compile error.

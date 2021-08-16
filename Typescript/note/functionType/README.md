# Function type

```ts
let someFunction: Function;
```

We can set variable `someFunction`'s type as function by setting type `Function`

But what is there are more than one function whom are different in prototype such as...

<br/>

```ts
const foo = (arg0: number, arg1: number): number => {
  return arg0 + arg1;
};

const bar = (arg: string): string => {
  return `arg: ${arg}`;
};
```

If our intention was to assign `foo` to `someFunction`, typescript can't throw an error if we assign `bar`.

<br/>
   
``` ts
let someFunction: (arg0: number, arg1: number) => number;
```
We can solve problem by explicitly define a prototype of function variable with specific function type as `(...argType) => returnType`

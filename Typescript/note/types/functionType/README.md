# Function type

## Basic concept of function type

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

## Callback and void return type

```ts
const func = (arg: number): void => {
  return arg; //Compile error. number can't be assigned to `void`
};
```

Reason for this code is clear: _mismatch with return type and returning value_

But what about callback functoin?

<br/>

```ts
const func = (arg: number, cb:(arg: number) => void): number {
  ///
  return arg;
}

func(3, (a) => {
  return a; // Would this be an error?
})
```

Such function `func` has call back function for second parameter whose return type is `void`. But what if I call `func` with **call back function which is returning that is not void?**

The answer is **typescript would not throw an error** because declaring `func` with its second call back function's return type as void is nothing more than explicitly showing that **return value from second callback will not be used inside this function.**

So calling `func` with call back function which returning `number` is still fine, and doing something meaningful inside `func` with those return value is still fine(in that case return type of `cb` in `func` has to be changed from `void` to other type)

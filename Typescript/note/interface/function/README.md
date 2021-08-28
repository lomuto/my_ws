# function with interface

interface is used to define the structer of an object. And **function is an object** in javascript. That means we can defin e a structure(signature) of function with interface.

```ts
interface Func {
  (param0: number, param1: string): string;
}

const func0: Func = (a: number, b: string) => {
  return `${a}, ${b}`;
};
```

set the type of parameters in parenthess and define a return type next to upcoming semi colon `:`

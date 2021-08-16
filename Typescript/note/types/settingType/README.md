# Setting types

## Union type

```ts
const Foo = (arg: string | number) => {
  return arg;
};
```

parameter in function `Foo` can take `string` or `number`.

## String Literal

```ts
const AddOrConcat = <T>(arg1: T, num2: T): T => {
  return arg1 + arg2;
};
```

Such function above seems legal. but **it throws an Error**  
Inoreder to set a function that works as I wanted...

```ts
const AddOrConcat = (
  arg1: number | string,
  arg2: number | string
): number | string => {
  if (typeof arg1 === `number` && typeof arg2 === `number`)
    return Number(arg1) + Number(arg2);
  else if (typeof arg1 === `string` && typeof arg2 === `string`)
    return String(arg1) + String(arg2);
  // `arg1 + arg2` is still good
  else return new Error(`Incompatible arguments`);
};
```

If those `if` statement feels so tired, it can be fixed by another parameter

```ts
const AddOrConcat = (
  arg1: number | string,
  arg2: number | string,
  checkType: string
): number | string => {
  if (checkType === `isString`) return String(arg1) + String(arg2);
  else if (checkType === `isNumber`) return Number(arg1) + Number(arg2);
};
```

What if we pass `checkType` parameter as _isstring_ with typo of _s_?  
To avoid such mistake, we can **explicitely announce variable with string literal**

```ts
const AddOrConcat = (
  arg1: number | string,
  arg2: number | string,
  checkType: `isString` | `isNumber`
): number | string => {
  if (checkType === `isString`) return String(arg1) + String(arg2);
  else if (checkType === `isNumber`) return Number(arg1) + Number(arg2);
};
```

Setting `checkType`'s type as `isString | isNumber`, third argument of `AddOrConcat` will explicitly show only two option as `isString` or `isNumber`

## Type Aliases

```ts
type numOrStr = number | string;

const AddOrConcat = (
  arg1: numOrStr,
  arg2: numOrStr,
  checkType: `isString` | `isNumber`
): numOrStr => {
  if (checkType === `isString`) return String(arg1) + String(arg2);
  else if (checkType === `isNumber`) return Number(arg1) + Number(arg2);
};
```

Doing `type foo = number`, we can explicitly set `foo` as type `number`.

Type can be alos union like `type foo = number|string`

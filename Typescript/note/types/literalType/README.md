# Literal type

Suppose you are passing a parameter to a function but you want to **enforce user to passing stricted value that you have pre defined**

This is where `literal type` came in.

```ts
const foo = (arg: 1 | 'good') {
    //
}
```

Now calling function `foo` would only be restricted with parameter number `1` or string `'good'`

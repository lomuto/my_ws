# Rest Parameters

If your function want to take multiple parameters and you have no idea how many of them will be(just like a `printf` function) here is a solution for it.

```js
const func = (...args) => {
  args.forEach(e, (i) => {
    console.log(`arg ${i}: ${e}`);
  });
};
```

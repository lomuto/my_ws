# Default Function parameter

```js
const func = (a, b = 3) => {
  console.log(`a: ${a}, b: ${b}`);
};

func(5); // a: 5, b=3
```

We can set a default function parameter by `=` operator inside parameter of function initialzation.

But make sure that **Default setted parameter is the last parameter of function.**

Such case that

```js
const func = (a = 5, b) => {
  console.log(`a: ${a}, b: ${b}`);
};

func(5); // error
```

You might expect param `b` to `5`, but js runtime will pass `5` to `a` and void for `b`.  
Keep this in mind...

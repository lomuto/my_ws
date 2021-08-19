# Anonymous function and Arrow function

- anonymous function can be abbreviated as arrow function
- bracket {} and return can be omitted when anonymous function has only statement with return
- bracket () for parameter can be omitted when anonymous function has only one param

In conclusion...

```javascript
foo(function (arg) {
  return ++arg;
});

// it can be abbreviated to
foo(arg => ++arg);
```

- when anonymous function has only one parameter and return statement comes with a function thas has only one argument as callBack function's parameter, callBack function's parameter can be abbreviated as that function's name  


In conclusion...

```javascript
foo(arg => bar(arg));

// it can be abbreviated to
foo(bar);
```

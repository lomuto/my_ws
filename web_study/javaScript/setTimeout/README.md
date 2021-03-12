# Trouble Shooting in callback func

```javascript
async function foo() {
  setTimeout(() => {
    return `hello from foo`;
  }, 2000);
}
```

what I intended: function foo returns certain literal to resolve after 2sec.
code seems no problem.  
but **But it retrns literal to setTimeout() not to Promise object**

correct:

```javascript
function foo() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(`Hello from foo`);
    }, 2000);
  });
}
```

Eventhough resolve statement is inside of setTimeout(),
return val goes to Promise obj through resolve()  
so it will work as i intended

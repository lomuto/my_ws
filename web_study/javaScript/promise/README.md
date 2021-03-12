# Promise and Promise Chain
   
### I'm not sure till when it ends, but I *Promise* that I will let you know when it ends
   
Promise is an object that used to handling an asynchronous event   
It waits untill the task of Promise object ends.   
   
```javascript
function foo(){
  return new Promise((res,rej)=>{
    setTimeout(()=>{
      res(`Task ends!`);
    },2000)
  })
}

foo()//
  .then(console.log);
  
console.log(`Message after foo() ends`);
```   
   
Despite of single thread-ed JS engine,   
`foo().then(console.log)` halted till `resolve` return its value

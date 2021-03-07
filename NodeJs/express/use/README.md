# What is use?

```js
const express = require(`express`);

const app = express();

app.get(`/`,(req,res)=>{
    ...
});

app.use(`/`,(req,res)=>{
    ...
});
```

We frequently see those `get` and `use` in express code.  
**What is the difference between them?**

Answer is simple.  
`get` is for REST API's get (REST API -> get,post,put,delete...) and **use covers all them up.**

If I done `app.get('/',(req,res)=> res.send('hello'))`  
response of _hello_ is only available in `get` method.

While `app.use('/',(req,res)=>res.send('Hello'))` is responses _hello_ to every request to root dir `/` by no matter what method it called.

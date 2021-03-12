# middleware

There are two middleware which is...

1. Function bwtween router

```js
const between = (req, res, next) => {
  console.log(`I'm middleware`);
  next();
};

app.get(`/`, between, (req, res)=>{
    ...
})
```

</br>

2. `app.use`

```js
app.use((req, res, next) => {
  console.log(`Hello from middleware`);
  next();
});
```

</br></br></br>

```js
import express from "express";

const app = express();

app.use((req, res, next) => {
  // first middle ware

  req.sth = `from first middleware`;
  next();
});

app.use((req, res, next) => {
  // second middle ware

  console.log(`${req.sth}`); // print `from first middleware` in console
});
```

`next()` in use method concatnate middlewares  
By `app.use((req,res)=>{})` its adding that arrow function that **Every server passes by**  
</br></br></br>

```js
app.get(
  `/`,
  (req, res, next) => {
    console.log(`This is middleware`);
    next();
  },
  (req, res) => {
    res.end(`hello`);
  }
);
```

middleware could be used as code above.

In get request from `/` url (`/` route),  
this takes two steps of function which two of them are concatnated with `next()`  
**Without next(), response of router will end at middleware (for this code its middleware has no response... so) webpage will kept loading**
</br></br></br>

```js
const express = require(`express`);
const app = express();

// app.use comes first than get req
app.use((req, res, next) => {
  console.log(`middleware comming through!`);
  next();
});

app.get(`/`, (req, res) => {
  res.send(`hello world!`);
});

app.get(`/hello`, (req, res) => {
  res.send(`route hellow`);
});

const PORT = 5555;
app.listen(PORT, () => {
  console.log(`Server listening to ${PORT}`);
});
```

**Adding a middle ware must be prioritized than setting a normal request**  
Requesting to every server route will go through `app.use(...)` so leave a console.log(`middleware comming through!`);</br></br></br>

```js
app.get(`/`, (req, res) => {
  res.send(`hello world!`);
});

app.use((req, res, next) => {
  console.log(`middleware comming through!`);
  next();
});

app.get(`/hello`, (req, res) => {
  res.send(`route hellow`);
});
```

Add a middleware like this would **make middleware only available at `/hello` route.** _(`/` route request will end before reach `app.use`)_

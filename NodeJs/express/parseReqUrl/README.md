# Parse url

```javascript
app.use((req, res) => {
  const queryVar = req.query.name;
  console.log(queryVar); // `localhost:5000?name=kang` will return kang
});

http.createServer(app).listen(5000);
```

parse queryString from `get` method

`req.body.key` for `post`

`req.body.key || req.query.key` for not sure whether `get` or `post`

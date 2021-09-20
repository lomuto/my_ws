# req param vs query

```
https://localhost:3000/john/18?id=god
```

For given url with such endpoint

```ts
app.get("/:name/:age", (req, res) => {
  const { name, age } = req.params;
  console.log(name); // john, 18
  console.log(age); // 18

  const { id } = req.query;
  console.log(id); // god
});
```

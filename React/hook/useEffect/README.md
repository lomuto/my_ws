# Useeffect

`useEffect` is related with component's life cycle.

```js
const App = () => {
  useEffect(() => {
    alert("Conponent created!");
  });
};
```

When component `App` has created, it will execute function in first parameter of `useEffect`.

---

```js
const App = () => {
  useEffect(() => {
    alert("Conponent created!");

    return () => {
      alert("good bye component!");
    };
  });
};
```

return a certain function in `useEffect`, it will be executed when component has diminished.

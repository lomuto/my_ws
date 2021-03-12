# enum

enum = _enumerate_

```ts
enum Foo {
  ADMIN,
  AUTHOR,
  USER,
}
```

for such code, when it compiled to JS code it will be...

```ts
var Foo;
(function (Foo) {
  Foo[(Foo["ADMIN"] = 0)] = "ADMIN";
  Foo[(Foo["AUTHOR"] = 1)] = "AUTHOR";
  Foo[(Foo["USER"] = 2)] = "USER";
})(Foo || (Foo = {}));
```

Its hard to understand, but to be short,  
**Foo.ADMIN === 0** and **Foo[0] === ADMIN**

---

```ts
enum Foo {
  ADMIN = 1,
  AUTHOR,
  USER,
}
```

Assigning **1** to `ADMIN` will set `AUTHOR` and `USER` as **2** and **3** (automatically incremented number)

```ts
enum Foo {
  ADMIN = 2,
  AUTHOR = 100,
  USER,
}
```

For this case, `USER` is **101**

---

### Reverse Mapping?

```ts
enum Foo {
  ADMIN = "administrator",
  AUTHOR = "authorizeduser",
  USER = "justuser",
}
```

`Foo.ADMIN` will return `administrator` but **not in viceversa**.  
Approaching `Foo` with "administrator" is impossible

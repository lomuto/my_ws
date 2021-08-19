## Object

```js
class Foo {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }
}

const bar = new Foo(`yun`, 25);

const { name, age } = bar;
```

By doing that, `name` and `age` stands for property in `bar`.<br/>  
So `console.log(name,age)` will be _yun 25_<br/>

Inorder to set name and age as different name,

```js
const { name: n, age: a } = bar;
```

It will set `n` and `a` as `name`,`age` property
</br></br>
How about in case such read data from `req.body`?

If we want to get data called `name` and `age` from post request,

```js
const = {
  body:{
    name,
    age
  }
} = req;
```

This will do.

  <br/>

## Array

```js
const arr0 = [1, 2];
const [e0, e1] = arr0;
```

Destructuring array is as same as object.

One fanct part is...

```js
const arr0 [1,2,3,4,5,6];
const [e, ...remain] = arr0;
```

variable `e` is assigned `1` while `remain` has assigned as array in element of `2,3,4,5,6`

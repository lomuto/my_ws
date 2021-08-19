# Object Destruction

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

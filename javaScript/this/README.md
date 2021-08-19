# this

```js
class Foo {
  constructor(member) {
    this.member = member;
  }

  printMember() {
    console.log(this.member);
  }
}
```

Lets say that we have class `Foo` with member `member` and method `printMethod` which prints `member`

<br/>

```js
const instFoo = new Foo("hello");

instFoo.printMember(); // hello

const bar = { printMember: instFoo.printMember };

bar.printMember(); // undefined
```

If we call method `printMember`, it will print `hello` on console.

But if we creates new object `bar` and call `printMember` it will print `undefined`. This happens because **`printMember` tries to find `member` inside `bar`** which doesn't exists.

<br/>

```js
class Foo {
  constructor(member) {
    this.member = member;
  }

  printMember = () => {
    console.log(this.member);
  };
}
```

In this case, `bar` will print `hello` because `printMember` is **referencing the statically initialized** fucntion which `this.member` will bind as memory address of instance of `Foo`

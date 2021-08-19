# Function is Object   
   
![proto.png](./proto.png)
   
```js
const smile = {};
```   
For a statement above, JS turns it into   
```js
const smile = new Object();
```    
   
Same as   
```js
const name = "yun"  // const name = new String(`yun`);
const ret = true    // const ret = new Boolean(true);
```
   
---

```js
const imObj = {
    name:"obj",
    say:"Hello"
}
```   
   
For such object `imObj`   
`imObj.constructor` will return *ƒ Object() { [native code] }* which means `imObj` is constructed by function `Object()`   
   
How about function??   
   
```js
function foo(){
    this.name = 3;
}

console.log(foo.constructor)    // ƒ Function() { [native code] }
```   
   
function has a constructor **just like the object**   
   
When `function foo()` created, prototype of `foo` (which is `foo.prototype` Object) also creates. And these two are linked as pointing each other, followed by...   
- `function foo()` has property of `prototype` which is referencing to `foo.prototype` object.   
- `foo.prototype` object has two property. One is named `constructor` which is referencing to `function foo()` and the other is `__proto__`   
   
To be simple,   
- **Object is derived from another Object. Object.__proto__ reference its parent Object** 
   
```js
function foo(a){
    this.content = a;
}
// prototype object of foo created.
// can be referenced by foo.prototype

const bar = new foo(3);
// bar.constructor === foo
// bar.__proto__ === foo.prototype

foo.prototype.name = "yun";
console.log(bar.name);
```   
   
What happen if code runs?   
**Astonishingly `bar.name` returns "yun"**   
   
As `__proto__` references its constructor's prototype,   
If property 'name' called by 'bar' as `bar.name`...
1. Search `name` property in `bar` object.
2. There is no `name` property, so go up to its derived Object using `__proto__` to search for `name`   
   
So that's what happen.   
   
What if `name` property doesn't exists in `bar.__proto__`?   
**Then it will go up again with `__proto__` property,  same as `foo.prototye.__proto__`, which is also `bar.__proto__.__proto__`**   

Then it eventually meet the very ancestor Object that constructed by `Object` function.   
This prototype object constructed by `function Object()` also has `__proto__` but it references **null**
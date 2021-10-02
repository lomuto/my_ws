# Array as StringBuilder

Technically, javascript doesn't support such class like stringbuilder, but it can be implemented easily with basic array in javascript.

Before start the main stuff, just to check the main concept of stringbuilder is that...

```javascript
const str = "";
str += "hello";
str += "my name is";
```

this would consume huge amount of memory for every each string object. So using stringbuilder, can save those extra memory for allocation.

```javascript
const buffer = [];
buffer.push("hello");
buffer.push("my name is");
const str = buffer.join("");
```

This would concatnate every single element in array with parameter in `join` method as delimiter.

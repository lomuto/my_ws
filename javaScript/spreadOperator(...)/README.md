# Spread operator (...)

```js
const arr0 = ["a", "r", "r", "a", "y"];
```

If I want to **deep** copy such array `arr0` to `arr1`

```js
const arr1 = arr0; // shallow copy
```

This of course not work cause its shallow copy.

<br/>   
   
```javascript
const arr1 = [arr[0], arr[1], arr[2], arr[3], arr[4]];
```   
This could work, but if size of `arr1` is large, then it would also impossible.   
   
<br/>   
   
```javascript
const arr1 = [];
app0.forEach(e => {
    app1.push(e);
});
```   
this is great, but hard to read
   
<br/>   
   
### Spread operator   
   
```js
const arr1 = [...arr0];
```   
Such `forEach` statement above could be written in neat way using spread operator.
   
<br/>      
   
### Spread operator in object   
   
Spread operator is also useful in deep coping object.   
   
``` js
const person0 = {
    name: 'yun',
    age: 18
};

const person1 = { ...person0 };

person0.name = 'kang';

console.log(person0); // yun, 18
console.log(person1); // kang, 18

```
You can see the `person1` has deep copied.

```

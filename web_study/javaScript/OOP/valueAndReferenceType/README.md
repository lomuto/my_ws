# Value type and Reference type   
   
- value type: Number, String, Boolean, Undefined, Null   
- reference type: Object, Function, Array

```js
let x = 10;
let y = x;      // call by value

x = 20;

console.log(`x is ${x} and y is ${y}`);
```
   
Output will be *x is 20 and y is 10*   
   
---

```js
let objX = {value:10};
let objY = objX;        // call by reference

objX.value = 20;


console.log(`value of objX is ${objX.value} and value of objY is ${objY.value}`);
```   
   
Output will be *value of objX is 20 abnd value of objY is 20*   
   

---   
   
   
```js
let number = 0;

function increase(arg){
    arg++;
    return;
}

increase(number)
console.log(number) // print 0. not 1




let obj = {value:0};

function increase(arg){
    arg.value++;
    return;
}

increase(obj);
console.log(obj)    // print 1
```   
   
Basically **function in javascript takes argument as call-by-value**   
   
But when argument is `Reference type`, its adress passed by
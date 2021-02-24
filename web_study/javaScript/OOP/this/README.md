# What is THIS?   
   
`this` is determined when a function is called   
When `this` called in browser, it will points to `window` object, which is global object in browser.   
In case of `nodeJs`, calling in outmost scope will points to `module.export` and calling in function would be `global` object.   
   
Basically JS doesn't have **Class**   
but it pretends to be like it had by **Factory funtion** and **Constructor function**   
   
Factory function is a function that just returns an object literal   
```js
function createCircle(radius){
    return {
        radius,  // radius = radius can be abbreviated to just a single word (es6 feature)
        draw : ()=>{
            console.log(`draw`);
        }
    }
}
```   
   
While Constructor function is a bit more *Claass-like* that takes **Upper Case letter** as first character of function's name

```js
function Circle(radius){
    this.radius = radius;
    this.draw = ()=>{
        console.log(`draw`);
    }
}   

const foo = Circle(2);
foo.draw();  // undefined error
```   
     
For code above, executing `foo.draw()` seems to work as printing `draw`    
but it turns out that it returns an error of undefined.   
**Because function `Circle` is just adding a `radius` property and `draw` method to `global object`**   
   
Inorder to make it work as expected for first time, using **new** OPERATOR would do   
   
Sequence of `new` operator would be   
1. Make an empty object    
2. Make `this` point to its empty object that just created  
3. Execute `this.foo` statement to add member in object
4. return `this` object   
   
Hence, inorder to use `foo` as object,   
`const foo = new Circle(2)` would do.
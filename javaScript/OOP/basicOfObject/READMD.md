# Basic concept of method   
   
```js
const circle={
    radius:3,
    location:{
        x:1.
        y:2
    },
    draw:()=>{
        console.log(`draw`);
    }
}
```   
   
Let's check fundemental of OBJECT.   
   
First, circle is a **Literal Object** just like the string literal.   
Initialized with its declaration. (Different with `class circle={};`)   
   
Object is basically consisted with **key** and **value**   
Syntax of key and value would be `key:value` as colon(`:`) to delimiter.  
   
`radius`,`location`,`draw` are all **Member** of Object   
   
These memeber have unique name for its state.   
Such **method** for function member and **property** for variable.   
   
So `radius` and `location` are **property**    
and `draw` is a **method**
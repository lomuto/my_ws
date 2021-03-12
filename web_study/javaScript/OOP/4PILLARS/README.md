# 4 Pillars of OOP   
   
1. Encapsulation (캡슐화)   
   
```js
// Procedual Programming
let baseSalary = 300;
let overtime = 10;
let rate = 20;

function getWage(baseSalary,overtime,rate){
    return baseSalary + ( overtime * rate );
}


// Object_Oriented Programming
const employee = {
    let baseSalary : 300,
    let overtime : 10,
    let rate : 20,
    getWage : ()=>{
        return this.baseSalary + (this.overtime * this.rate);
    }
}
```   
   
Same `getWage` function but **No parameters!**   
Function with fewer parameters are easy to use and maintain   
   
**Reduce Complexity, Increase reuseability**
   
---

2. Abstraction (추상화)   
   
When we buy a Phone, only thing that we have to know is on/off and sound button. We don't have to know how it works inside.   
It works same as code. When it comes with OOP, **function's interface got simpler**   
Also when someone modifies the method (which is in public instad of private) **the impact of change reduces**
   
**Reduce Complexity, Isolate impact of change**

---
   
3. Inheritance (상속)   
   
When it comes with situation such making to-do list, its hard to set every action for each list   
Thanks to inheritance, it can be done by just adding a eventlistener to inheritanced DOM element.
   
**Eliminate redundant code**

---

4. Polymorphism (다형성?)   
   
*Poly*: Many   
*Morph*: Form   
Hence.. it has meaning such `Many Forms`   
   
Simillar code, but different action   
You don't have to use code like...
```js
switch(foo){
    case `select`: rendSelect();
    case `text`: rendText();
    case `checkbox`: rendcheckbox();
    ...
}
```   
   
**Refactor ugly switch/case statement**
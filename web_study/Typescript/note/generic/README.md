# Generic   
   
Usually `<>` bracket uses to...   
```ts
const arr:number[] = [1,2,3];
const numArr:Array<number> = arr;
```   
Basically, `type[] === Array<type>`   
this is where `<>` uses...  
   
---

```ts
const returnArr = (arg:any):any=>{
    return arg;
}

const numArr:number[] = returnArr([1,2,3]); //  This is llegal
const strArr:Array<string> = returnArr([1,2,3]);    //This is illegal but TS won't recognize! 
```    
   
Setting type as `any` could casue such problem above.   
That's why we need `generic`   
   
```ts
const returnArr = <T>(arg: T): T=>{
    return arg;
}

const numArr:number[] = returnArr([1,2,3]);
const numArr:string[] = returnArr([1,2,3]);     // ERROR!
```   
   
As seting `generic` to explicitely, TS recognize that `returnArr([1,2,3])`'s return type is number and say it's ERROR   
   
---   
   
```ts
const Foo = (arg:{name:string, age:number}):string => {
    return arg.name;
}
```   
This can be written more clearely with `interface`   
```ts
interface Human{
    name:string;
    age:number;
}

const Foo = (arg:Human):string=>{
    return arg.name;
}
```   
or   
```ts
class Person{
    public name:string;
    public age:number;

    constructor(name:string, age:number){
        this.name = name;
        this.age = age;
    }
}

const Foo = (arg:Person):string=>{
    return arg.name;
}
```   
   
When class is extended but we are not sure what that class' member is exactely, we use `<T extends sth>`    

```ts
class Person{
    public name:string;
    public age:number;

    constructor(name:string, age:number){
        this.name = name;
        this.age = age;
    }
}

class Student extends Person{
    private score: number;

    constructor(name:string, age: number, score: number){
        super(name, age);
        this.score = score;
    }
}

...

const foo = <T extends Person>(arg:T):string=>{
    return arg.name;
}
```    
    
By using `<T extends Person>` we can set parameter as some random object **but extended from Person class**
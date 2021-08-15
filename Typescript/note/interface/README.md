# Interface   
   
```ts
const showPerson = (name: string, age: number, gender: string):string=>{
    return `My name is ${name} and i'm ${age} years old, and i'm ${gender}`;
}
```   
   
For such function that takes (`string`,`number`,`string`) as parameter and returns string,   
its quiet annoing to pass all those three argument....   
It can be done easily by passing an *object*   
There is one step before pass *object* as a parameter   
   
```ts
interface Human{
    name:string;
    age:number;
    male:string;
}

const showPerson = (person:Human):string=>{
    return `My name is ${person.name} and i'm ${person.age} years old, and i'm ${person.gender}`;
}
```   
   
By setting an *interface* which set the type of property of object to hand over by parameter,   
*object* can be handed over as argument.   
   
```ts
const Me={
    name:`yun`,
    age:25,
    gender:`male`
}

showPerson(Me);
```
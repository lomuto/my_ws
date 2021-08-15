# Class in typescript   
   
Class in typescript is basically same as javaScript   
   
```ts
class Human{
    public name:string;
    public age:number;
    public gender:string;
    constructor(name:string, age:number, gender?:string){
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
}

const yun:Human = new Human("Yun",25,"male");
```   
   
Every member in typescript calss can set its security as `public` or `private` keyword   
And as it can be seen in parameters in `constructor`, setting gender parameter as `gender?:string` means gender param is string but *optional*   
Don't forget to specify the type of new class const too! `const yun:Human`
# Inherit   
   
```js
class Foo{
    constructor(name,age){
        this.name = name;
        this.age = age;
    }
}

class Bar extends Foo{
    constructor(name,age,adress){
        super(name,age);
        this.adress = adress;
    }
}
```   
   
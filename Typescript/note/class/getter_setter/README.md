# Getter Setter

```ts
class Person {
  public name: string;
  private _age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }

  get age(): number {
    return this._age;
  }

  set age(value: number) {
    if (value < 0) throw new Error(`Age must be larger than 0`);

    this._age = value;
  }
}

const p0: Person = new Person("Kim", 23);
p0.age = 20; // p0.setAge(20);
console.log(p0.age); //  p0.getAge();
```

`set` and `get` keyword in typescript implicitly helps programmer to get or set property without calling `getProp()` or `setProp()` method with `()` operator.

It is just a feature that javascript & typecript provides, so not sure wheteher it is best pracice to use `get` and `set` keyword to make getter & setter instead of explicit method `getProp` and `setProp`

Extending `Person` method will be...

```ts
class Student extends Person {
  private _height: number;

  constructor(name: string, age: number, height: number) {
    super(name, age);
    this.height = height;
  }

  get height(): number {
    return this._height;
  }

  set height(value: number) {
    if (value < 0) throw new Error(`Height must be larger than 0`);

    this._height = value;
  }
}
```

- Entended class' constructor arguments are passed by `super`. **Just passes the argument's name will do**  


```ts
class Foo {
  public firstName: string;
  public lastName: string;

  constructor(first, last) {
    this.firstName = first;
    this.lastName = last;
  }

  get fullName(): string {
    return `${this.firstName} ${this.lastName}`;
  }

  set fullName(value: string) {
    const name = value.split(` `);

    this.firstName = name[0];
    this.lastName = name[1];
  }
}

const person = new Foo(`Kim`, `Case`);

console.log(person.fullName);

person.fullName = `Yunseok Kang`;

console.log(`First is ${person.firstName}, Last is ${person.lastName}`);
```

Calling `person.fullName` will return `firstName` and `lastName` property

Signing a string to `person.fullName` will replace its `firstName` and `lastName` property

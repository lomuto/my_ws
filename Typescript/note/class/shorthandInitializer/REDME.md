# Shorhthand Initializer

This is just a mark up for feature in typescript. **Which is not recommended**

<br/>

```ts
class Person {
  private name: string;
  private age: number;
  private height: number;

  constructor(name: string, age: number, height: number) {
    this.name = name;
    this.age = age;
    this.height = height;
  }
}
```

Given class `Person` someone might feel exhasuted to declare member and initialize it in constructor again. It might be painful if there are dozens of members.

```ts
class Person {
  constructor(
    private name: string,
    private age: number,
    private height: number
  ) {}
}
```

Declaration and Initialization can be abbreviated with constructor's parameter with access modifier.

# super

```ts
class Department {
    constructor(
        private name: string,
        private floor: number;
    ){};

    ...
};
```

If I want to build an IT Department from `Department` class, we can use inherit.

```ts
class ITDepartment extends Department {
  constructor(name: string, floor: number, private admin: string) {
    super(name, floor);
  }
}

const it0 = new ITDepartment("it0", 12, "adminOfIt0");
```

By making `constructor` with given parameters,  
first pass the parent's class property with `super` method and then modify the property of current class.

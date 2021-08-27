# Abstract class

_Polymorphism_ is a one of main feature in _OOP_.  
In typescript we can implement such attribute by abstract class.

```ts
abstract class Job {
  constructor(private _name: string, private _celery: number) {}

  get name() {
    return this._name;
  }

  get celery() {
    return this._celery;
  }

  abstract describeJob(): void;
}
```

Unlike the other method in `Job` class, abstract function `describeJob` comes with keyword `abstract` followed by function's parameter and return type.  
**abstract method can only be exist inside abstract class** so be sure to add `abstract` keyword in front of class name too.

<br/>

```ts
class Teacher extends Job {
  constructor(name: string, celery: number) {
    super(name, celery);
  }

  describeJob() {
    console.log("This job teaches students");
  }
}

class Programmer extends Job {
  constructor(name: string, celery: number) {
    super(name, celery);
  }

  describeJob() {
    console.log("This job writes code");
  }
}
```

Both `Teacher` and `Programmer` classes inherits abstract class `Job`. If neither of them didn't implement abstract method `describeJob`, it would yeild a compile error.

<br/>

```ts
const teacher = new Teacher("teacher", 100);
const programmer = new Programmer("programmer", 200);

const jobs: Job[] = [];
jobs.push(teacher);
jobs.push(programmer);

jobs.forEach((e) => e.describeJob());
```

Array `jobs` of element type `Job` can hold both `teacher` and `programmer` instances which both of them are inherited from class `Job`.

Calling `describeJob` method by `forEach` statement from `jobs` is also available.

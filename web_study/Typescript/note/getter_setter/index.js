class Person {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }
    get age() {
        return this._age;
    }
    set age(value) {
        if (value < 0) {
            throw new Error(`Age can't be minus`);
        }
        this._age = value;
    }
}
class Student extends Person {
    constructor(name, age, height) {
        super(name, age);
        this.height = height;
    }
    get height() {
        return this._height;
    }
    set height(value) {
        if (value < 0) {
            throw new Error(`Height must be bigger than 0`);
        }
        this._height = value;
    }
}
const kang = new Person(`Yun`, 25);
console.log(`kang's name is ${kang.name} and age is ${kang.age}`);
const oh = new Student(`na`, 10, 170);
console.log(`${oh.name}, ${oh.age}, ${oh.height}`);

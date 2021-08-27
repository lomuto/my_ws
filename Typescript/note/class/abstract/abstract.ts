abstract class Job {
    constructor(
        private _name: string,
        private _celery: number
    ){}

    get name() {
        return this._name;
    };

    get celery() {
        return this._celery;
    }

    abstract describeJob(): void;
};

class Teacher extends Job{
    constructor(
        name: string,
        celery: number
    ) {
        super(name, celery);
    };

    describeJob() {
        console.log('This job teaches students');
    }
};

class Programmer extends Job {
    constructor(
        name: string,
        celery: number
    ) {
        super(name, celery);
    };

    describeJob() {
        console.log('This job writes code');
    }
};

const teacher = new Teacher('teacher', 100);
const programmer = new Programmer('programmer', 200);

const jobs: Job[] = [];
jobs.push(teacher);
jobs.push(programmer);

jobs.forEach(e => e.describeJob());
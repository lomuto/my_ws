# async await

```C
if(!fork())
    return 3;

int* stat_loc;
wait(&stat_loc);
```

By using `fork()` system call function in C,
parallel process runs and child process' ret value can be reaped by wait()

same for async and await

```javascript
const sth = ?;//

async function foo(){
    if(sth === ?)
        return `this is resolve`;
    else
        throw `this is reject`;
}

async function bar(){               // await only can be used in async function
    const fooResult = await foo(); // JS thread stops unstill foo() returns its value
    try{
        console.log(fooResult);
    }
    catch(err){
        console.log(err);
    }
}

bar();
```

- return in async function is param of resolve in Promise obj
- throw is reject in Promise obj
- await is only available in async funtion
- while JS is single threaded process, await guarantees async safe. wait untill await func to be finished
- when error throwed in try{}, it immediately goes to catch() parameter

// Wrong Code.
// return goes to setTimeout. not foo or bar
//
// async function foo(){
//     setTimeout(()=>{
//         return `foo`
//     },2000)

// }

// async function bar(){
//     setTimeout(()=>{
//         return `bar`
//     },1000)
// }

function foo(){
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve(`hello from foo`);
        },2000)
    })
 }
 
 function bar(){
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve(`hello from bar`);
        },1000)
    })
 }
 
 async function res(){
    const fooResult = await foo();
    const barResult = await bar();
 
    return `${fooResult} ${barResult}`;
 }
 
 res().then(console.log);
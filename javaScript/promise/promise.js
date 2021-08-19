`use strict`

const num = prompt(`Enter number`);

const prom = new Promise((resolve, reject)=>{
    if(num > 10)
        resolve(`num is higher than 10`);
    else
        reject(`num is lower then 10`);
});

prom //
    .then((value)=>{console.log(value)})    // executed followed by resolve()
    .catch(console.log)                     // executed followed by rejec()
    .final(console.log(`promise fin`));     // executed whenever prom chain finished
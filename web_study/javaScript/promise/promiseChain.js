`use strict`

const result = prompt(`choose number\n1.friedChicken\n2.sunnySideup`);
if(result === `1`)
    var branch = prompt(`choose number\n1.live\n2.friedChicken`); // error occured when use `const` instead of `var`

const egg = new Promise((resolve,reject)=>{
    if(result === `1`)
        resolve(`🥚`); 
    else if(result === `2`)
        reject(`🥚 => 🍳`);
});

const babyChick = new Promise((resolve, reject)=>{
    if(result === `1`)
        resolve(`=>🐤`);
});

const rooster = new Promise((resolve,reject)=>{
    if(branch === `1`)
        resolve(`=>🐓`);
    else if(branch === `2`)
        reject(`=>🍗`);
});


egg //
    .then((egg)=>{
        babyChick.then((babyChick)=>{
            rooster//
                .then((friedChicken)=>{
                    console.log(`${egg}${babyChick}${friedChicken}`);
                })
                .catch((live)=>{
                    console.log(`${egg}${babyChick}${live}`);
                })
        })
    })
    .catch(console.log);
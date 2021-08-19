`use strict`

// class UserStorage{

//   logIn(id,pwd){
//        return new Promise((resolve,reject)=>{
//           setTimeout(()=>{
//             if( (id === `yun` && pwd === `123`) || (id === `hel` && pwd ===`123`))
//                resolve(id);
//             else
//                reject(`inValidated User`);
//           },2000)
//        })
//    }

//    getRoles(id){
//          return new Promise((resolve,reject)=>{
//             setTimeout(()=>{
//                if(id === `yun`)
//                   resolve({name:`yun`,role:`admin`});
//                else 
//                   reject(`no access`);
//             },1000)
//          })
//    }
// }

// const user = new UserStorage();
// const id = prompt(`Enter ID: `);
// const pwd = prompt(`Enter pwd: `);


// async function USER(id,pwd){
//    try{
//       const userId = await user.logIn(id,pwd)
//       console.log(`userId received`);
//       const userRole = await user.getRoles(userId)
//       console.log(`userRole received`);

//       console.log(userRole);
//    }
//    catch(err){
//       console.log(err);
//    }
// }


// USER(id,pwd);

class UserStorage{
    constructor(id, pwd) {
        this.id = id;
        this.pwd = pwd;
    }
    logIn(){
        return new Promise((resolve,reject)=>{
            setTimeout(() => {
                if( (this.id === `yun` && this.pwd === `123`) || (this.id === `hel` && this.pwd ===`123`))
                    resolve(id);
                else
                    reject(`inValidated User`);
            },2000)
        })
    }

    getRoles(){
        return new Promise((resolve,reject) => {
            setTimeout(()=>{
                if(this.id === `yun`)
                    resolve({name:`yun`, role:`admin`});
                else 
                    reject(`no access`);
            },1000)
        })
    }
    
    async check () {
        try{
            const userId = await this.logIn()
            console.log(`userId received`);
            const userRole = await this.getRoles()
            console.log(`userRole received`);

            console.log(`userId: ${userId}, userRole: ${userRole}`);
        }
        catch(err){
            console.log(err);
        }
    }
}

const user = new UserStorage(prompt(`Enter ID: `), prompt(`Enter pwd: `));
user.check();


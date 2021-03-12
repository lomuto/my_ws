`use strict`

class userStorage{
    checkInfo(id,pwd){
        return new Promise((resolve,reject)=>{  // return Promise object to utilize func right away
            if((id === `yun` && pwd === `123`) || (id === `guest` && pwd === `123`))
                resolve(id);
            else
                reject(new Error(`Invalidated user`));
        })
    }

    getRoles(id){
        return new Promise((resolve,reject)=>{
            if(id === `yun`)
                resolve({name:id,role:`Admin`});
            else
                reject({name:id,role:`Guest`});
        })
    }
}

const USER = new userStorage();
const ID = prompt(`Enter ID`);
const PWD = prompt(`Enter PassWord`);

USER.checkInfo(ID,PWD) //as checkInfo func return Promise obj, it can use then and catch
                    .then((userId)=>{
                        USER.getRoles(userId) //
                                        .then((userRole)=>{alert(`Hello ${userRole.name} you are ${userRole.role}`)})
                                        .catch((userRole)=>{alert(`Hello ${userRole.name} you are ${userRole.role}`)});
                    })
                    .catch(error => alert(error));
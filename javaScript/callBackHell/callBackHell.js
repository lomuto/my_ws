`use strict`

class userStorage{
    checkInfo(id,pwd,onSucess,onError){
        setTimeout(()=>{
            if((id === `yun` && pwd === `123`) || (id === `guest` && pwd === `123`))
                onSucess(id);
            else
                onError(new Error(`Invalidated user`));
        },2000)
    }

    getRoles(id,setRole){
        setTimeout(()=>{
            if(id === `yun`)
                setRole({name:id,role:`Admin`});
            else
            setRole({name:id,role:`Guest`});
        },1000)    
    }
}

const USER = new userStorage();
const ID = prompt(`Enter ID`);
const PWD = prompt(`Enter PassWord`);

// Hard to understand what this statement stands for...
// It's called callBack Hell

USER.checkInfo(
    ID,
    PWD,
    (userId) => {     // declare onSucess anonymous func instantly
        USER.getRoles(
            userId,
            (ret)=>{ 
                alert(`Hello ${ret.name}, you are ${ret.role}`);
                console.log(`${ret.role} logged in`); 
            }
            );
    },
    alert   // (error) => { alert(error) }  has abbreviated to function's name, while it has arg as param
)
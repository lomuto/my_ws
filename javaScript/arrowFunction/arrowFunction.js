`use strict`

const arr = [1,2,3];

let mappedArr = arr.map(function (value){
    return ++value;
});
console.log(mappedArr);

// anonymous function can be abbreviated as arrow function
mappedArr = arr.map((value)=>{
    return ++value;
});
console.log(mappedArr);


// return statement must be included unless it's situation is upcoming example
mappedArr = arr.map((value)=>{++value;});   // this function has no return val. so result will be undefined
console.log(mappedArr);


// bracket {}, return and semicolon ; can be omitted when anonymous function has only statement with return
mappedArr = arr.map((value)=> ++value );
console.log(mappedArr);


// bracket () for parameter can be omitted when anonymous function has only one param
mappedArr = arr.map( value => ++value );
console.log(mappedArr);


/* when anonymous function has only one parameter 
and return statement comes with a function thas has only one argument as callBack function's parameter
callBack function's parameter can be abbreviated as that function's name
*/ 
function plus(arg){
    return ++arg;
}

mappedArr = arr.map((value => plus(value)));
console.log(mappedArr);

mappedArr = arr.map(plus);
console.log(mappedArr);

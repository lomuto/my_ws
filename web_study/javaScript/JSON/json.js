`use strict`

const OBJ = {
    name: `mask`,
    age: `18`,
    height: `186`,
    eye: `brown`,
    methodD(arg){ console.log(arg) }    // method doesn't converted to JSON string
};

console.log(OBJ);

/*
// * use stringify method in JSON to convert `object -> json`
// * stringify(value: any, replacer?: (this: any, key: string, value: any) => any, space?: string | number): string;
// * takes an object to convert as first parameter and second for callBack function
// * first param for callBack func is key and second for value in object
*/
const json = JSON.stringify(OBJ,(key,value)=>{
    return key === `name` ? `Anderson` : value;
});
// Abbreviation of arrow function would be...
// const json = JSON.stringify(OBJ,(key,value)=>key === `name` ? `Anderson` : value);


console.log(json);  // check that name has turned to `Anderson` and method didn't converted to json


/*
// * use parse method in JSON to convert `json -> object`
// * simialr to stringify
// * 
*/
const obj = JSON.parse(json,(key,value) => key === `eye` ? `blue` : value);

console.log(obj);
`use strict`

const arr = [1,2,3,4,5,6];

// push and unshift method adds element in post, pre position each
arr.push(7);
arr.unshift(0);
console.log(arr);


// pop and shift method returns its post, pre positioned element each and modifies array
const poped = arr.pop();
const shifted = arr.shift();
console.log(`poped value is ${poped} and shifted vaue is ${shifted}`);
console.log(arr);


// splice method takes first param as index num of array, second param as amount of elements to slice
// slice method is similar with splice method while formal one returns modified array and latter one return sliced array
const splicied = arr.splice(2,2);
console.log(
`spliced array: ${splicied}
modified array: ${arr}`
);


// forEach method traverses array
arr.forEach((value,index)=>{
    console.log(`${index}th element is ${value}`);
});



// map method is similar with forEach method but it is much more like modifiying whole array while forEach only traverses it
const mappedArr = arr.map((value)=>{
    return ++value;
});
console.log(`mapped array: ${mappedArr}`);



// reduce(callBackFn(prev,curr){},initialValue)
// this method is shit... i'd never had chance to understand it 100%
// when initialValue is void, prev takes the first element of array, prev takes initialValue as default
const result = arr.reduce((prev,curr)=>{
    return prev+curr;
},1);
console.log(result);


// sort method.
arr.sort((a,b)=>b-a);
console.log(`Sorted as Descending order: ${arr}`);


// array to string: join or toString
// string to array: split
const string = arr.join(`,`);
console.log(string);

const Arr = string.split(`,`);
console.log(Arr);
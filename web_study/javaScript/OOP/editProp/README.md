# Add,Remove Property   
   
## Add

```js
class Foo{
    constructor(name,age){
        this.name = name;
        this.age = age;
    }
}

const foo = new Foo();
```
   
For such object `foo`, we can add property `adress:"seoul"` by   
```js
foo.adress = `seoul`;
```   
   
Also, `adress:"seoul"` property can be added by   
```js
foo[`adress`] = "seoul";
```   
   
This bracket notaion is useful when **dynamically adding property**   
   
```js
const arr = [
    `apple`,`banana`,`kiwi`
]

for(let i in arr){
    bar[`fruit${++i}`] = arr[i];
}
```   
   
Now `bar` object has property with `fruit0:"apple"`,`fruit1:"banana"`,`fruit2:"kiwi"`   
   
Also useful for   
```js
const propName = `center-location`;
bar[propName] = `sth`;
```  
While `bar.center-location` is illegal, bracet notation enables it   
   

---  
   

## Delete   
   
```js
delete bar.name;
delete ber[`age`];
```   
   
This will remove property from object.   
   

---   
   

## Enumerate   
   
Seen in the *Add* section above, `i` in `for(let i in arr)` stands for number starting from **0** to **arr.length-1**   
   
But if `i` is in `for(let i in bar)` such object `bar`,   
it will stands for **key of Object**   
Inorder to check the value of key, bracket notation from above enables it   
   
```js
for(let i in bar){
    consol.log(bar[i]);
}
```   
   
Its output will be value of `name` and `age` key each.   
   
**Object.keys()** method returns an array of every key value of given object parameter.   
```js
const arr = Object.keys(bar);
console.log(arr);
```   
Output will be `["name","age"]`   
   
`if('sth' in object)` is searching key named as `sth` in `object`
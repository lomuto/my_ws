# Validator

`$ npm i validator`

[https://www.npmjs.com/package/validator](https://www.npmjs.com/package/validator)

Validates given string to certaion format.

```js
const validator = require(`validator`);

console.log(validator.isEmail("abc@gmail.com")); //true
console.log(validator.isEmail("abc!gmailcom")); //false

console.log(validator.isURL("https://www.google.com")); //true
console.log(validator.isURL("hello")); //false
```

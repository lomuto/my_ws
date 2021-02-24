# Basic Rest API with Nodejs   
   
```js
const express = require(`express`)
const Joi = require(`joi`)

const app = express();

const courses = [
    { id:1, name: `course1` },
    { id:2, name: `course2` },
    { id:3, name: `course3` }
]

const PORT = process.env.PORT || 3000;
app.listen(3000,()=>{ console.log(`Server listening ${PORt}`) })
```   
   
After this basic setup above, add `app.use(express.json())` middleware to approach `req.body`   
   
   
### 1. Config   
   
```js
app.get(`/api/courses`,(req,res)=>{
    res.send(courses)
})
```

This will show what's in `courses` when access to `http://localhost:3000/api/courses`   


---   


### 2. Search   
   
```js
app.get(`/api/courses/:id`,(req,res)=>{
    const course = courses.find(c => c.id === parseInt(req.params.id))
    if(!course){
        res.status(404).send(`Invalid id`)
        return;
    }
    
    res.send(course);
})
```   
   
`req.params.id` is **String**   
Must convert its type to **Integer** by **parseInt**

`find()` is a method in Array Object.    
It gets the first parameter as array that called it self.   
When callBack function, which is second parameter for `find` method returns false, `find` will return `undefined`   
When callBack function returns true for first time, `find` method returns that object.   
    
 
Must involve `return;` at the end of error execption so that **rest of code won't run** 
 
   
**404 for Not Found in URL**   
   

--- 
   

### 3. Add   
   
```js
app.post(`/api/courses`,(req,res)=>{
    const schema = {
        name: Joi.string().min(3).required()
    }
    const result = Joi.validate(req.body,schema)

    if(result.error){
        res.status(400).send(`Name not required or its length is under 3`)
        return;
    }

    const course = {
        id: courses.length + 1,
        name: req.body.name
    }

    courses.push(course)

    res.send(courses)
})
```   
   
`npm i joi` to use joi module   
   
Simplify this error condition   
   
```js
if( !req.body.name || req.body.name <3 ){
    ...
}
```   

to...   
   
```js
const schema = {
    name: Joi.string().min(3).required()
} 
const result = Joi.validate(req.body,schema)
if(result.error){
    ...
}
```
   
This is reallly useful when it comes with many error conditions.   
   
`validate` method takes object as a parameter   



---   
   
### 4. Edit    
```js
app.put(`/api/courses/:id`){
    const course = courses.find(e => e.id === req.params.id)
    if(!course){
        res.status(404).send(`Invalid id`)
        return;
    }

    const schema = {
        name: Jsi.string().min(3).required()
    }
    const { error } = Jsi.validate(req.body,schema);

    if(error){
        res.status(400).send(error.details[0].message)
        return;
    }

    course.name = req.body.name;

    res.send(courses)
}   
```   
   
return of `validate` method is an Object that has value and error field.   
When error occurs after comparing `req.body` and `schema`, error field fills up and satisfies `if` error statement   
   
Using `{}` we can extract certain field from Object such `const { error } =  ...`   


---     
   

### 5. Delete   
   
```js
app.delete(`/api/courses/:id`,(req,res)=>{
    const courseToDelete = courses.find(c => c.id === parseInt(req.params.id))
    if(!courseToDelete){
        res.status(404).send(`Invalid ID`);
        return;
    }

    const indexToDelete = courses.indexOf(courseToDelete);
    courses.splice(indexToDelete,1);

    res.send(course);
})
```   
   
While `parseInt(req.params.id)` is one ahead from its index number (`id:1` but index number is 0) use `indexOf` method to get its exact number   
   
`splice` method modifies an array that called itself.   
Its first parameter gets for index number and second for amount of element to erase   
   
---      

### Functionize   
   
   
By Setting a functios like   
```js
function idValidation(paramId){
    const course = courses.find(c => c.id === parseInt(paramId));
    return course ? course : false;
}

function bodyValidation(reqBody){
    const schema = {
        name: Joi.string().min(3).required()
    }
    const {error} =  Joi.validate(reqBody,schema);

    return error ? error : false
}
```   
   
We can re-use it

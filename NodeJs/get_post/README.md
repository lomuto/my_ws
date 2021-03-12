# Get and Post method  
   
## get   
   
get method is used to get parameter from *query string* in url   
   
> localhost:5000?name=yun&age=18   
   
Query string in url starts with `?` and parameters in url can be seperated by `&`   
   
```js
get((req,res)=>{
    console.log(`name in query string is ${req.query.name} and age is ${req.query.age}`);
})
```   
   
`name in query string is yun and age is 18`   
   
    
---    
   
   
## post   
   
Post method is slower but it's safer and able to send more data then `get`   
   
Datas sended by `post` are in `body`   
   
Requested data through `post` still can be detected with developer tool, so encryption still be needed   
   
```js
const express = require(`express`);

const app = express();

app.use(express.json());
app.use(express.urlencoded({extended:false}));

post((req,res)=>{
    console.log(req.body.foo);
})
```

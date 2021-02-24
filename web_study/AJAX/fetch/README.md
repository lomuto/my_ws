# Fetch API   
   
```js
function AJAXPromise(method,url,data,header,value){
    return new Promise((resolve,reject)=>{
        const xhr = new XMLHttpRequest();
        xhr.onload = ()=>{ resolve(xhr) };
        xhr.onerror = ()=>{ reject(xhr) };
        xhr.open(method,url);
        if(data){
            xhr.setRequestHeader(header,value);
            xhr.send(data);
        }
        else xhr.send();
    })
}
```   
   
By code above, we can promisify AJAX with one re-usable function   
   
There is an API that works simillar with it.   
   
When it comes with a `GET`   

```js
fetch(`http://myServer.com/api`)
    .then(response=>response.json())
    .then(data=>console.log(data))
    .catch(consolt.log)
```   
   
Fetch API basically takes two parameters as `url` and `setting Object`   
method for API such as `GET`,`POST`,`PUT` defined in `setting Object`, but for this case, its method is `GET`   
and **by default `fetch` use `GET` method for skipping the second parameter**   
   
Fetch API returns a Promise object so we can get its resolve argument with `response` in `.then()`   
   
After receiving a response from server,    
`.then(response=>response.json())` is shorthanded for `.then(response=>{ return response.json() })`   
and **response.json() returns a Promise object** that parses the responsed JSON to object   
Hence, inorder to get resolve object from responsed JSON, chaining the promise `.then(data=>console.log(data))` will do.    

     
For `POST`   
```js
async function fetchPost(){
    try{
        const newData = prompt(`Enter data to request`);
        const response = await fetch(`http://myServer.com/api`,{
            method:"POST",
            body:JSON.stringify({
                name:newData
            }),
            header:{
                "Content-type":"application.json"
            }
        });
        if(response.status === 400){
            const err = await response.text();
            throw err;
        }
        else{
            const data = await response.json();
            console.log(data);
        }
    }catch(err){
        console.log(err);
    }
}

fetchPost();
```   
   
As `fetch` and `response.text` are both return Promise object, async&await also available   
   
**Despite that `response` status is not 200 or 201, it doesn't throw error**   
So status of response must be handled inside `try`

# Promisify AJAX   

```js
function AJAX(id){
    const xhr = new XMLHttpsRequest();
    const dataToSend = {
        name:"hello"
    }
    xhr.open(`PUT`,`http://myserver.com/api/:${id}`);
    xhr.onload = ()=>{
        return xhr.response;
    };
    xhr.setRequestHeader(`Content-Type`,`application/json`);
    xhr.send(JSON.stringify(dataToSend));
}

function showData(){
    const resData = AJAX(2);
    console.log(resData);
}

showData(); // execute code
```   
      
Executing `showData` will...
1. Declare `resData` as const variable
2. Execute `AJAX` with argument of `2`   
3. Getting ready for sending request as `GET` method to server with given parameter `id` as query string
4. Set request header as given type
5. Convert object data to JSON string and send request   
   
As JavaScript is single threaded language, here comes a problem.   
No one knows whether...   
   
**server response its data and return value to initialize `resData`**   
or   
**console.log references uninitialized `resData` and print `undefined`**    
comes first   
   
    
Inorder to insure its sequence function `AJAX` must be promisified.   
   
```js
function AJAX(id){
    return new Promise((resolve,reject)=>{
        const xhr = new XMLHttpsRequest();
        const dataToSend = {
            name:"hello"
        }
        xhr.open(`PUT`,`http://myserver.com/api/:${id}`);
        xhr.onload = ()=>{
            resolve(xhr.response);
        };
        xhr.onerror = ()=>{
            reject(new Error(`Network error`));
        }
        xhr.setRequestHeader(`Content-Type`,`application/json`);
        xhr.send(JSON.stringify(dataToSend));
    });
}

function showData(){
    AJAX(2)//
        .then(result => console.log(result))
        .catch(console.log);
}

showData();
```

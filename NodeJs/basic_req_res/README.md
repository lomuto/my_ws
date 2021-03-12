# Building a simple webServer

> `http` : core module. declared as "http" itself, so no extension needed   
>   
> `createServer((req,res)=>{})` : method in http. takes callBack function with two param requset,respond   
>   
> `writeHead(statusNum,header:MIME)` : defines status number and contents to load. header should be written in MIME format   
>   
> `end` : sth to do when response ends...   
>   
> `listen` : method that set the port number. localhost:[portnumber]   

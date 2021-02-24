# Basic sequence of AJAX   
   
Sequence of AJAX runs with...   
1. Create new XMLHttpRequest object, let its example as `xhr`
2. Open object with `xhr.open(method,url)`   
3. Send request with `xhr.send()`   
4. When response event from server arrives, execute event handelr function that added with `xhr.onload()`   

As you can see at **4** above, function for response must be added **before send method executed**   
   
Hence, basic structure for AJAX would be...   

```js
const xhr = new XMLHttpsRequest();
xhr.open();

xhr.onload = ()=>{};

xhr.send();
```    
   
or   
   
```js
const xhr = new XMLHttpsRequest();
xhr.onload = ()=>{};

xhr.open();
xhr.send();
```  
   
So that after response event occured, handled function can be executed 
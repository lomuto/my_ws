# static middleware

Includes certain path of directory to server.
   
```js
import express from "express"
import serveStatic from "serve-static"
import path from "path"

const app = express();
const __dirname = path.resolve();
...
// both works same
app.use(express.static(__dirname__));
//app.use(serveStatic(__dirname))
```

```javascript
import express from "express"
import serveStatic from "serve-static"
import path from "path"

const app = exrpess();
const __dirname = path.resolve();

app.use(/foo,serveStatic(`${__dirname}/public`))

...listen(5000);
```

Setting middleware like code above, requesting  
<code>localhost:5000/**foo**/sth</code>  
will return `sth` inside `public` directory where nodejs file is at.

<pre>
ㄴmain.js
ㄴ<i><b>public</b></i>
    ㄴsth
</pre>

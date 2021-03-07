# bodyParser

**Express now provides bodyParser class.**  
`express.json()`

Inorder to extract parameter from request.body, `body-parser` module is required

Adding a `body-parser` to middleware by `app.use(bodyParser.sth())` as global or certain router, it helps to catch a data from request.

Usually deals with `form` data or request data of `AJAX`

---

**index.html**

```html
<!DOCTYPE html>

<head>
    <title>Document</title>
</head>
<body>
    <form method="POST" action="/login">    <!--post data to /login-->
        <input type="text" name="value">    <!--req.body.value-->>
        <input type="submit" value="submit">
    </form>
</body>
</html>
```

---

**main.js**

```js
import bodyParser from "body-parser"
...
app.use(bodyParser.json());
app.use(bodyParser.urlencoded( { extended:false } ));
...
```

Starting from express `v4.16`, body-parser has built in `express`

```js
import express from "express"
...
app.use(express.json());
app.use(express.urlencoded( { extended : false } ));
...
```

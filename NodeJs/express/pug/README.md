# PUG extension

_`npm i pug`_<br/><br/>
[express api](https://expressjs.com/en/api.html)

For the link above, we can check api about `app.set()`

![introPic](./intro.PNG)

we can also check the `view engine` and `views` parameter

![view](./view.PNG)<br/><br/>
While `view engine` is set to _undefined_ in default,  
`express().set("view engine","pug")`  
will set the `view engine` as `pug`<br/><br/>
`views` parameter is set to _process.cwd() + "/views"_ by default, which is _views_ directory which is at same for `express` file.  
`express().set("views",path.join(__dirname,"foo"))` will set the `res.render('bar')` to search `bar` file in `foo` directory
<br/><br/><br/>

```js
...
const app = express();
...
app.get(`/foo`,(req,res) => res.render("foo"))
```

When requesting to server with code above,  
"~/foo" request send a `foo.pug` file in `views` directory

```
--📂server.js
|
|-📂views - 📄foo.pug
```

<br/><br/>

```pug
html
    head
        title page
    body
        main
            p Hello
```

This .pug file will parsed to

```html
<html>
  <head>
    <title>page</title>
  </head>
  <body>
    <main>
      <p>hello</p>
    </main>
  </body>
</html>
```

</br></br></br>

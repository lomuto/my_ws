# Error handle in express with async function

Express basically doesn't provide promises. So if error was been caught inside of async function such as...

```ts
// 📂 router/someRouter.ts
const someRouteHandler: RequestHandler = async (req, res) => {
    try{
        ...
    } catch(e) {
        // catches an error and throw to middleware
        throw e;
    }
}
```

```ts
// 📂 app.ts
...
app.use('/someRoute', someRouteHandler);

// Expecting thrown error in prior step sent to this error handling router
app.use((err, req, res, next) => {
    res.status(500).json({ Error: err.messae })
})
```

But as I mentioned, **Express doesn't support promises....**  
So it will yeild an error by error from async function.

Inorder to fix this problem, just simply change `throw e` syntax to `next(e)`

```ts
// 📂 router/someRouter.ts
const someRouteHandler: RequestHandler = async (req, res) => {
    try{
        ...
    } catch(e) {
        // now, this will yeilds no error
        next(e);
    }
}
```

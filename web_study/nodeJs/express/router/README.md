# Router

### express.Route()

Route is a method of `express` module that provides `redirect`.  
**`static` method in `express` module must be added in middleware before locate relative path in redirection**

```js
const express = require(`express`);
const path = require(`path`);

const app = express();
const router = express.Router();

app.use(express.static(path.join(__dirname)));

router.get(`/`, (req, res) => {
  res.redirect(`....`);
});

router.get(`/foo`, (req, res) => {
  res.redirect(`....`);
});

router.get(`/bar`, (req, res) => {
  res.redirect(`....`);
});

app.use(`/`, router);

app.listen(5000);
```

As all redirect path is under root path(`/`) while redirect in root path(`/`) has also setted,
Setting middleware for `router` object by `app.use('/',router)` will add rest of all redirect path under root path
</br>

---

</br></br>

**Add `"type":"module"` in _package.json_ to use `import` and `export`**

```js
// 📁 router.js
import express from "express";

export const ROUTER = express.Router();

ROUTER.get(`/`, (req, res) => res.send(`root page`));
ROUTER.get(`/password`, (req, res) => res.send(`password page`));
ROUTER.get(`/test`, (req, res) => res.send(`test page`));

// export { ROUTER }
```

</br>

```js
// 📁 app.js

import express from "express";
import { ROUTER } from "./router.js";

const app = express();

app.use(`/foo`, ROUTER);

app.listen(5000);
```

Exporting `router.js` and import it from `app.js`.

This code works as adding a `ROUTER` to middleware relative to `/foo`.

So requesting `/foo` to server will response with _root page_ msg and `/foo/password` to _password page_.

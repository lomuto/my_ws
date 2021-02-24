# Using `import` syntax in nodejs

Since Node.js adopted CommonJS module sys, transpiler such as `Babel` required to use `import` syntax.  
Starting from 13.2v, ES moudule is available.

There are two ways to use `import` syntax.

1.  change module file's extension as `mjs` (`moduleFile.js` ==> `moduleFile.mjs`)
2.  Add `"type" : "module"` in `package.json` in project file

---

#### caution on relative path

While `require()` allows backticks(`` ` ``), double and single quotes(`',"`)  
`import` only allows double quotes(`" "`)

Aslo **full path including extension** required in using `import`

```javascript
const sthFromModule = require(`./moduleFile`);

import sthFromModule from "./moduleFile.js"
```
   
---   
   
### import extended module   
   
Extended modules such as `express`,`serve-static`,`path` are imported as   
`import express from "express"`   
such imported without relative path

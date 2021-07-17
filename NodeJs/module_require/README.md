# 3 ways to export and require moudle

```javascript
// 📂 moduleFile.js

const calc = {
  add(a, b) {
    return a + b;
  },
  sub: (a, b) => {
    return a - b;
  },
};
```

there are 3ways to export from `moduleFile.js` and import it from other file _which is in same directory_

1. `module.exports = calc`

   > ```javascript
   > // Exported as `clac` but importing with different name is available
   >
   > const improtedModule = require(`./moduleFile`);
   > improtedModule.add(1, 2);
   > improtedModule.sub(1, 2);
   > ```

<br/>

2. `module.exports = {calc}`

   > ```javascript
   > // exports object and import as destructure syntax
   >
   > const { calc } = require(`./moduleFile`);
   > calc.add(1, 2);
   > calc.sub(1, 2);
   >
   > // const calc = require(`./moduleFile`);
   > // calc.calc.add(1,2);
   > // Both are same
   > ```

<br/>

3. `module.calcModule = calc`

   > ```javascript
   > // Send it as gloabal object
   >
   > const importedModule = require(`./moduleFile`);
   > importedModule.calcModule.add(1, 2);
   > importedModule.calcModule.sub(1, 2);
   > ```
   >
   > OR
   >
   > ```javascript
   > const { calcModule } = require(`./moduleFile`);
   > calcModule.add(1, 2);
   > calcModule.sub(1, 2);
   > ```

<br/>

4. Exporting object right through

   > ```js
   > // 📂 moduleFile.js
   >
   > module.exports = {
   >   name: "yun",
   >   age: 18,
   > };
   > ```
   >
   > ```js
   > // 📂 main.js
   >
   > const MODULE = require("./moduleFile.js");
   >
   > console.log(MODULE.name); // "yun"
   > console.log(MODULE.age); // 18
   > ```
   >
   > OR
   >
   > ```js
   > // 📂 main.js
   >
   > const { name, age } = require("./moduleFile.js");
   >
   > console.log(name); // "yun"
   > console.log(age); // 18
   > ```

<br/>

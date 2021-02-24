# 3 ways to export and require moudle

let `moduleFile.js` as

```javascript
const calc = {
  add(a, b) { return a + b },
  sub: (a, b) => { return a - b }
};
```

there are 3ways to export from `moduleFile.js` and require from other file _which is in same directory_

1. `module.export = calc`

   > ```javascript
   > const improtedModule = require(`./moduleFile`);
   > improtedModule.add(1, 2);
   > improtedModule.sub(1, 2);
   > ```

2. `exports.calcModule = calc`
   > ```javascript
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

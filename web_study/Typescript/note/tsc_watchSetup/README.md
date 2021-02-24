# Install typescript and finish setting   
   
tsc-watch is basically like... `nodemon` in nodejs.   
Instead of keep typing `$npm start`, tsc-watch will keep watching code and show result console immediately...   

0. (Not sure whether its essential) `$npm link typescript`  
1. Install tsc-watch by `$npm add tsc-watch -d`
2. Edit `tsconfig.json` to...   
   
```json
{
    "compilerOptions": {
        "module": "commonjs",
        "target": "ES2015",
        "sourceMap": true,
        "outDir": "dist"
    },
    "include":["src/**/*"],
    "exclude":["node_modules"]
}
```   
   
outDir: Destination where compiled `.js` file will be located.   
include: `src/**/*` means, every file(`*`) in every directory(`**`) inside `src` directory which is at same directory with `tsconfig.json`   
   
3. Edit `package.json` to...   
   
```js
"scripts": {
    "start":"tsc-watch --onSuccess \" node dist/index.js\" "
  }
```   
   
It means when compile successed with no error, save compiled `.js` inside `dist` as name with `index.js`   
   

   
**Start tsc-watch with `npm start`**
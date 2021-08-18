1. `$ npm install typescript --save-dev`
2. _tsconfig.json_

```json
{
  "compilerOptions": {
    "module": "commonjs",
    "target": "ES2015",
    "sourceMap": true
  },
  "include": ["index.ts"],
  "exclude": ["node_modules"]
}
```

- module: set the moudle of JS to execute with nodejs
- targer: ES version to compile with
- include: files to compile
- exclude: files not to be compiled

3. Add `script` key to `package.json` by following....

```json
"scripts": {
    "start":"node index.js",
    "prestart":"npx tsc"
  }
```

- prestart: command before `start`. `$npx tsc` stands for compile `.ts` to `.js`
- start: command that automatically runs for `$npm start`

**Inorder to let compiler know that `.ts` is module file, `export {}` has to be added in very end of code...**

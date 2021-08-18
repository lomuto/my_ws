# compilerOptions

### target: string

version of javaScript  
default: `es5`

<br/>

### moudle

commig soon...

<br/>

### lib: string[]

Choose libraries that provided.

default: auto include libraries such includes `document` and `console`

```json
// same as lib is commented in target es6
"lib": [
    "dom",
    "es6",
    "dom.iterable",
    "scripthost"
]
```

<br/>

### allowJs, checkJs : boolean

Choose wheter typescript will compile `.js` file not only as `.ts` file.

Useful in such situation that you build a project combined `.ts` and `.js`

<br/>

### sourceMap: boolean

Useful in debugging.

Generates a bridge between compiled `.js` and `.ts` so that we can check in browser.

<br/>

### outDir: string[]

Controlls the path of compiled `.js` file.

while default _ourDir_ is same directoy as `.ts` file,

<br/>

### rootDir: string[]

Set the root directory of where `.ts` file is located.  
Save the time for typescript compiler to search for `.ts` files.

Also, when _ourDir_ is settled, **typescript compiler will synchronize directories of _outDir_ with _rootDir_**

```
outDir: ./dist
rootDir is not settled

📂prj
    ㄴ 📂src
        ㄴ index.ts
    ㄴ 📂user
        ㄴ userFile
    ㄴ 📂dist
        ㄴ 📂src
            ㄴ index.ts
        ㄴ 📂user
            ㄴ userFile
```

```
outDir: ./dist
rootDir ./src

📂prj
    ㄴ 📂src
        ㄴ index.ts
    ㄴ 📂user
        ㄴ userFile
    ㄴ 📂dist
        ㄴ index.ts
```

<br/>

### removeComments: boolean

Removes the comment in compiled `.js` file

<br/>

### noEmit: boolean

Doesn't generate output `.js` file. Just for **check whether `.ts` file is good to compile**  
Surely it will save time for compilation whether `.ts` is validate to be compiled.

<br/>

### noEmitOnError: boolean

If typescript file has error, compiler would not emit a `.js` file

<br/>

### strict

Strictness of compilation process.

If `strict` option has set to _true_, that means all those upcoming secondaey options are also true.

- noImplicitAny:  
  Prohibits `any` type in paramter.  
   The reason why it only works it parameter is that type of global variable can be dynamcially tracked in runtime, while **function parameter has to be defined in its initialzation**

<br/>

```ts
const btn = document.querySelector("button")!;
```

- strictNullChecks:  
  such case above, `!` at the end of line is forced. Cause typescript won't know whether there is `button` element in current document. So `!` guarantees typescript that such element exists, so don't make an error.  
  This situation happens because if there is no button element, then **expression will return null**. strictNullCheks won't allow single chance of variable holding a _null_

<br/>

- strictBindCallApply:  
  Prevents user from accidently bind wrong object.

```ts
const handler = (message: string) => {
  console.log(`Message: ${message}`);
};

/*
First param of bind: Object to bind. In this case, binded object is unnecessary so pass null.

Second param of bind: Pre-defined first argument of function handler
*/
btn.addEventListener("click", handler.bind(null, "Hello")); // Forces user to set second argument of bind function
```

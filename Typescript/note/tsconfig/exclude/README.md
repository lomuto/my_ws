# exclude

```json
// 📄 tsconfig
...
},
"exclude": [
    "node_modules"
]
```

`node_modules` directory is excluded in typescript compile process by default.

But when you adding other directoy or file to be excluded in complier process, **must add `node_modules` in exclude list** otherwise typescript will compile all those enormous files inside `node_modules`.

To the bottom line

1. If there are no files or directories to be excluded, `node_modules` is added in exclude list by default.
2. Adding some file or directory to exclude list, **must add 'node_modules'**

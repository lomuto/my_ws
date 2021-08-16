# never

`never` type is to emplicitly show to a programmer that this function would **never** returns anything.

```ts
const spinning = (arg: number): never => {
    while(arg) {
        ...
    }
}
```

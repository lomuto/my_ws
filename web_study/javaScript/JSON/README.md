# JSON

**JSON is string!**

object --> JSON  
`stringify(value: any, replacer?: (this: any, key: string, value: any) => any, space?: string | number): string;`

JSON --> object   
`parse(text: string, reviver?: (this: any, key: string, value: any) => any): any;`

value in object can be written with `backtick`,`single quote` and `double quote`  
when object is converted to JSON, its value will be in **`double quote` only**

hence...

- object: { name: 'Anderson', age: '18', height: '186', eye: 'brown' }
- JSON: {"name":"Anderson","age":"18","height":"186","eye":"brown"}

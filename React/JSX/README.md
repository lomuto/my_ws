# JSX

### JSX: JavaScript Xml

<br/>

<br/>
   
## How `<App />` is compiled?

```js
const App = () => {
  return (
    <div>
      <li></li>
      <li>
        <ul></ul>
      </li>
      <li></li>
    </div>
  );
};
```

Suppose we have `App` for code above.  
Go to [BABEL](https://babeljs.io/) and check the code to be compiled as...

```js
"use strict";

const App = () => {
  return React.createElement(
    "div",
    null,
    React.createElement("li", null),
    React.createElement("li", null, React.createElement("ul", null)),
    React.createElement("li", null)
  );
};
```

This is how it works.

<br/>

---

<br/>   
   
## HTML to JSX   
  
```html
<!-- html -->
<label class="label" for="name">
    Enter name:
</label>
<input id="name"></input>
<button style="background-color:blue; color:white">Submit</button>
```
   
```JSX
// JSX
const App = ()=>{
    return(
        <div>
            <label class="label" for="name">
                Enter name:
            </label>
            <input id="name"></input>
            <button style={{backgroundColor:"blue",color:"white"}}>Submit</button>
        </div>
    );
};
```
   
`for="name"` attribute in `label` tag is just link the label and input tag with `id="name"`.
   
<br/>

### Changes

- Returning an Element in JSX must be wrapped in single tag.

```jsx
// illegal
return(
    <div></div>
    <div></div>
)
```

```jsx
// legal
return (
  // wrapped in single div tag
  <div>
    <div></div>
    <div></div>
  </div>
);
```

- `style` in html tag replaced in JSX as key and value for object. Its name also changed to `background-color` to **`backgroundColor`**

- `{}` in JSX is for using javascript syntax in JSX. So, `{{}}` is **Object in javascript syntax**  
  Each property in object stands for style-attribute and its value.  
  Hence,

```html
<foo style="background-color:blue; color:white"></foo>
```

TO

```jsx
<foo style={{backgroundColor:"blue",color:"white"}}>
```

As JSX's style attribute is a property of object, delimiter of each attribute changed [`;`] -> [`,`]

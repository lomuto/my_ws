# Start with react.

## Getting started

```bash
$ npx create-react-app %MY_APP%
```

This will create a project folder of react app.

<br/>

---

<br/>   
   
## npm start   
   
move to prj folder   
```bash
$ cd %MY_APP%
```   
   
then   
```bash
$ npm start
```   
Then we can check the result in live-time like `nodemon`

   <br/>

check the `package.json` and see

```js
"script":{
    "start":"react-scripts start"
    ...
}
```

So basically, `$ npm start` is alias of `$ react-script start`

We can check the code of `start.js` in `%MY_APP%/node_modules/react-scripts`, compiles our react code to ES5 contents using babel.

<br/>

---

<br/>

## Hello react

In our project folder, we can see `index.js` in `src` folder. **Inorder to run react app, main code of our project must be a name of `index.js` inside `src` folder**

```jsx
import React from "react";
import ReactDOM from "react-dom";

const App = () => {
  return <div>Hello React!</div>;
};

ReactDOM.render(<App />, document.querySelector("#root"));
```

This could be the basic code of print "Hello react" on browser.

Let's focus on `ReactDOM.render()`

`<App />` is equal to `App()`. So it just returns a HTML string.

`document.querySelector("#root")` indicates a `<div id="root"></div>` in `%MY_APP%/public/index.html`  
Every jsx go inside of `document.querySelector("#root")` will be taken care of react.

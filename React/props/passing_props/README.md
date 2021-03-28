# Basic of props

```js
import React from "react";
imoprt ReactDOM from "react-dom";

const App = ()=>{
    return(
        <div>
            <div class="person">
                <div id="name">My name is John</div>
                <div id="age">I'm 25 years old</div>
                <div id="height">I'm 184cm</div>
            </div>
        </div>
    );
};

ReactDOM.render(<App/>,document.querySelector("#root"));
```

Code above shows a spec of person.  
What if I want to show another person "Kaleb" 29years old and 178cm height?

```js
const App = () => {
  return (
    <div>
      <div class="person">
        <div id="name">My name is John</div>
        <div id="age">I'm 25 years old</div>
        <div id="height">I'm 184cm</div>
      </div>
      <div class="person">
        <div id="name">My name is Kaleb</div>
        <div id="age">I'm 29 years old</div>
        <div id="height">I'm 178cm</div>
      </div>
    </div>
  );
};
```

This will do.  
But when it comes to adding a 100 people, that would be pain in the ass.

---

```js
const Person = (props) => {
  return (
    <div class="person">
      <div id="name">My name is {props.name}</div>
      <div id="age">I'm {props.age} years old</div>
      <div id="height">I'm {props.height}cm</div>
    </div>
  );
};

const App = () => {
  return (
    <div>
      <Person name="John" age="25" height="184" />
      <Person name="Kaleb" age="29" height="178" />
    </div>
  );
};
```

Using `props` we can add people easily.

```js
const Person = ({name,age,height}) => {
```

This will explicitily show how many props are in component.

# Usestate

use

```js
const [data, setData] = useState(0);
```

not

```js
constructor(props){
    super(props);
    this.state = {
        data:0
    }
}
```

---

`useState` takes an initial value of `state` and returns its value's reference and function pointer that can change its state in an array of first and second index in sequence.

By using destructor syntax,

```js
const [data, setData] = useState(0);
```

`data` will be the state's name and we can set a function of modifing state at `setData`

---

```js
import React, { useEffect, useState } from "react";
import ReactDOM from "react-dom";
import axios from "axios";

const Content = ({ userId, id, title, body }) => {
  return (
    <div style={{ border: "2px solid black", marginBottom: "13px" }}>
      <div>User ID: {userId}</div>
      <div>ID: {id}</div>
      <div>Title: {title}</div>
      <div>Body: {body}</div>
    </div>
  );
};

const App = () => {
  const [data, setData] = useState(null);

  const getData = () => {
    axios.get("https://jsonplaceholder.typicode.com/posts/").then((res) => {
      setData(res.data);
    });
  };

  return (
    <div>
      <button onClick={getData}>Click to Fetch data</button>
      <div>
        {data == null
          ? "Loading..."
          : data.map((d) => {
              return (
                <Content
                  userId={d.userId}
                  id={d.id}
                  title={d.title}
                  body={d.body}
                />
              );
            })}
      </div>
    </div>
  );
};

ReactDOM.render(<App />, document.querySelector("#root"));
```

Clicking the button will execute `getData` and `getData` will fetch a data and save them to `data` by `setData`.

After fetch has finished, it will reload the component and add the `Content` component.

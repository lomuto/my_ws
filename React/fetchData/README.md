# Fetch data asynchronously

```jsx
import React from "react";

class App extends React.Component {
  state = {
    loading: true,
    data: null,
  };

  async componentDidMount() {
    const response = await fetch("https://jsonplaceholder.typicode.com/posts/");
    const rawData = await response.json();
    this.setState({ data: JSON.stringify(rawData), loading: false });
  }

  render() {
    return (
      <div>
        {this.state.loading ? (
          <div>Loading...</div>
        ) : (
          <div>{this.state.data}</div>
        )}
      </div>
    );
  }
}

export default App;
```

---

Add a comment after I get to understand this clearly.

- `componentDidMount` : It seems like function runs automatically when It called.
- `state` : After component created, It is permenant. But using `state` and `setState`, some variable in `state` get to changed in `setState`, Component rendered again I guess..?

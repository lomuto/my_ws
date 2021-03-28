# props.children

Passing a small part of component could be done by `props` object.

```js
<Foo name="John" age={generateName()} />
```

But what about passing a whole component?

Suppose

```js
const Segment = (props) => {
  <div>
    <div className="content">// place to put content in</div>
  </div>;
};
```

If we want to put whole component in a `.content`,

```js
const Segment = (props) => {
  <div>
    <div className="content">{props.children}</div>
  </div>;
};

const App = () => {
  return (
    <Segment>
      <div>
        <p>This is content</p>
      </div>
    </Segment>
  );
};
```

Add components inside of `Segment`'s open and close tag  
component will be passed automatically in wrapped with inside of `props` name as `children`.

```js
<div>
  <div className="content">
    <div>
      <p>This is content</p>
    </div>
  </div>
</div>
```

# Intersection type

```ts
let foo: string | number;
```

We've seen this kind of type that variable `foo` can hold either `string` and `number`.  
We can extend this with interface as

```ts
type myType0 = number;
type myType1 = string;

type myFinalType = myType0 | myType1;

let foo: myFinalType;
```

`foo` can now hold number and string.

<br/>

We can set the type to duplicated one with those given types with `&` operator such as

```ts
type myType0 = number | string;
type myType1 = string | boolean;

type myType2 = myType0 & myType1;
```

Now `myType2` is a string type.

<br/>

## How about in object?

```ts
interface myType0 {
  name: string;
  age: number;
}

interface myType1 {
  name: string;
  height: number;
}

type myType2 = myType0 | myType1;
type myType3 = myType0 & myType1;
```

What would be the difference in those two?

### union in object

```ts
let foo: myType2;

foo = {
  name: "good",
  age: 12,
};

foo = {
  name: "good",
  height: 162,
};

foo = {
  name: "good",
  age: 12,
  height: 162,
};
```

Union type in object enables variable with such type can **represent every single types**, so basically it can become type `myType0`, `myType1` and `myType2` at the same type.

<br/>

### intersection in object

```ts
let foo: myType3;

// compile error
foo = {
  name: "good",
  age: 12,
};

// compile error
foo = {
  name: "good",
  height: 162,
};

foo = {
  name: "good",
  age: 12,
  height: 162,
};
```

Unlike the union, type with intersection can only be stay in total consumption of given types.  
As you can see above, only last examples would be leagal

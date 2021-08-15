# Tuple

```ts
let foo: string | number;
foo = 1; // Legal
foo = `Hello`; // Legal as well
```

Type of variable in TS can be multiple as it seen with `|` (OR) keyword  
So `foo` can be both string and number

---

```ts
const foo = (string|number)[] = [];
foo.push(1);
foo.push(`Hello`);
foo.[1] = 2;        // foo: [1,2] Still legal
```

Setting an type as multiple is also available at Array.  
Array `foo`'s element can be both string and number.  
After changing second element of `foo` string `Hello` to number 2 will make array `foo` as array of number. But its fine so far.

---

What if you want to make an array of two types, which is string and number, **while ensure that first element is number and second is string?**  
This is where **`Tuple`** comes.

```ts
const foo: [number, string] = [1, `Hello`];

foo[0] = 2;
foo[1] = `Nello`; // both legal

foo.push(`hrhr`); // Legal??
```

Array `foo` must have number for first element and string for second.  
Modifing its element is OKAY as long as tuple set is legal.  
But if pushing an element is also legal? **Yes**  
If its not initialize it as `[1'Hello',4]` like adding an extra element, TS can't pushing an element.

# map

- Initialize

```cpp
map<string,int> m;
```

<br/>

- Add

```cpp
m.insert(make_pair("height",185));
m.insert(pair<string,int>("height",185));
```

Must hand it over as `pair`

<br/>

- Modify

```cpp
m[height] = 172;
```

`[]` operator has been overloaded inside class `map`  
`m[foo] = 192;` will modify key `foo` as 192 or **Add a element with key for `foo` and value for `192`**

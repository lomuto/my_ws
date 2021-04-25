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

## **Add same `key` by `m.insert` won't update the value of key.**

<br/>

- Modify

```cpp
m[height] = 172;
```

`[]` operator has been overloaded inside class `map`  
`m[foo] = 192;` will modify key `foo` as 192 or **Add a element with key for `foo` and value for `192`**

---

<br/>   
   
## Traversing map   
   
```cpp
map<string,int> m;
...
for(map<string,int>::iterator it = map.begin() ; it != map.end() ; it++){
    cout << it->first << ' ' << it->second << '\n';
}
```   
   
It will print map's element by order of `key value`

# Unique_ptr

```cpp
#include <memory>
```

Unique pointer is very useful for following an **RAII**

```cpp
unique_ptr<int> foo(new int(3));
```

Such `foo`'s allocated memory in heap will be returned automatically when process is out of `foo`'s scope.

<br/>

---

<br/>

- ### Initialization and assignment

```cpp
// init
unique_ptr<int> foo(new int);
```

```cpp
// assign
unique_ptr<int> foo = make_unique<int>();
```

<br/>

---

<br/>   
   
## **unique_ptr with vector**
   
As `unique_ptr` is a class,   
It can be initialized with constructor such
```cpp
unique_ptr<int> uniq(new int(3));
```   
   
Using `unique_ptr` with `vector` has advantage of dealing with dynamically allocated vector elemetns.
   
<br/>

---

<br/> 
   
```cpp
vector<unique_ptr<int>> v;
```   
   
When it comes with such vector `v` above,   
Adding an element with `v.push_back(new int(bar))` seems legal but **it is not**.

```cpp
vector<unique_ptr<int>> v;
v.reserve(5);

for(int i=0,buf; i<5; i++){
    cin >> buf;
    v.push_back(unique_ptr(new int(2)));
}
```

Adding an element must be held with creating another `unique_ptr` instance.

**vector's type is `unique_ptr<T>` so type of element that is to be added also be an instance of `unique_ptr<T>`**

<br/>

---

<br/>

```cpp
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

typedef struct _cor {
    int x;
    int y;
} COR;

int main() {
    int n;

    cin >> n;

    vector<unique_ptr<COR>> v;
    v.reserve(n);

    for (int i = 0, tmp1, tmp2; i < n; i++) {
        cin >> tmp1 >> tmp2;
        unique_ptr<COR> temp(new COR{tmp1, tmp2});
        v.push_back(temp);
    }
}
```

While **`push_back` only takes an instance** use `emplace_back` for not creating an temporalily instance.

```cpp
for (int i = 0, tmp1, tmp2; i < n; i++) {
    cin >> tmp1 >> tmp2;
    v.emplace_back(new COR{ tmp1, tmp2 });
}
```

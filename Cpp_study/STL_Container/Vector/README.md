# Vector

- `#include <vector>`

- `vector<type> foo` : Creates a vector container `foo`

- `foo.reserve(n)` : Make `n` spaces for vector container. While size of vector is managed similar with `string`, **It is essential to reserve vector's size at the declaration.**  
  This enables optimization at compile prcoess.

- `foo.begin()` : Retruns a reference of vector's starting element.

- `foo.end()` : Returns a reference of vector's **one ahead of last element**

- `std::vector::iterator` : As vector's type varies in runtime, setting its type as `object` is also legal. So even though vector is an array, **dereferencing it by [] operator might be impossible for an object type**. That's why concept of `iterator` comes out. It takes element address of vector, and enables traversing elements in array.

```cpp
// using namespace std

vector<int> foo;
foo.reserve(10);

...

for(vector::iterator i=foo.begin() ; i < foo.end() ; i++){
    cout << foo[i];
}
```

- `const_iterator` : Same iterator, but prevent modifying dereference.

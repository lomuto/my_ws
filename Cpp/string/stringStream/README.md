# istringstream

### Input String Stream

Inorder to use `getline` in `<string>` header file, its first parameter is `std::isteam` type.

Let's say we want to toknize `"Hello My Name Is Foo"`.  
Delimiter of string would be `' '(blank space)` so

```cpp
string temp;
...
getline(str,temp,' ');
```

Seems work,  
**But first parameter is `string` not `istream` so it would occur error.**

To use string as input stream,  
`istringstream` in `<sstream>` header comes out.

```cpp
#include <sstream>

using namespace std
...
string "Hello My Name Is Foo";
istringstream iss(str);
string temp;

while(!iss.eof()){
    getline(iss,temp,' ');
    cout << temp << '\n';
}

```

As `iss` is stream,  
`eof` method is available.

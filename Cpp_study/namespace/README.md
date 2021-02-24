# Namespace

```cpp
#include <iostream>

int main(){
    std::cout << "Hello World!" << std::endl;
}
```

`std` in code above is called **namespace**  
`std::cout` specifies a variable `cout` which is inside a `std` namespace.  
Namespace `std` exists inside headerfile `iostream`<br/><br/><br/>

```c
#include <stdio.h>

int main(){
    printf("Hello world!");
}
```

We all aware of that function `printf` is inside `stdio` headerfile.  
Exactely same for `std`, which exists as namespace instead of function<br/><br/><br/>

```cpp
// 📂 iostream
...

namespace std{
...
ostream cout;
...
}
```

This is what `cout` in `std` would look like.<br/><br/><br/>

```cpp
#include <iostream>

using namespace std;    // MOST LIKELY NOT RECOMMENDED

int main(){
    cout << "Hello World!" << endl;
}
```

`using namespace std` enables write everything in namespace `std` from included `iostream` headerfile without explicitely say `std::cout`, just `cout`  
**While there are so many variable and function is `std` namespace, so `using namespace std` might cause error of overwritting variable name**<br/><br/><br/>

```cpp
#include <iostream>

using std::cout;

int main(){
    cout << "Hello" << std::endl;   // write endl in solo would cause error.
}
```

`using std::cout` includes `cout` in `std` namespace **exclusively**.  
That means, other things in `std` such `endl` won't be included.

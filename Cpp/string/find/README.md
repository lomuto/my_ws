# find

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string INPUT, TARGET;
    cin >> INPUT >> TARGET;

    int res = INPUT.find(TARGET);

    if (res == string::npos)
        cout
            << TARGET << " not found\n";

    cout << TARGET << " found in: " << res << '\n';
}
```

`find` method searh a specific char or string inside a caller obj.

```cpp
INPUT.find(TARGET);
```

will search string `TARGET` from `INPUT`.  
When it finds `TARGET`, it will return a relative starting index of `TARGET` inside `INPUT`. ("abc" in "kkabckk" will be `2`).

When `TARGET` doesn't exists in `INPUT`, it will return **`string::npos`** which stands for fail in `find`.

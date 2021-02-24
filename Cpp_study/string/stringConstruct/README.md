# std::string constructor

```cpp
#include <iostream>

int main() {
    std::string name;
    std::cout << "Please enter your first name:";
    std::cin >> name;

    std::string greeting = "Hello, " + name + "!";

    std::string spaces(
        greeting.size(),
        ' ');  // spaces(14, ' ');, character is only available in second param
    // constructor function of string class
    std::string second = "* " + spaces + " *";
    std::string first(second.size(), '*');

    std::string test(10, 'j');

    std::cout << test;
}
```

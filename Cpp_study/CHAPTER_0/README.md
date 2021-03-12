# Hello World!   
   
```cpp
#include <iostream>

int main(){
    std::cout << "Hello Wordl!" << std::endl;

    return 0;
}
```   
   
`std` is a **namespace** inside `iostream`   
   
`std::cout` is an output bufffer.   
Its data type is `std::ostream`
   
`std::endl` clears an output buffer.   
   
`<<` is an operator   
This **left associative** operator takes left operand as `std::ostream` typed.   
   
As `<<` is left associative...   
`std::cout << "Hello Wordl!" << std::endl;` is same as   
`{std::cout << "Hello Wordl!"} << std::endl;`   
   
When `std::cout << "Hello World!"` executed, this expression yields `std::cout` object. So it can be carried on to `std::cout << std::endl;`.      

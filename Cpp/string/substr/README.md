# substr

```cpp
string foo = "012345678";

foo.substr(0,2);    // "01"
foo.substr(3,-1);   // "345678"
foo.substr(3,4);    // "3456"
```

First parameter is index number of string.  
Second parameter is length of sub string.

If length of sub string is out of string's bound, substring will be starting from first parameter's index to string's end.

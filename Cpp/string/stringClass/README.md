# std::string

`std::string` type is a C++ variable type for string.

What `std::string` is really amazing is that it's size(length) is dynamic.

Before explain about this, `std::string` is available for basic arithmetic, compare operator sych `+,==,!=`

```cpp
// C
char fullname[SIZE] = strcat(firstname,lastname);

//Cpp
std::string fullname = firstname + lastname;
```

</br>

```cpp
// C
temp = strcmp(str1,str2);
if(!temp)
    //same string
else if(temp > 0)
    // str1 is alphabetical preceeds than str2
else if(temp < 0)
    // str2 preceeds alphabetical order than str1

// Cpp
if(str1 == str2)
    //
else if(str1 > str2)
    //
else if(str1 < str2)
    //
```

---

</br>

## How is that possible?

</br>

To explain what happens inside `std::string`...

1. approx **16byte** mem allocated for `std::string` type. `private` member that counts for its size(length) is always counting
2. for `+` operator, copy the characters to `std::string` variable memory and increase the `size` member.
3. If extra characters to add exceeds left out memory, **reallocate memory for bigger size** and copy the origin characters and copy the rest. Free for ex-memory also happens.

While these process happens in `heap`, **Modifing std::string type variable too much could occur memory fragmentation**

That's why `snprintf` and `char[]` instead of `std::string` used more frequently.

`snprintf(fullname,40,%s,%s,firstname,lastname)`

</br>

Aslo, memory of `std::string` might changes a lot. By using `c_str()` method we can get starting memory of string. (return type is `const char*`)

# How to understand const in pointer

**Read it from right to left!**

</br>

- const char\* str

Arranging syntax above would be [ *, char, const ] which is **Pointer to char which is const**  
and it means, `str` is variable that pointer, which is its character (dereferenced one) is const.

So,

```c
str = &sthStr;
```

is legal, while

```c
*str = 'x';
```

is illegal.

</br>

- char\* const str

[ const pointer to char(char pointer) ]  
It means _pointer to char_, which is \*char\*\* it self is a const.

So,

```c
*str = 'x';
```

is legal,

```c
str = &sthStr;
```

is illegal.

</br>   
   
Reading it from right to left is useful to understand because that how syntax tree in compiler exactly works. (pushing the given string by word, and parse it by poping order.)

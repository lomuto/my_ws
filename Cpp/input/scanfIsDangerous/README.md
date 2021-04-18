# Why scanf is dangerous?

**scanf skips the boundary check**

```c
char name[4];
scanf("%s",name);
```

Such code above, if we write `John`,  
**allocated memory is only 4bytes, but total 5 bytes(John\0) with extra 1 byte of invasion occurs**  
This could lead to serious problem while those invaded memory could be area of kernel.

That's why `scanf_s` | `sscanf` (secure scanf) takes third parameter as maximum characters to be embraced.

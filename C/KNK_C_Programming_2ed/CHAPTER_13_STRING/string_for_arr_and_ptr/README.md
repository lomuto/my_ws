# Array and Pointer as String   
    
`char* ptr = "Hello"`   
str points to string literial   
   
`char str[] = "Hello"`   
str allocated 6bytes(1byte for '\0') of memory and add `\0` at the end   
   
```
char str[] = "Hello";
char* ptr = str;
```   
Now ptr points to array of character, so it can access to memory   
while 'ptr' at the top points to string literial.   
   
**It's not matter of string is initialized by pointer or array, it's matter of the object that it's pointing** 

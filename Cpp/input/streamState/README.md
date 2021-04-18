# State of stream

```c
if( fgets(line, 10, stdin) != NULL ){
    // ...
}
```

C version of reading from standard input. ( `stdin` )  
There are several cases for `fgets` to return `NULL`, code is a bit ambigious.  
</br>

```cpp
// 📁 read_line.c

std::cin >> line;
if( std::cin.eof() ){
    std::cout << "end of file" << std::endl;
}
```

`std::cin` is same as `stdin` in C.  
When standard input file's pointer points to _end of file_,  
`std::cin.eof()` returns `true`.

<br/>

<br/>
   
```
// 📁 foo.txt

hello

```
File `foo` ends with new line character (`\n`).

</br>

`$ cat ./foo | ./read_line.out`

Such command will hand over content of `foo` to execute file of code above.

<br/>

if `foo.txt`'s content is `hello\n` such involves new line character it will end fine.

But if `foo.txt`'s content is `hello` such with **no new line character**, after reading the `foo.txt`, file pointer will left in end of file while couldn't met *black space character*.
So it would print "end of file".
```

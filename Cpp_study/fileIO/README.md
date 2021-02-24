# I/O stream

- header: < fstream >
- ifstream 파일입력
- ostream 파일출력
- fstream 파일 입력 및 출력  


```cpp
std::fstream fs;
fs.open("foo.txt");

// Exception handle
if(!fs.is_open())
    return 0;

//read
std::string temp;
for( getline(fs,temp) ; !fs.eof() ; getline(fs,temp) )
    std::cout << temp << std::endl;

//write
char str[SIZE] = "Hello";
fs.write(str,SIZE);
```

**`std::fstream fs;` is essential that it's creating a file stream object**

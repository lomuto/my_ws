# Reverse string

Taking inputs

```c
#define BUF_SIZE = 64

int main(){
    char BUFFER[BUF_SIZE];

    getline(BUFFER, BUF_SIZE);

    ...
}
```

</br>
   
- My code
```c
void REVERSE(char* const origin, char* dist){
    int i = 0;
    for(char* ptr = origin + strlen(origin)-1 ; ptr != origin ; ptr--, i++){
        *(dist + i) = *ptr;
    }
    *(dist+i) = '\0';
}
```   
   
Problem:
1. Using to much mem
2. Hard to read
3. O(n). A bit slow   
   
</br>   
   
- Better Code
   
```cpp
#define SWAP(x,y) x = x^y, y = x^y, x = x^y
...
void REVERSE(char* const str){
    for(char *p = str, *q = str+strlen(str)-1 ; p < q ; p++,q--){
        SWAP(*(str+p),*(str+q));
    }
}
```
Compact use of mem and clean   
most of all, **O(n/2)**

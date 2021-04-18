# compare string   
while variable `str` is `char str[] = "hello";`   
   
`str == "hello"` would return 0   
   
It's because each operand it self represent their ***adress*** in memory   
   
we can check this by   
   
```
char* str = "waffle";
if(str == "waflle")printf("waffle!\n"); 
```
this would print "waffle", while `str` points string literal "waffle"'s adress   
   
function `int strcmp(const char* str1,const char* str2)` provide proper comparsion with string while return 0 if `str1` and `str2` is same string.   
while comparing `str1` and `str2`in alphabetic order in each sequence of character,   
it would return 1 when `*(str1) > *(str2)`, return -1 when its in opposite(Window OS)   
   
***MAC OS and Linux return diff, not 1 or -1***

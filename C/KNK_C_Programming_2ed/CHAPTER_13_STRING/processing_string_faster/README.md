# Processing the string Faster   
   
Let's say that we want to find out the length of string.   
which ends with the same question of finding last character of string   
   
```
size_t MY_strlen(const char* str){
	int n=0;
	for(;*str != NULL;str++) n++;

	return n;
}
```    
   
if str[i] is NULL, NULL can also end the loop, so we can change the statement as `for(;*str;str++)`   
   
`++` operator is in higher position in hierachy comparing to `*`, so it can be abbreviated as `for(;*str++;)`   
   
Finally, instead of adding 1 to `n` untill loop ends, we can finish that in once. If we handle this, finall function would be...  
   
```
size_t MY_strlen(const char* str){
	char* temp = str;   
	for(;*str++;);
	
	return str-temp;				
} 
```

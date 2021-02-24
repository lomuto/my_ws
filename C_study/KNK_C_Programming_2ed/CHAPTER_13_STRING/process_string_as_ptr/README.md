# Using pointer operations for porcessing string   
```
int count_space(char* str) {
	int temp=0;
	for (int i = 0; *(str + i) != '\0'; i++) {
		if(*(str+i) == ' ') temp++;
	}

	return temp;
}
```   
modify function to not using `i` in loop...   
   
```
int count_space_onlyPTR(const char* str) {
	int temp=0;
	for (; *str != '\0'; str++) if(*str == ' ') temp++;
	return temp;
}
```   
   
whats the edge of doing this?    
1. mold the habit to hand over array parameters with const   
2. saves the memory

# String Functions

> `char* strcpy(char* str1,char* str2)`   
> `strncpy(str1,str2,sizeof(str1)-1)`   
   
> `size_t strlen(const str)`   
   
> `char* strcat(char* str1, const char* str2)`   
> `strncat(str1, str2, sizeof(str1 )- strlen(str1) -1 )`   
   
> `int strcmp(const char* str1, const char* str2)`   

   
```
char* strCpy(char* str1, const char* str2) {
	for (int i = 0; *(str1 + i) = *str2; i++, str2++);	// string copy ends when *str2 is NULL.

	return str1;
}
```   
   
```
int strCmp(const char* str1, const char* str2) {

	for (;; str1++, str2++) { 
		if (*str1 > * str2) return 1;
		else if (*str1 < *str2) return -1;
		else if (*str1 == NULL && *str2 == NULL) break;
	}

	return 0;
}
```

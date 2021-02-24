# Reverse Letters

By using `getchar()`, push the character one by one to STACK untill meets '\n'   
   
In order to print them as reverse, `pop()` untill `ptr <= &STACK[0]`   
   
The important thing is that   
   
**NEVER USE pointer as Operand with Integer if it points to non-integer type value**   
   
Cause, if `int* ptr` points to `char STACK[] = {,,}`, pushed element would be stored as gap of 3 (char = 1byte, int = 4byte)    
   
ex) `{'\0','\0','\0',65,'\0','\0','\0',72,'\0','\0','\0',93}`

# Indicate whether parentheses and/or braces are nested properly
$ ((){}{()})   
   
By using stack, `push` every single character that entered    
If entered character is `')' or '}' or ']'` compare it with element of current pointer of stack    


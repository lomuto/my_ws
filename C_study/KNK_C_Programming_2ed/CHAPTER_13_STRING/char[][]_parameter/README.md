# 2D char array as Parameter   
   
In order to passing parameter as 2D array, you must specify size of row   
   
for example, if you want to pass `char strs[][10]` as parameter   
   
prototype of function has to be `function(char strs[][10])` or `function(char (*str)[10])` so that ***compiler can understand the size of array***   
   
one more important thing...   
`char (*strs)[10]` and `char* strs[10]` are ***different***   
   
while bracket`[]()` has higher hierachy in arithmetic than asterisk`*`   
`char* strs[10]` is a pointer of 10th element of array   
`char (*strs)[10]` is a 2 dimensional array with 10 sized row

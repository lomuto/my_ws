# Print String with string format   
   
string format in printf function comes with `%m.p/*type*/`   
when length of format to print is bigger than `m`, it gets ignored and printed with full length   
but when it comes with `.s`, length of format get truncated as `s`   
   
while `char* str = "conjunct"`   
`printf("%3s",str)` would be `conjunct`   
`printf("%.3s",str)` would be `con`

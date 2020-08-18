# Variable-Length Array Parameters

By using ` /type/  /func_name/(int n, int arr[n])`     
we can specify `n` as length of paramter `arr`      

We can also `/type/ /func_name/(int n, int arr[*])`   
by same meaning   
   
If parameter `n` exceed the length of argument `arr`   
elements of exceeded index in `arr` get garbage value

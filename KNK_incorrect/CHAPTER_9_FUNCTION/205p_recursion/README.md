# Recursion

Turning a flow of recursional task in mathmatical situation into a code is a truely hard thing to do   
Just remember these simple step...   
1. When it comes with `x^n`, makes it clear as recursional expression: `x^n = x * x^(n-1)`   
2. R-value in expression will become a return statement: `return x * function(x,n-1)`
3. Clearify termination condition: `if(n == 1) return x;`   

In order to abbriviate function statement in single return statement...   
> return n == 1 ? x : x*function(x,n-1);  

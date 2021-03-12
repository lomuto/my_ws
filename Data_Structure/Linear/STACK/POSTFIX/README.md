# POSTFIX
   
**It took 8hours to finish :(**   
   
1. If its OPERAND, write on main string   
2. If its OPERATOR...   
> 2.1 If STACK is empty, push   
> 2.2 If STACK is not empty and exp is '(', push   
> 2.3 If STACK is not empty and exp is ')', pop untill top of STACK is '('   
> 2.4 IF STACK is not empty and exp is ARITHMETIC OPERATOR...   
> > 2.4.1 If OPERATOR in STACK has higher higherachy than exp, pop untill it meets higher higherachy OPERATOR or '(' or bottom of STACK   
> > 2.4.2 If OPERATOR in STACK has lower higherachy than exp, push   
   
> 2.5 If top of STACK is '(' just push

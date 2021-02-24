# RPN Calculator
Some calculators (notably those from Hewlett-Packard) use a system of writing mathematical expressions known as Reverse Polish Notation (RPN)   
The algorithm involves reading the operators and operands in an expression from left to right, performing the following actions:   
1. When an operand is encountered, push it onto the stack.   
2. When an operator is encountered, pop its operands from the stack, perform the operation on those operands and then push the result onto the stack.   
```
Enter an RPN expression: 1 2 3 * + =    
Value of expression: 7    
Enter an RPN expression: 5 8 * 4 9 - / =    
Value of expression: -8    
Enter an RPN expression: q    
```

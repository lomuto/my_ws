# Display digit number
Write a program that prompts the user for a number and then displays the number,
using characters to simulate the effect of a seven-segment display:

```
Enter a number: 491-9014
      _       _   _
|_|  |_|   | |_| | |   | |_|
  |   _|   |  _| |_|   |   |
```   
Implemented code by printing segement of number in sequence of each row    
for example when print `9`
```
top      _   
   
middle  |_|   
   
bottom   _|
```   
Using `goto()` function seems efficient, but didn't implemented here

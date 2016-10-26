# Problem

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

```
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
```
# Solution

Maintain a stack. Whenever we find a number, push it to the top of the stack. Otherwise, pop two elements from the stack top, and calculate the result accoring to the operand. The result is then pushed to the stack top.

# Running Time

- cpp version: 19 ms (001.cpp)

# Problem

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

# Solution

This problem is about the design of adder. When both a and b are not zero, we have the relation that:

```
sum = a ^ b
carry = (a & b) << 1
a + b = sum + carry
```

# Running Time

- cpp version: 0 ms (001.cpp)

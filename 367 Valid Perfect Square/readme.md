# Problem

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

```
Input: 16
Returns: True
```
Example 2:

```
Input: 14
Returns: False
```

# Solution

First take the [square root](../069%20Sqrt(x)), then take the square. Check if the result is the same as the original input.

# Running Time

- cpp version: 0 ms (001.cpp)

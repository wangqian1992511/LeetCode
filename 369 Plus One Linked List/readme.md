# Problem

Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:

```
Input:
1->2->3

Output:
1->2->4
```

# Solution

Find the least significant non-nine digit. Add one to this digit and clear the other less significant digits as zeros. Pay attention to the case when all the digits are initially nine.

# Running Time

- cpp version: 4 ms (001.cpp)

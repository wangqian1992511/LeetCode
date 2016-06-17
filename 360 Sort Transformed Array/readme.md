# Problem

Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:

```
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
```

# Solution

Find the asymptote if "a" is not equal to zero. Xor will be helpful to handle the two different cases when "a" is larger or smaller than zero. Horner's method is used to calculate the polynomial in an efficient way (though the improvement is not obvious in this problem).

# Running Time

- cpp version: 8 ms (001.cpp)

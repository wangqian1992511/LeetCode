# Problem

Implement pow(x, n).

# Solution

Naive fast exponential implementation. We generally use the following relation:

```
a^n = (a^{n/2})^2
```

Pay attention to the parity of n. The time complexity is O(log(n)). Notice that n may be negative. For convenience, int64_t type is used here.

# Running Time

- cpp version: 4 ms (001.cpp)

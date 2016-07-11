# Problem

Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

```
a = 2
b = [3]

Result: 8
```
Example2:

```
a = 2
b = [1,0]

Result: 1024
```
# Solution

The first step is to convert "a" into "a mod c".

Then use the recursive relation:

```
  a^{10^{p+1}x + 10^{p}y} 
= (a^{10^{p}x})^10 * a^{10^{p}y}
```

When calculating the exponential, do not forget to use the technique mentioned in the [previous problem](../050%20Pow(x%2Cn)).

# Running Time

- cpp version: 20 ms (001.cpp)

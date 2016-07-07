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

We should calculate the modular power digit by digit and multiply them together. Notice that any adjacent digits have the relation:

```
a^{k*10^{p+1}} = {a^{k*10^{p}}}^10
```

# Running Time

- cpp version: 28 ms (001.cpp)

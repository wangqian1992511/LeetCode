# Problem

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1], [-1,1]], return true.

Example 2:
Given points = [[1,1], [-1,-1]], return false.

# Solution

Establish a hash map from each y-axis to a set of x-axis. If two points (x<sub>1</sub>, y) and (x<sub>2</sub>, y) are reflective with respect to the line at x:

```
x_1 + x_2 = 2x
```

Moreover, the reflection point x should be the same for all possible y.

# Running Time

- cpp version: 76 ms (001.cpp)

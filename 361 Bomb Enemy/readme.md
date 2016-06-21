# Problem

Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:

```
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
```

# Solution

Two pointers are used to maintain the number of enemies between each pair of walls in each row/column. The time complexity is O(nm).

Of course, we can also design a DP solution by maintaining the cumulative number of enemies for each position from four different directions. But this implementation may cost more constant time.

# Running Time

- cpp version: 152 ms (001.cpp)

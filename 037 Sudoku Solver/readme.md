# Problem

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

![](001.png)
![](002.png)

# Solution

Use DFS to place valid number in the cells one by one. In this problem, bit manipulation is used to record the remaining valid numbers for each row/colum/grid. 

When we want to place a number in cell (i,j), we should first conduct the bitwise AND:

```
row[i] AND col[j] AND grid[area[i][j]]
```

The lowbit operation (x AND -x) can be used to directly obtain the lowest set bit of the result in the equation above. The can speed the process of linearly searching for the next valid candidate. The improvement will be obvious if we have to traverse the whole searching tree (such as finding the number of valid plans).

# Running Time

- cpp version: 8 ms (001.cpp)
# Problem

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

![](001.png)

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

# Solution

Simply use a boolean array to record whether a number has been assigned to a certain row, column or grid.

# Running Time

- cpp version: 12 ms (001.cpp)
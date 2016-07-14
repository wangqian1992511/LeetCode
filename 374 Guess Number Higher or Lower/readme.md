# Problem

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):


```
-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
```
 
Example:

```
n = 10, I pick 6.
Return 6.
```

# Solution

Use the binary search. The solution is generally the same as that in [Problem 278](../278%20First%20Bad%20Version).

# Running Time

- cpp version: 0 ms (001.cpp)

# Problem

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

```
2, [[1,0]]
```
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

```
2, [[1,0],[0,1]]
```
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

# Solution

Use a queue to maintain the nodes with a current zero degree. There is a valid solution when and only when the number of courses popped from this queue is the same as the total number of courses.

# Running Time

- cpp version: 20 ms (001.cpp)
- python version: 76 ms (001.py)

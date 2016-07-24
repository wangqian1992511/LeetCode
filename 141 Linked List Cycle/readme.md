# Problem

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

# Solution

Use two pointers. The slow one is chasing the fast one. If they meet at one node, there must be a cycle.

# Running Time

- cpp version: 12 ms (001.cpp)

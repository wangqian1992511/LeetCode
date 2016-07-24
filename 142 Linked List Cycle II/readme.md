# Problem

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

# Solution

Use the same method as in the [previous problem](../141%20Linked%20List%20Cycle) to detect the cycle. When there is a cycle we notice that:

```
dist[fast] = 2dist[slow]
dist[fast] = dist[listHead,cycleHead] + dist[cycleHead,meetPoint] + len[cycle]
dist[slow] = dist[listHead,cycleHead] + dist[cycleHead,meetPoint]
```

Thus, we can derive that:

```
dist[listHead,cycleHead] = len[cycle] - dist[cycleHead,meetPoint] = dist[meetPoint,cycleHead]
```

The remaining step is moving two pointers, starting separately from the meetPoint and the listHead, until they meet together.

# Running Time

- cpp version: 12 ms (001.cpp)

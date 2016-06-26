# Problem

Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

```
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
```
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

# Solution

Use two BST to maintain the two ending points of each interval. When a number x is added, we should check whether:

1. x has already be discussed
2. x-1 is a right ending of an interval
3. x+1 is a left ending of an interval

The time complexity is O(log(n)) for each element.

When we would like to get all the current intervals, we can construct the intervals with the two BST mentioned above. The time complexity is O(n). Thus, the average complexity is O(1) for each element.

The overall complexity is O(log(n)) for each element.

# Running Time

- cpp version: 168 ms (001.cpp)
